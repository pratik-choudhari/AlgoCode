from googlesearch import search

print('Welcome! I am here to help you :)')
print('Please Enter your query here: ')
query=input()
for i in search(query, tld="co.in", num=10, stop=20, pause=2):
    print(i)