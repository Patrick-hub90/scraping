import requests
import copy
from lxml import html
from bs4 import BeautifulSoup
from time import sleep
from selenium import webdriver
class Alliexpress:

    def __init__(self):
        self.url = "https://fr.aliexpress.com/?afSmartRedirect=n&isPhone=false&src=google&albch=fbrnd&acnt=304-410-9721&albcp=2068664807&albag=79246744747&slnk=&trgt=aud-352110689665%3Akwd-14802285088&plac=&crea=525047064423&netw=g&device=c&mtctp=e&memo1=&albbt=Google_7_fbrnd&albagn=888888&isSmbActive=false&isSmbAutoCall=false&needSmbHouyi=false&gclid=Cj0KCQiA15yNBhDTARIsAGnwe0WUHQhsOjag1Ap0eRp31lA1D7rT6Cv7m5mg2Z61bCFMEZujToYSW94aAjxrEALw_wcB&aff_fcid=6a44b9dd9e3e42ccb48ccec63d3e47a9-1638359556731-02502-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=6a44b9dd9e3e42ccb48ccec63d3e47a9-1638359556731-02502-UneMJZVf&terminal_id=975efcaa28e549c39573ce55d1612281"
        self.categorie_line = {}
        self.c_url = ""
        self.categorie = []
        self.produit = {}
        self.driver = webdriver.Chrome()
    def getInfo(self):
        reponse = requests.get(self.url)
        soup = BeautifulSoup(reponse.content,'html.parser')
        categorie = copy.copy(self.getCategorie())
        self.categorie_line = categorie
        return {
                "categorie" : categorie
               }
    def getProduits(self):
        dicto = {}
        self.getInfo()
        self.categorie=[]
        for nom,lien in self.categorie_line.items():
            self.categorie.append(nom)
            self.driver.get("https:"+lien)
            self.driver.execute_script('window.scrollTo(0, document.body.scrollHeight);')
            page = self.driver.page_source
            soup = BeautifulSoup(page,'html.parser')
            liste = []
            self.produit[nom] = []
            for a in soup.find_all('a',class_='_3KNwG _2f4Ho'):
                liste.append(self.getCaracteristique(a))
                
            dicto[nom] = liste
        return dicto
    def getCaracteristique(self,tag):
        c_image = tag.find('img',class_='oOZ6t product-img')['src'] if tag.find('img',class_='oOZ6t product-img') != None else "https://www.salonlfc.com/wp-content/uploads/2018/01/image-not-found-scaled-1150x647.png"
        c_nom = tag.find('img',class_='oOZ6t product-img')['alt'] if tag.find('img',class_='oOZ6t product-img') != None else  tag.find('h1',class_='_3eC3x').text
        l_price = []
        for l in tag.find('div',class_='_13_ga _37W_B').find_all('span'):
            l_price.append(l.string)
        c_price = "".join(l_price)
        c_vendu = tag.find('span',class_='_2tU1w').text if tag.find('span',class_='_2tU1w') != None else "Pas de Vente"
        c_rating = tag.find('span',class_='ZwoRt').text if tag.find('span',class_='ZwoRt') != None else "Pas d'avis"
        c_priceEnvoi = tag.find('span',class_='_1XYdp').text if tag.find('span',class_='_1XYdp') != None else "Neant"
        return {
                "Nom" : c_nom,
                "Image" : c_image,
                "Price" :c_price,
                "Vendus" : c_vendu,
                "Etoiles" : c_rating,
                "PriceSending": c_priceEnvoi
               }
    def getCategorie(self):
        self.driver.get(self.url)
        sleep(1)
        self.driver.execute_script('window.scrollTo(0, document.body.scrollHeight);')
        sleep(2)
        tree = html.fromstring(self.driver.page_source)
        line = tree.xpath('//*[@id="home-firstscreen"]/div/div/div[2]/div/div/div[1]/a/@href')
        if(len(line)==0):
            line.append("//www.aliexpress.com/all-wholesale-products.html?spm=a2g0o.home.16005.1.1b4b7065TbEb3b")
        reponse = requests.get("https:"+line[0])
        soup = BeautifulSoup(reponse.content,'html.parser')
        dico = {}
        self.categorie = []
        for categorie in soup.find_all('div',class_='item util-clearfix'):
            nom = categorie.find('a').string
            self.categorie.append(nom)
            c_lien = categorie.find('a')['href']  
            dico[nom] = c_lien                            
        return dico 
    def save_info(self):
        dicto_2 = self.getProduits()
        with open('C:/Users/ghost/Documents/scrap/scrapping/produit/Info_Genrale.txt','w') as m_fichier:
            for cate in dicto_2.keys():
                m_fichier.write(cate.replace(" ","_").replace("é","e").replace("è","e").replace("ê","e")+"\n")  
                with open('C:/Users/ghost/Documents/scrap/scrapping/produit/{}.txt'.format(cate.replace(" ","_").replace("é","e").replace("è","e").replace("ê","e")),'w') as fichier:
                    for j in dicto_2[cate]:
                        fichier.write("Nom :"+j["Nom"])
                        fichier.write('\n')
                        fichier.write(j["Image"])
                        fichier.write('\n')
                        fichier.write("Price :"+j["Price"])
                        fichier.write('\n')
                        fichier.write("Vendus :"+j["Vendus"])
                        fichier.write('\n')
                        fichier.write("Etoiles :"+j["Etoiles"])
                        fichier.write("\n######################\n")
produit = Alliexpress()
print(produit.save_info())
