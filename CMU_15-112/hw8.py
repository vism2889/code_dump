#################################################
# hw8.py
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
#
# Names and andrew id's of up to 3 collaborators:
#   name + andrew id #1:
#   name + andrew id #2:
#   name + andrew id #3:
#################################################

import cs112_s20_unit8_linter
import math, copy

#################################################
# Helper functions
#################################################

def almostEqual(d1, d2, epsilon=10**-7):
    # note: use math.isclose() outside 15-112 with Python version 3.5 or later
    return (abs(d2 - d1) < epsilon)

import decimal
def roundHalfUp(d):
    # Round to nearest with ties going away from zero.
    rounding = decimal.ROUND_HALF_UP
    # See other rounding options here:
    # https://docs.python.org/3/library/decimal.html#rounding-modes
    return int(decimal.Decimal(d).to_integral_value(rounding=rounding))

# from: https://www.cs.cmu.edu/~112/notes/notes-strings.html#basicFileIO
def readFile(path):
    with open(path, "rt") as f:
        return f.read()

#################################################
# Functions for you to write
#################################################

def movieAwards(oscarResults):
    # takes tuples of movie titles, and awards won by that movie, returns 
    # dictionary with movie title as key and number of awards won as value
    movieResultDict = dict()
    for result in oscarResults:
        if result[1] in movieResultDict:
            movieResultDict[result[1]] += 1
        else:
            movieResultDict[result[1]] = 1
    return(movieResultDict)

def friendsOfFriends(friends):
    # takes a dictionary of sets of friends, returns a dictionary of friends
    # of friends
    fof = dict()
    for friend in friends:
        fof[friend] = set()
        for friendsOf in friends[friend]:
            for friendsOff in friends[friendsOf]:
                if friendsOff != friend and \
                    friendsOff not in friends[friend]:
                    fof[friend].add(friendsOff)
    return(fof)

def invertDictionary(d):
    # takes a dictionary's values and turns them into keys in a new dictionary
    # with the new values being sets containing old keys corresponding to the 
    # old values
    inverted = dict()
    for item in d:
        if d[item] not in inverted:
            inverted[d[item]] = set()
        inverted[d[item]].add(item)
    return(inverted)

def readDogDataCsvFileInto2dList(year):
    # takes data from a csv fiel and stores it in a 2D list
    year = str(year)
    yearFile = readFile('dog-licenses-' + year + '.csv')
    list2D = []
    for line in yearFile.split('\n'):
        if line != '':
            lineList = []
            for item in line.split(','):
                lineList.append(item)
            list2D.append(lineList)
    return list2D

def convert2dListToTable(data):
    # converts 2D list into a list of dictionaries 
    table = []
    for i in range(len(data)):
        tableEntry = dict()
        for j in range(len(data[0])):
            tableEntry[data[0][j]] = data[i][j]
        table.append(tableEntry)
    return(table)

def cleanData(table):
    #for brevity: formats data to align with specifications in problem details
    for item in table:
        for i in item:
            item[i] = item[i].title()
            newString = ''
            for c in item[i]:
                if c.isalnum() or c.isspace() or c == '/':
                    newString += c
            item[i] = newString
            if i == 'LicenseType':
                item[i] = item[i].split(' ')[-1]
                if item[i] == 'Free':
                    item[i] = 'Unknown'
            cols = []
            if i == 'Color':
                for col in item[i].split('/'):
                    cols.append(col.lower())
                item[i] = cols
            if i == 'ExpYear' or i == 'Expyear':
                if item[i].isdigit():
                    item[i] = int(item[i])
            if i == 'ValidDate':
                item[i] = item[i][:4]
                if item[i].isdigit():
                    item[i] = int(item[i])

def getCleanedTable(year):
    # combines the above functions to load data into a table, clean it, 
    # and then return the cleaned table
    list2D = readDogDataCsvFileInto2dList(year)
    table = convert2dListToTable(list2D)
    cleanData(table)
    return table

def getLabelValues(row, label):
    # not used
    return 42

