from django.shortcuts import render
from django.http import HttpResponse
import quotes.scrape_quotes as sq
# Create your views here.


def index(request):
    quote=sq.get_random_quote()
    return render(request,"quotes/index.html",{"quote":quote})