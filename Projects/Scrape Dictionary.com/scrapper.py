import json
import requests
from tqdm import tqdm
from bs4 import BeautifulSoup

# String For Storing the links of all the words
stri = ""

# Dictionary Holding the Final Output
all_words = {}

# Method for Scrapping the Word Name and Word Meaning
def extractMeaning(url):
    result = requests.get(url)
    soup = BeautifulSoup(result.text, "html.parser")
    pos = soup.find(attrs={"class": "css-1o58fj8 e1hk9ate4"})
    heading = soup.find("h1", attrs={"class": "css-1jzk4d9 e1rg2mtf8"}).text
    arr = []
    for i in pos.find_all(attrs={"class": "e1q3nk1v3"}):
        arr.append(i.text)

    all_words[heading] = arr


# Character Bar
character_bar = tqdm(range(97, 123), desc="Progress Bar: ", unit=" ticks")

for i in range(97, 123):
    # Updating Character Bar
    character_bar.update(1)
    result = requests.get("https://www.dictionary.com/list/" + chr(i))
    soup = BeautifulSoup(result.text, "html.parser")
    pages = soup.find("li", attrs={"class": "css-3w1ibo e1wvt9ur6"}).a

    # If only one page is there with that word

    if pages is None:
        # Page bar
        page_bar = tqdm(range(0, 1), desc="Collecting Page: ", unit=" ticks")
        container = soup.find("ul", attrs={"class": "css-1y59cbu e1j8zk4s0"})
        for j in range(0, 1):
            # Updating the Page Bar
            page_bar.update(1)
            words = container.find_all("li")

            # Word Bar
            word_bar = tqdm(
                range(1, len(words) + 1), desc="Collecting Words: ", unit=" ticks"
            )
            for k in words:
                # Updating the Word Bar
                word_bar.update(1)
                try:
                    extractMeaning(k.a["href"])
                    stri = stri + k.a["href"] + "\n"
                except:
                    pass

    else:
        pages = int(pages["data-page"])
        # Page Bar
        page_bar = tqdm(range(1, pages + 1), desc="Collecting Pages: ", unit=" ticks")
        for j in range(1, pages + 1):
            # Updating the Page Bar
            page_bar.update(1)
            page = requests.get(
                "https://www.dictionary.com/list/" + chr(i) + "/" + str(j)
            )
            soup = BeautifulSoup(page.text, "html.parser")
            container = soup.find("ul", attrs={"class": "css-1y59cbu e1j8zk4s0"})
            words = container.find_all("li")
            # Word Bar
            word_bar = tqdm(
                range(1, len(words) + 1), desc="Collecting Words: ", unit=" ticks"
            )
            for k in words:
                # Updating the Word Bar
                word_bar.update(1)
                try:
                    extractMeaning(k.a["href"])
                    stri = stri + k.a["href"] + "\n"
                except:
                    pass


# File for writing links of all the words
f = open("links.text", "w")
f.write(stri)
f.close()

# Output JSON File
with open("dictionary.json", "w", encoding="utf8") as s:
    json.dump(all_words, s, indent=4, ensure_ascii=False)