def getValueSets(year):
    # maps each column title to a set of all its possible unique values
    table = getCleanedTable(year)
    valueSets = dict()
    for val in table[0]:
        valueSets[val] = set()
    for val in valueSets:
        for row in table[1:]:
            for item in row:
                if item == 'Color':
                    for color in row[item]:
                        valueSets['Color'].add(color)
                else:
                    valueSets[item].add(row[item])
    return valueSets

def getValueCounts(year):
    # gets a count of the number of occurances of a given unique value in a 
    # correpsonding to a given column title
    table = getCleanedTable(year)
    countDict = dict()
    for title in table[0]:
        countDict[title] = dict()
    for row in table[1:]:
        for entry in row:
            if isinstance(row[entry],list):
                for item in row[entry]:
                    if item in countDict[entry]:
                        countDict[entry][item] += 1
                    else:
                        countDict[entry][item] = 1
            else:
                if row[entry] in countDict[entry]:
                    countDict[entry][row[entry]] += 1
                else:
                    countDict[entry][row[entry]] = 1
    return(countDict)

def getMaxValue(valueCounts):
    # this function is not used
    maxCounts = ''
    for entry in valueCounts:
        maxCounts = max(valueCounts[title])
    #print(maxCounts)

def getMostPopularValues(year):
    # gets most frequently occuring value, or values in a set if more than 
    # one most popular value exists
    table = getValueCounts(year)
    popularValues = dict()
    for entry in table:
        popularValues[entry] = ''
        maxE = -1
        maxETitle = ''
        for item in table[entry]:
            if table[entry][item] > maxE:
                maxE = table[entry][item]
                maxETitle = item
            elif table[entry][item] == maxE:
                if not isinstance(maxETitle, set):
                    t = maxETitle
                    maxETitle = set() 
                    maxETitle.add(t)
                    maxETitle.add(item)
                elif isinstance(maxETitle, set):
                    maxETitle.add(item)
        popularValues[entry] = maxETitle
    return(popularValues)

def someMoreDataAnalysis():
    # code to find answers is below and pretty much just makes call
    # to functions that were written as previous parts of the assignment
    print(getMostPopularValues('2018'))
    return '''
Q1: What is the most popular zip code in the full 2018 data?
A1: 15108

Q2: What is the most popular dog name in the full 2018 data?
A2: Bella

Q3: What is the second-most-popular dog name in the full 2018 data?
A3: 42

Q4: What is the third-most-popular dog name in the full 2018 data?
A4: 42
'''

#################################################
# Test Functions
#################################################

def testMovieAwards():
    print('Testing movieAwards()...', end='')
    tests = [
      (({ ("Best Picture", "The Shape of Water"), 
          ("Best Actor", "Darkest Hour"),
          ("Best Actress", "Three Billboards Outside Ebbing, Missouri"),
          ("Best Director", "The Shape of Water") },),
        { "Darkest Hour" : 1,
          "Three Billboards Outside Ebbing, Missouri" : 1,
          "The Shape of Water" : 2 }),
      (({ ("Best Picture", "Moonlight"),
          ("Best Director", "La La Land"),
          ("Best Actor", "Manchester by the Sea"),
          ("Best Actress", "La La Land") },),
        { "Moonlight" : 1,
          "La La Land" : 2,
          "Manchester by the Sea" : 1 }),
      (({ ("Best Picture", "12 Years a Slave"),
          ("Best Director", "Gravity"),
          ("Best Actor", "Dallas Buyers Club"),
          ("Best Actress", "Blue Jasmine") },),
        { "12 Years a Slave" : 1,
          "Gravity" : 1,
          "Dallas Buyers Club" : 1,
          "Blue Jasmine" : 1 }),
      (({ ("Best Picture", "The King's Speech"),
          ("Best Director", "The King's Speech"),
          ("Best Actor", "The King's Speech") },),
        { "The King's Speech" : 3}),
      (({ ("Best Picture", "Spotlight"), ("Best Director", "The Revenant"),
          ("Best Actor", "The Revenant"), ("Best Actress", "Room"),
          ("Best Supporting Actor", "Bridge of Spies"),
          ("Best Supporting Actress", "The Danish Girl"),
          ("Best Original Screenplay", "Spotlight"),
          ("Best Adapted Screenplay", "The Big Short"),
          ("Best Production Design", "Mad Max: Fury Road"),
          ("Best Cinematography", "The Revenant") },),
        { "Spotlight" : 2,
          "The Revenant" : 3,
          "Room" : 1,
          "Bridge of Spies" : 1,
          "The Danish Girl" : 1,
          "The Big Short" : 1,
          "Mad Max: Fury Road" : 1 }),
       ((set(),), { }),
            ]
    for args,result in tests:
        if (movieAwards(*args) != result):
            print('movieAwards failed:')
            print(args)
            print(result)
            assert(False)
    print('Passed!')

