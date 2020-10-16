"""Parse CodeChef's Problems.

Reads the Problem Code given by the user and saves
desired data into a text file.
I.e.: "python main.py CODE"
"""

from json.decoder import JSONDecodeError
from requests.models import Request
from bs4 import BeautifulSoup
import requests
import sys

__version__ = "1.0.0"
__author__ = "André Silva"


def main():
    """Save CodeChef's Problem."""
    problem_code = process_args(1)
    problem = CodeChefProblem(problem_code.upper())
    problem.save()
    print("Problem has been successfully scrapped.")


def process_args(index: int) -> str:
    """Process command line arguments.

    Args:
        index (int): The index of the desired argument.

    Returns:
        str: The value of the argument at the desired index.
    """
    if len(sys.argv) != index + 1:
        print("Error: Wrong number of arguments. " +
              f"Expected {index + 1}, got {len(sys.argv)}.")
        sys.exit(1)

    return sys.argv[index]


class CodeChefProblem():
    """CodeChef's Problem Scrapper."""

    url: str = "https://www.codechef.com/api/contests/PRACTICE/problems/{code}"
    name: str
    code: str
    description: str
    author: str
    date: str
    editorial: str
    time_limit: str
    source_limit: str
    tags: [str]
    languages: [str]

    def __init__(self, code: str):
        """Initialize the scrapper.

        Args:
            code (str): The Problem Code of the desired problem.
        """
        self.code = code

    def parse_problem(self):
        """Read the server response and get the desired data."""
        response: dict = self._get_response()
        self._check_response(response)
        self.name = response["problem_name"]
        self.description = self._process_description(response["body"])
        self.author = response["problem_author"]
        self.date = response["date_added"]
        self.editorial = response["editorial_url"]
        self.time_limit = response["max_timelimit"]
        self.source_limit = response["source_sizelimit"]
        self.tags = self._process_tags(response["tags"])
        self.languages = response["languages_supported"]

    def save(self):
        """Read Problem data and save it in a text file."""
        self.parse_problem()

        with open(f"{self.code}.txt", "w", encoding="utf-8") as file:
            file.write(f"{self.name}\n")
            file.write(f"Problem Code: {self.code}\n\n")
            file.write(self.description)
            file.write("\n------------ Notes ------------\n\n")
            file.write(f"Author: @{self.author}\n")
            file.write(f"Editorial: {self.editorial}\n")
            file.write(f"Tags: {self.tags}\n")
            file.write(f"Date Added: {self.date}\n")
            file.write(f"Time Limit: {self.time_limit}\n")
            file.write(f"Source Limit: {self.source_limit}\n")
            file.write(f"Languages: {self.languages}\n")

    def _get_response(self) -> dict:
        self.url = self.url.format(code=self.code)
        request: Request = requests.get(self.url)
        if request.status_code != 200:
            print("Network Error: There seems to be an issue accessing the server. " +
                  "Please try again.")
            sys.exit(1)
        try:
            return request.json()
        except JSONDecodeError:
            print("Unexpected error while decoding the data. Please try again.")
            sys.exit(1)

    def _check_response(self, request: dict):
        status: bool = False if request["status"] == "error" else True

        if not status:
            print(f"Problem with code \"{self.code}\" was not found. Please try again.")
            sys.exit(1)

    def _process_tags(self, tags: str) -> str:
        return BeautifulSoup(tags, "lxml").text

    def _process_description(self, description: str) -> str:
        unwanted_sentences: dict = {
            "start": {
                "startswith": "### Read problem",
                "endswith": "well."
            },
            "end": {
                "startswith": "<aside",
                "endswith": "</aside>"
            }
        }
        description = self._remove_start(description, unwanted_sentences["start"])
        description = self._remove_end(description, unwanted_sentences["end"])
        return BeautifulSoup(description, "lxml").text

    def _remove_start(self, text: str, unwanted_sentence: dict) -> str:
        if text.startswith(unwanted_sentence["startswith"]):
            new_start: str = unwanted_sentence["endswith"]
            text = text[text.find(new_start) + len(new_start):]
        return text

    def _remove_end(self, text: str, unwanted_sentence: dict) -> str:
        if text.endswith(unwanted_sentence["endswith"]):
            new_end: str = unwanted_sentence["startswith"]
            text = text[:text.find(new_end)]
        return text


if __name__ == "__main__":
    main()
