import requests
from bs4 import BeautifulSoup
from random import randint,choice




def get_random_quote():
    class Quote:
        def __init__(self,text,author):
            self.text=text
            self.author=author
    ran_num=randint(1,10)
    template=f"http://quotes.toscrape.com/page/{str(ran_num)}/"
    resp=requests.get(template)
    soup=BeautifulSoup(resp.content,"html.parser")
    main_body = soup.findAll("div", attrs={"class": "row"})
    
    quotes_container = main_body[1].findAll("div", attrs={"class": "col-md-8"})
    
    quotes=quotes_container[0].findAll("div",attrs={"class":"quote"})
    quote_object_list=[]
    for i in quotes:
        q_text=i.find("span",attrs={"class":"text"}).text
        q_author=i.find("small",attrs={"class":"author"}).text
        quote_object_list.append(Quote(q_text,q_author))

    
    #print(quotes_container)
    selected_quote=choice(quote_object_list)

    return selected_quote