def testFriendsOfFriends():
    print("Testing friendsOfFriends()...", end="")
    d = dict()
    d["fred"] = set(["wilma", "betty", "barney", "bam-bam"])
    d["wilma"] = set(["fred", "betty", "dino"])
    d["betty"] = d["barney"] = d["bam-bam"] = d["dino"] = set()
    fof = friendsOfFriends(d)
    assert(fof["fred"] == set(["dino"]))
    assert(fof["wilma"] == set(["barney", "bam-bam"]))
    result = { "fred":set(["dino"]),
               "wilma":set(["barney", "bam-bam"]),
               "betty":set(),
               "barney":set(),
               "dino":set(),
               "bam-bam":set()
             }
    assert(fof == result)
    d = dict()
    #                A    B    C    D     E     F
    d["A"]  = set([      "B",      "D",        "F" ])
    d["B"]  = set([ "A",      "C", "D",  "E",      ])
    d["C"]  = set([                                ])
    d["D"]  = set([      "B",            "E",  "F" ])
    d["E"]  = set([           "C", "D"             ])
    d["F"]  = set([                "D"             ])
    fof = friendsOfFriends(d)
    assert(fof["A"] == set(["C", "E"]))
    assert(fof["B"] == set(["F"]))
    assert(fof["C"] == set([]))
    assert(fof["D"] == set(["A", "C"]))
    assert(fof["E"] == set(["B", "F"]))
    assert(fof["F"] == set(["B", "E"]))
    result = { "A":set(["C", "E"]),
               "B":set(["F"]),
               "C":set([]),
               "D":set(["A", "C"]),
               "E":set(["B", "F"]),
               "F":set(["B", "E"])
              }
    assert(fof == result)
    print("Passed!")


def testInvertDictionary():
    print("Testing invertDictionary()...", end="")
    assert(invertDictionary({1:2, 2:3, 3:4, 5:3}) == 
           {2:{1}, 3:{2,5}, 4:{3}})
    print("Passed!")

def testReadDogDataCsvFileInto2dList():
    print('Testing readDogDataCsvFileInto2dList()...', end='')
    data = readDogDataCsvFileInto2dList('2018-abridged')
    assert(data[0] == ['LicenseType','Breed','Color','DogName','OwnerZip',
                       'ExpYear','ValidDate'])
    #print('data: ', len(data))
    assert(len(data) == 101)
    assert(data[-1] == ['Dog Senior Citizen or Disability Neutered Male',
                        'YORKSHIRE TERRIER', 'BLACK/BROWN', 'JACK', '15238',
                        '2018', '2017-11-29T09:47:37'])
    print('Passed!')

def testConvert2dListToTable():
    print('Testing convert2dListToTable()...', end='')
    data = readDogDataCsvFileInto2dList('2018-abridged')
    table = convert2dListToTable(data)
    assert(len(data) == len(table))
    assert(data[18] == ['Dog Individual Spayed Female', 'COCKER SPANIEL', 
                        'BLONDE', 'JUILET', '15214', '2018', 
                        '2017-11-27T10:42:11'])
    assert(table[18] == {'LicenseType': 'Dog Individual Spayed Female',
                         'Breed': 'COCKER SPANIEL',
                         'Color': 'BLONDE',
                         'DogName': 'JUILET', 
                         'OwnerZip': '15214', 
                         'ExpYear': '2018', 
                         'ValidDate': '2017-11-27T10:42:11'
                        })
    print('Passed!')

