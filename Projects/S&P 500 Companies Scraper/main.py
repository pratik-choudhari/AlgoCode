""" Python Script to scrape details of S&P 500 Companies """

from bs4 import  BeautifulSoup, NavigableString, Tag
import requests
import pandas as pd

URL = 'https://en.wikipedia.org/wiki/List_of_S%26P_500_companies'

# Get the page
page = requests.get(URL)
soup = BeautifulSoup(page.content, 'html.parser')

header_list = []
header = soup.findAll('table', {'id': 'constituents'})[0].find('tr')

# Make a list of headers
for item in header:
    try:
        # Strip off unwanted chars
        item = item.get_text().strip()
        header_list.append(item)
    except:
        continue

HTML_data = soup.findAll('table', {'id': 'constituents'})[0].findAll('tr')[1:]
data = []

# Make a list of all the rows
for element in HTML_data:
    sub_data = []
    for sub_element in element:
        if isinstance(sub_element, NavigableString):
            continue
        if isinstance(sub_element, Tag):
            sub_element = sub_element.get_text().strip()
            sub_data.append(sub_element)
    data.append(sub_data)

# Create a DataFrame and convert it into .csv file
df = pd.DataFrame(data=data, columns=header_list)
df.to_csv('S&P 500 List.csv')
print('--------- Task Successfully Completed -----------')
