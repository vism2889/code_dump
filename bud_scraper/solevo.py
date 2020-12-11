# Author: Morgan Visnesky
# Date: 11/21/2019
# File: solevo.py
# Project: budScraper

# For accessing Solevo Wellness dispensaries

# TODO:
#   add other locations other than squirrel hill
#
#
from dependencies import *
browser = Browser('chrome',headless=True)

class solevo():
    def connect():
        page = "https://www.solevowellness.com/squirrel-hill-menu/"
        browser.visit(page)
        time.sleep(3)

    def dryLeaf():
        leaf_button = browser.find_by_xpath('/html/body/div/div[4]/div/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/ul/li[2]/a')[0]
        leaf_button.click()
        time.sleep(1)


        leafs =[]

        cprint('Solevo Wellness: Dry Leaf Options: ', 'red', 'on_white') # changes terminal color
        print('\n')

        Xpath= '//*[contains(@data-category,"Dry Leaf")]'

        search_bar = browser.find_by_xpath(Xpath)

        for search in search_bar:
            leafs.append(search)
        for leaf in leafs:
            leaf = leaf.text.encode('utf8')
            cprint(leaf.decode('utf-8'), 'white', 'on_green')
            print('\n')

    def vape():
        vape_button = browser.find_by_xpath('/html/body/div[1]/div[4]/div/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/ul/li[3]/a')[0]
        vape_button.click()
        time.sleep(1)
        vapes =[]

        cprint('Solevo Wellness: Vaporizer Options: ', 'red', 'on_white') # changes terminal color
        print('\n')

        Xpath= '//*[contains(@data-category,"Vapes")]'

        search_bar = browser.find_by_xpath(Xpath)

        for search in search_bar:
            vapes.append(search)
        for vape in vapes:
            vape = vape.text.encode('utf8')
            cprint(vape.decode('utf-8'), 'white', 'on_green')
            print('\n')

    def concentrate():
        concentrate_button = browser.find_by_xpath('/html/body/div[1]/div[4]/div/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/ul/li[5]/a')[0]
        concentrate_button.click()
        time.sleep(1)
        concentrates =[]

        cprint('Solevo Wellness: Concentrate Options: ', 'red', 'on_white') # changes terminal color
        print('\n')

        Xpath= '//*[contains(@data-category,"Concentrates")]'

        search_bar = browser.find_by_xpath(Xpath)

        for search in search_bar:
            concentrates.append(search)
        for concentrate in concentrates:
            concentrate = concentrate.text.encode('utf8')
            cprint(concentrate.decode('utf-8'), 'white', 'on_green')
            print('\n')

    def edible():
        edible_button = browser.find_by_xpath('//html/body/div[1]/div[4]/div/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/ul/li[4]/a')[0]
        edible_button.click()
        time.sleep(1)
        edibles =[]

        cprint('Solevo Wellness: Edible Options: ', 'red', 'on_white') # changes terminal color
        print('\n')

        Xpath= '//*[contains(@data-category,"Edibles")]'

        search_bar = browser.find_by_xpath(Xpath)

        for search in search_bar:
            edibles.append(search)
        for edible in edibles:
            edible = edible.text.encode('utf8')
            cprint(edible.decode('utf-8'), 'white', 'on_green')
            print('\n')

    def topical():
        topical_button = browser.find_by_xpath('/html/body/div[1]/div[4]/div/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/ul/li[6]/a')[0]
        topical_button.click()
        time.sleep(1)
        topicals =[]

        cprint('Solevo Wellness: Topical Options: ', 'red', 'on_white') # changes terminal color
        print('\n')

        Xpath= '//*[contains(@data-category,"Topicals")]'

        search_bar = browser.find_by_xpath(Xpath)

        for search in search_bar:
            topicals.append(search)
        for topical in topicals:
            topical = topical.text.encode('utf8')
            cprint(topical.decode('utf-8'), 'white', 'on_green')
            print('\n')

    def accessory():
        accessory_button = browser.find_by_xpath('/html/body/div[1]/div[4]/div/div/div/div[2]/div/div/div[1]/div[1]/div[1]/div/ul/li[7]/a')[0]
        accessory_button.click()
        time.sleep(1)
        accessories =[]

        cprint('Solevo Wellness: Accessory Options: ', 'red', 'on_white') # changes terminal color
        print('\n')

        Xpath= '//*[contains(@data-category,"Accessories")]'

        search_bar = browser.find_by_xpath(Xpath)

        for search in search_bar:
            accessories.append(search)
        for accessory in accessories:
            accessory = accessory.text.encode('utf8')
            cprint(accessory.decode('utf-8'), 'white', 'on_green')
            print('\n')