def testCleanData():
    print('Testing cleanData()...', end='')
    data = readDogDataCsvFileInto2dList('2018-abridged')
    table = convert2dListToTable(data)
    cleanData(table) # note this works destructively!
    assert(table[18] == {'LicenseType': 'Female',
                         'Breed': 'Cocker Spaniel',
                         'Color': ['blonde'],
                         'DogName': 'Juilet', 
                         'OwnerZip': '15214', 
                         'ExpYear': 2018, 
                         'ValidDate': 2017
                        })
    # Note that the raw data for row 2 has the Color BLACK/BROWN
    assert(table[2]['Color'] == ['black', 'brown'])
    # Note that the raw data for row 26 has the DogName "CHRISTINA ""TINA"""
    assert(table[26]['DogName'] == 'Christina Tina')
    print('Passed!')

def testGetCleanedTable():
    print('Testing getCleanedTable()...', end='')
    table = getCleanedTable('2018-abridged')
    assert(len(table) == 101)
    assert(table[18] == {'LicenseType': 'Female',
                         'Breed': 'Cocker Spaniel',
                         'Color': ['blonde'],
                         'DogName': 'Juilet', 
                         'OwnerZip': '15214', 
                         'ExpYear': 2018, 
                         'ValidDate': 2017
                        })
    print('Passed!')

def testGetValueSets():
    print('Testing getValueSets()...', end='')
    valueSets = getValueSets('2018-abridged')
    assert(valueSets == {
        'LicenseType': {
            'Unknown', 'Female', 'Male'
            },
        'Breed': {
            'Cockapoo', 'Bichon Frise', 'Boxer Mix', 'Poodle Mix',
            'Am Pitt Bull Mix', 'Brittany Spaniel', 'Beagle', 'Shepherd Mix',
            'Maltese Mix', 'Terrier Mix', 'Morkie', 'Aus Shepherd', 'Tag',
            'Am Pit Bull Terrier', 'Mixed', 'Tree Walk Coonhound',
            'Great Dane', 'Golden Retriever', 'Beagle Mix', 'Shih Tzu',
            'Akita', 'Ger Shepherd', 'Cane Corso', 'Weimaraner',
            'Goldendoodle', 'Poodle Standard', 'Belg Malinois',
            'Ger Shepherd Mix', 'Sib Husky', 'Estrela Mtn Dog', 'Chihuahua',
            'Maltese', 'Doberman Pinscher', 'Rat Terrier',
            'Labrador Retriever', 'Min Pinscher', 'Doberman Mix',
            'Yorkshire Terrier', 'Greyhound', 'Dachshund Mix', 'Keeshond',
            'Shetland Sheepdog', 'Lab Mix', 'Scottish Terrier',
            'Cocker Spaniel', 'Portugese Water Dog', 'Lhasa Apso Mix',
            'Yorkshire Terr Mix', 'Havanese'
            },
        'Color': {
            'grey', '', 'yellow', 'tan', 'brown', 'buff', 'red', 'cream',
            'gold', 'orange', 'brindle', 'blonde', 'spotted', 'multi',
            'black', 'white'},
        'DogName': {
            'Rosie ', 'Tucker', 'Rusty', 'Isis', 'Juilet', 'Gus', 'Romeo',
            'Doggie', 'Taffy', 'Karma', 'Bumble', 'Sable', 'Jessie', 'Lola',
            'Luna', 'Happy', 'Jake', 'Neena', 'Baloo', 'Buddy', 'Maeby Axford',
            'Eich', 'Honey Puck', 'Toby', 'Stella', 'Abe', 'Valkyrie', 'Carly',
            'Chickie', 'Aslan Mcgregor', 'Princess', 'Duke',
            'Rufus Gerald Wallace', 'Emily', 'Nahbi', 'Norman Mitchell',
            'Cissie Bear', 'Hunter', 'Molly Magee', 'Bailey', 'Howie',
            'Zoe Vitsas', 'Bruno', 'Dakota', 'Charley', 'Sisco', 'Molly',
            'Zeta', 'Jack', 'Shadoe', 'Annie', 'Charlie', 'Willie', 'Cobalt',
            'Bear', 'Roxy', 'Saint', 'Lilly', 'Oakley', 'Clover', 'Joe',
            'Christina Tina', 'Chloe', 'Murphy', 'Cooper', 'Tacoda',
            'Mimi Pearl Foster', 'Ellie', 'Tonks', 'Rosie', 'Teddy', 'King',
            'Leroi', 'Dude', 'Arrow', 'Titan', 'Luce', 'Bandit', 'Bojangles',
            'Baley', 'Missy', 'Jackson', 'Sydney', 'Maggie', 'Curious George',
            'Snowball', 'Winnie', 'Madeleine', 'Izzy'
            },
        'OwnerZip': {
            '15120', '15221', '15126', '15131', '15068', '15133', '15218',
            '15129', '15136', '15209', '15147', '15057', '15104', '15108',
            '15227', '15116', '15237', '15018', '15137', '15101', '15236',
            '15017', '15205', '15202', '15148', '15102', '15090', '15234',
            '15220', '15146', '15139', '15228', '15044', '15239', '15042',
            '15135', '15238', '15025', '15214', '15045', '15122', '15106',
            '15241', '15235', '15229'
            },
        'ExpYear': {
            2018
            },
        'ValidDate': {
            2017
            }
        })
    print('Passed!')

