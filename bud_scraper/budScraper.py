# Author: Morgan Visnesky
# Date: 11/21/2019
# File: budScraper.py
# Project: budScraper

# INFO: Scrapes webpages of medical marijauna dispensaries in pennsylvania


# TODO:
#
#   - Use splinter click() feature to navigate menu instead of spawning to different web addresses
#   - Username and pw field selects to login // automate actual ordering
#   - set frequency of scrape function
#   - function to alert / contact person if dry leaf is available
#   - check if dispensaries are on leafly / if leafly has an api / or how to parse leafly

from CY import *
from solevo import *

def main():
    #solevo.connect()
    #solevo.vape()
    #solevo.dryLeaf()
    #solevo.concentrate()
    #solevo.edible()
    #solevo.topical()
    #solevo.accessory()
    CY.connect()
    CY.dryLeaf2()
    CY.vape()
    #CY.concentrate()
    #CY.tincture()
    #CY.capsule()
    browser.quit()

if __name__ == '__main__':
    main()
