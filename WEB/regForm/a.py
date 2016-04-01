from bs4 import BeautifulSoup as bs
from lxml import html
from PIL import Image
import io
import urllib
import loadImage
import requests
import re
import mechanicalsoup


main = "http://kolesa.kz/a/new/?cat=auto.car"
br = mechanicalsoup.Browser()
capcha_page = br.get(main)
f = open("page", "w")
f.write(str(bs(capcha_page.content)))
capcha_form = capcha_page.soup.select("form")[1]


loadImage.imageURL("http://kolesa.kz" + capcha_form.select("img")[0].attrs['src'])
#img = ("http://kolesa.kz" + capcha_form.select("img")[0].attrs['src'])

capcha_form.select("input")[0]['value'] = input()
requestForm = br.submit(capcha_form, br)
print("+++++++++++++++++++++++++")
print(str(bs(requestForm.url)))





#page = requests.get(main)

#f = open("page", "w")
#f.write(str(bs(page.content, "lxml")))
#soup = bs(page.content, "lxml")
#print(requests.__dict__.keys())
#print(requests.post(main))
#for img in soup.find_all('img'):
#    im = "http://kolesa.kz"+img.attrs['src']
#    loadImage.imageURL(im)
#    break