def testGetValueCounts():
    print('Testing getValueCounts()...', end='')
    valueCounts = getValueCounts('2018-abridged')
    assert(valueCounts == {
        'LicenseType': {
            'Male': 47, 'Female': 52, 'Unknown': 1
            },
        'Breed': {
            'Cockapoo': 2, 'Ger Shepherd': 4, 'Belg Malinois': 1, 'Mixed': 9, 
            'Am Pit Bull Terrier': 1, 'Scottish Terrier': 1, 
            'Yorkshire Terrier': 4, 'Dachshund Mix': 2, 'Shetland Sheepdog': 2,
            'Labrador Retriever': 5, 'Bichon Frise': 2, 'Lhasa Apso Mix': 1,
            'Am Pitt Bull Mix': 4, 'Brittany Spaniel': 2, 'Terrier Mix': 4,
            'Cocker Spaniel': 3, 'Maltese': 5, 'Lab Mix': 5, 'Havanese': 1,
            'Akita': 1, 'Beagle Mix': 2, 'Doberman Mix': 1, 'Shih Tzu': 2,
            'Ger Shepherd Mix': 1, 'Doberman Pinscher': 1, 'Greyhound': 1,
            'Chihuahua': 1, 'Beagle': 3, 'Morkie': 1, 'Aus Shepherd': 1,
            'Poodle Standard': 1, 'Tree Walk Coonhound': 1, 'Great Dane': 1,
            'Estrela Mtn Dog': 1, 'Boxer Mix': 1, 'Portugese Water Dog': 1,
            'Golden Retriever': 6, 'Maltese Mix': 1, 'Weimaraner': 1,
            'Shepherd Mix': 1, 'Cane Corso': 1, 'Sib Husky': 2,
            'Poodle Mix': 1, 'Rat Terrier': 1, 'Keeshond': 1,
            'Yorkshire Terr Mix': 1, 'Min Pinscher': 1, 'Goldendoodle': 1,
            'Tag': 3
            },
        'Color': {
            'brown': 40, 'black': 42, 'brindle': 3, 'white': 36, 'tan': 7,
            'yellow': 1, 'spotted': 3, 'blonde': 3, 'multi': 3, 'orange': 1, 
            'cream': 2, 'red': 1, 'grey': 3, '': 1, 'gold': 3, 'buff': 1
            },
        'DogName': {
            'Charley': 1, 'Tacoda': 1, 'Eich': 1, 'Arrow': 1, 'Oakley': 1,
            'Bailey': 1, 'Mimi Pearl Foster': 1, 'Leroi': 1, 'Zoe Vitsas': 1,
            'Taffy': 1, 'Dude': 1, 'Chickie': 1, 'King': 1, 'Emily': 1,
            'Ellie': 3, 'Rusty': 1, 'Annie': 1, 'Juilet': 1, 'Romeo': 1,
            'Lola': 3, 'Abe': 1, 'Maggie': 2, 'Buddy': 1, 'Princess': 1,
            'Christina Tina': 1, 'Howie': 1, 'Happy': 1, 'Lilly': 1,
            'Shadoe': 1, 'Sable': 1, 'Nahbi': 1, 'Valkyrie': 1, 'Doggie': 1,
            'Curious George': 1, 'Willie': 1, 'Snowball': 2, 'Honey Puck': 1,
            'Roxy': 1, 'Bumble': 1, 'Bojangles': 1, 'Stella': 1,
            'Norman Mitchell': 1, 'Winnie': 1, 'Molly Magee': 1,
            'Madeleine': 1, 'Bandit': 1, 'Karma': 1, 'Dakota': 1,
            'Clover': 1, 'Titan': 1, 'Luna': 1, 'Maeby Axford': 2,
            'Saint': 1, 'Luce': 1, 'Baloo': 1, 'Rufus Gerald Wallace': 1,
            'Baley': 1, 'Joe': 1, 'Jackson': 1, 'Teddy': 1,
            'Aslan Mcgregor': 1, 'Charlie': 2, 'Murphy': 1, 'Bear': 1,
            'Cooper': 2, 'Rosie ': 1, 'Hunter': 1, 'Zeta': 1, 'Duke': 1,
            'Bruno': 1, 'Molly': 1, 'Tucker': 1, 'Chloe': 1, 'Gus': 1,
            'Rosie': 1, 'Sydney': 1, 'Sisco': 1, 'Izzy': 1, 'Cissie Bear': 1,
            'Neena': 1, 'Toby': 1, 'Jessie': 1, 'Cobalt': 1, 'Isis': 1,
            'Tonks': 1, 'Carly': 1, 'Jake': 1, 'Missy': 3, 'Jack': 1
            },
        'OwnerZip': {
            '15236': 1, '15238': 6, '15104': 1, '15139': 4, '15129': 1,
            '15090': 1, '15101': 2, '15228': 3, '15235': 5, '15108': 5,
            '15120': 2, '15239': 7, '15214': 2, '15218': 4, '15237': 1,
            '15018': 2, '15025': 4, '15017': 1, '15137': 1, '15045': 2, 
            '15131': 1, '15136': 5, '15205': 4, '15122': 1, '15234': 1, 
            '15057': 1, '15241': 3, '15147': 1, '15135': 2, '15044': 3,
            '15126': 1, '15229': 2, '15221': 2, '15102': 1, '15202': 2, 
            '15227': 1, '15148': 1, '15133': 2, '15209': 2, '15146': 1, 
            '15116': 3, '15106': 2, '15042': 1, '15068': 1, '15220': 1
            },
        'ExpYear': {
            2018: 100
            },
        'ValidDate': {
            2017: 100
            }
        })
    print('Passed!')

def testGetMostPopularValues():
    print('Testing getMostPopularValues()...', end='')
    assert(getMostPopularValues('2018-abridged') == {
        'LicenseType': 'Female',
        'Breed': 'Mixed',
        'Color': 'black',
        'DogName': {'Ellie', 'Lola', 'Missy'},
        'OwnerZip': '15239',
        'ExpYear': 2018,
        'ValidDate': 2017
        })
    print('Passed!')

def testSomeMoreDataAnalysis():
    print('Skipping testing for someMoreDataAnalysis().  :-)')

def testDogLicensesDataAnalysis():
    testReadDogDataCsvFileInto2dList()
    testConvert2dListToTable()
    testCleanData()
    testGetCleanedTable()
    testGetValueSets()
    testGetValueCounts()
    testGetMostPopularValues()
    testSomeMoreDataAnalysis()

#################################################
# testAll and main
#################################################

def testAll():
    # All are required (no mild/medium/spicy)
    testMovieAwards()
    testFriendsOfFriends()
    testInvertDictionary()
    testInvertDictionary()
    testDogLicensesDataAnalysis()
    #someMoreDataAnalysis()

def main():
    cs112_s20_unit8_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
