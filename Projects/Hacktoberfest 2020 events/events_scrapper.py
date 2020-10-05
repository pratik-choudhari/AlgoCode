import csv
import requests
from bs4 import BeautifulSoup

# Method for filtering the contents of "event" variable as "charmap" repeatedly fails to encode some characters
def filter_output(s):
    event = ""
    for i in s:
        if ord(i)>=32 and ord(i)<=126:
            event = event + str(i)
    return event

# Method for searching and storing all hacktoberfest 2020 events in "events.csv" file
def search_events():

    url = "https://hacktoberfest.digitalocean.com/events"

    # Requesting and storing the contents of hacktober events webpage in "soup" variable
    result = requests.get(url)
    soup = BeautifulSoup(result.text, "html.parser")

    # Finding all the contents stored in the table format
    find_contents = soup.find(attrs={"class": "table"})
    if find_contents is None:
        print("\nNo events!")

    else:
        # Finding all the rows except the table-heading
        rows = find_contents.find_all("tr")[1:]

        # Creating a csv file and storing the movie information in it
        # If a file already exists the program overwrites its contents

        with open("events.csv", "w") as csv_file:
            writer = csv.writer(csv_file)

            # Initializing the first row with the column title
            writer.writerow(["Oraganiser's Location", "Event", "Date", "Time Zone", "RSVP"])

            # Iterating all the rows of the scrapped contents and storing them in desired csv file
            for row in rows:

                # Storing the different informations in different variables
                location = row.find(attrs={"data-label": "location"}).text
                event = filter_output(row.find(attrs={"data-label": "event"}).text)
                date = row.find(attrs={"data-label": "date"}).text
                time_zone = row.find(attrs={"data-label": "zone"}).text
                rsvp = row.find(attrs={"data-label": "event"}).a['href']

                # Appending the data back to the csv file
                writer.writerow([location, event, date, time_zone, rsvp])


# Calling the function/method to scrape and store all hacktoberfest 2020 events
# After scraping all the information is stored in events.csv file
search_events()