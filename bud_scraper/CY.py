# Author: Morgan Visnesky
# Date: 11/21/2019
# File: CY.py
# Project: budScraper

# For accessing CY+ dispensaries

# TODO:
#   Add rest of catergories
#
#
from dependencies import *
browser = Browser('chrome', headless=True)

#browser = Browser('chrome')

class CY:
    def connect():
        page = "https://shop.cydispensary.com/products"
        browser.visit(page)
        time.sleep(3)

        search_button = browser.find_by_xpath('/html/body/div[3]/div[3]/div/div/div/button[1]')[0]
        search_button.click()
        time.sleep(1)

    def menu_location_select(locationMenu):
        menuButton = browser.find_by_xpath('//*[@id="menu-item-287"]')
        menuButton.click()
        if locationMenu == 'butler':
            butlerMenu = browser.find_by_xpath('//*[@id="menu-item-95"]/a')
            butletMenu.click()
        if locationMenu == 'new kensington':
            newKensingtonMenu = browser.find_by_xpath('//*[@id="menu-item-295"]/a')
            newKensingtonMenu.click()
        if locationMenu == 'pittsburgh':
            pittsburghMenu = browser.find_by_xpath('//*[@id="menu-item-94"]/a')
            pittsburghMenu.click()

    def productSelect():

        print('What product are you looking for?' + '\n')
        print('Dry leaf, Vaporizors, Concentrates, Tinctures, capsules, or topicals?' + '\n')
        product = raw_input()
        if product == 'dry leaf':
            dryLeaf()
        if product == 'vaporizors':
            vape()
        if product == 'concentrates':
            concentrate()
        if product == 'tinctures':
            tincture()
        if product == 'capsules':
            capsule()
        if product == 'topicals':
            topical()

    def concentrate():
        concentrates =[]
        cprint('CY+: Concentrate Options: ', 'red', 'on_white')
        print('\n')

    def tincture():
        tinctures =[]
        cprint('CY+: Tincture Options: ', 'red', 'on_white')
        print('\n')

    def capsule():
        capsules =[]
        cprint('CY+: Capsule Options: ', 'red', 'on_white')
        print('\n')

    def topical():
        topicals =[]
        cprint('CY+: Topical Options: ', 'red', 'on_white')
        print('\n')

    def dryLeaf():
        page = "https://shop.cydispensary.com/products/flower"
        browser.visit(page)
        time.sleep(1)
        pattern = re.compile('//*[@id="root"]/div/div/div/div/main/div/div/div[2]/div/div[2]/div[3]/div/div/div*', re.IGNORECASE)
        #search_button = browser.find_by_xpath('/html/body/div[3]/div[3]/div/div/div/button[1]')[0]
        #search_button.click()
        #time.sleep(2)
        #search_bar_xpath = '//*[@id="root"]/div/div/div/div/main/div/div/div[2]/div/div[2]/div[3]/div/div/div'+'['+str(i)+']'

        for i in range(1,10):
            search_bar_xpath = '//*[@id="root"]/div/div/div/div/main/div/div/div[2]/div/div[2]/div[3]/div/div/div'+'['+str(i)+']'
            try:
                search_bar = browser.find_by_xpath(search_bar_xpath)[0]
            except IndexError:
                continue
            print(search_bar.text.encode('utf8'))

    def dryLeaf2():
        page = "https://shop.cydispensary.com/products/flower"
        browser.visit(page)
        time.sleep(1)
        #pattern = re.compile('//*[@id="root"]/div/div/div/div/main/div/div/div[2]/div/div[2]/div[3]/div/div/div*', re.IGNORECASE)
        #search_button = browser.find_by_xpath('/html/body/div[3]/div[3]/div/div/div/button[1]')[0]
        #search_button.click()
        #time.sleep(2)
        Xpath= '//*[contains(@id,"root")]'
        #search_bar_xpath = '//*[@id="root"]/div/div/div/div/main/div/div/div[2]/div/div[2]/div[3]/div/div/div'+'['+str(i)+']'
        search_bar = browser.find_by_xpath(Xpath)
        buds = []
        for i in search_bar:
            buds.append(i)
            print(i.text.encode('utf8'))
            print('\n\n')
            print(len(buds))

    def vape():
        page = "https://shop.cydispensary.com/products/vapes"
        browser.visit(page)
        time.sleep(1)

        vapes =[]

        cprint('CY+: Vaporizer Options: ', 'red', 'on_white') # changes terminal color
        print('\n')
        for i in range(1,10):

            search_bar_xpath = '//*[@id="root"]/div/div/div/div/main/div/div/div[2]/div/div[2]/div[3]/div/div/div'+'['+str(i)+']'
            search_bar = browser.find_by_xpath(search_bar_xpath)[0]


            vapes.append(search_bar)
        for vape in vapes:
            vape = vape.text.encode('utf8')
            cprint(vape.decode('utf-8'), 'white', 'on_green')
            print('\n')
