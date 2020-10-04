import re

ipList = []
n = int(input())
for i in range(n):
    ip = ipList.append(input())

for ip in ipList:
    if (re.search(r'\b(?:\d{1,3}\.){3}\d{1,3}\b', ip)):
        print('true')
    else:
        print('false')
