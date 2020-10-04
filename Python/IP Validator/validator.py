import re

ipList = []

# Accept user input
n = int(input())
for i in range(n):
    ip = ipList.append(input())

# Iterate over IP addresses
for ip in ipList:
    # Check if any IP address matched the RegEx
    if (re.search(r'\b(?:\d{1,3}\.){3}\d{1,3}\b', ip)):
        print('true')
    else:
        print('false')
