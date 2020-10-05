import re
import requests
from bs4 import BeautifulSoup

# Output file
f = open("output.txt","a",encoding="utf-8")

# Header while sending requests
USER_AGENT = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36"
headers = {"user-agent": USER_AGENT}

problemCode = input("Enter Problem Code: ")

# Letter Part of Problem Code
letterPart = re.findall("^[0-9]*(.+)",problemCode)

# Numerical Part of Problem Code
numericalPart = re.findall("^([0-9]+)[a-zA-Z]+",problemCode)

url = "https://codeforces.com/problemset/problem/"+numericalPart[0]+"/"+letterPart[0]

codePage = requests.get(url,headers=headers)
soup =  BeautifulSoup(codePage.text,"html.parser")

# Div containing everything related to problem
problemStatement = soup.find("div",attrs={"class":"problem-statement"})

# Problem header

header = problemStatement.find("div",attrs={"class":"header"})
title = header.find("div",attrs={"class":"title"})
timeLimit = header.find("div",attrs={"class":"time-limit"})
f.write("Problem Code: "+problemCode+"\n")
f.write("Problem Name: "+title.text+"\n")
f.write("Time Limit: "+timeLimit.div.next_sibling+"\n\n")

# Problem Statement

f.write("Problem Statement: "+"\n")

problemDesc = header.next_sibling
for i in problemDesc.find_all("p"):
    f.write(i.text+"\n")

f.write("\n")


# Input Specification
f.write("Input Specification: "+"\n")

inputSpecification = problemStatement.find("div",attrs={"class","input-specification"})
for i in inputSpecification.find_all("p"):
    f.write(i.text+"\n")

f.write("\n")

# Output Specification
f.write("Output Specification: "+"\n")

outputSpecification = problemStatement.find("div",attrs={"class","output-specification"})
for i in outputSpecification.find_all("p"):
    f.write(i.text+"\n")

f.write("\n")

# Sample Test cases

f.write("Sample Test cases: "+"\n\n")

# Input and Output for each test case

inputTestCase = problemStatement.find_all("div",attrs={"class","input"})
outputTestCase = problemStatement.find_all("div",attrs={"class","output"})

for i,j in zip(inputTestCase,outputTestCase):
    f.write("Input:"+"\n")
    f.write(i.pre.text+"\n")
    f.write("Output:"+"\n")
    f.write(j.pre.text+"\n\n")


f.write("\n")


# Note if there in Problem
note = problemStatement.find("div",attrs={"class","note"})

if note is not None:
    f.write("Note: "+"\n")
    for i in note.find_all("p"): 
        f.write(i.text+"\n")


f.close()