#################################################
# hw9.py
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
#
# Names and andrew id's of up to 3 collaborators:
#   name + andrew id #1:
#   name + andrew id #2:
#   name + andrew id #3:
#################################################

import cs112_s20_unit9_linter
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

#################################################
# Functions for you to write
#################################################

def alternatingSum(L):
    # recursively returns an alternating sum in the form of:
    # 1-2+3-4+5
    result = 0
    if len(L) > 0:
        result = L[0] - alternatingSum(L[1:])
    return result

def singleItemOnlyEven(n, count=0):
    # helper function for onlyEvenDigits 
    # recursively returns only evens of single number
    newN = 0
    ones = -1
    if n > 0:
        ones = n % 10
        n = n //10
        if ones % 2 == 0:
            newN += ones * 10**count
            count+=1
        else:
            pass
        newN += singleItemOnlyEven(n, count)
    else:pass
    return newN
    
        

def onlyEvenDigits(L):
    # uses singleItemOnlyEvens to replace all items in list L
    # with only the even digit versions of those items
    newL = []
    if len(L) > 0:
        newL.append(singleItemOnlyEven(L[0]))
        if len(newL) != len(L):
            newL += onlyEvenDigits(L[1:])
    return newL

def isPow3(n, result=0):
    # helper function for powersOf3ToN that recursively determines 
    # if a given number is a power of three
    if n ==1: return True
    if n > 1:
        if n % 3 == 0:
            n = n // 3
            result = n
        else: return False
        result = isPow3(n, result)
    return (result == 1)

def powersOf3ToN(n, currMultiple=1):
    # returns a list of all the powers of 3 up to a given number
    # uses the helper function isPow3 on each value checked
    nto3List = []
    if currMultiple <= n:
        if isPow3(currMultiple):
            nto3List.append(currMultiple)
        else:
            pass
        nto3List += powersOf3ToN(n, currMultiple + 1)
    return nto3List
'''
def binarySearchValues(L, item, result=[], s = 0):
    # broken does not work
    #print('or', ord(L[0]), 'end or', ord(L[len(L)-1]))
    
    print('L',L, 'result', result)
    itemOrd = ord(item)
    print('itemOrd',itemOrd)
    #result = []
    low = 0
    lowItem = ord(L[0])
    high = len(L) - 1
    highItem = ord(L[len(L)-1])    
    print(lowItem, highItem, 'low and high items')
    if len(L) == 0:
        print('hi im zero')
        result1 = result
        result = []
        return result1
        #pass
    if lowItem <= itemOrd:
        mid = (low + high) // 2
        midOrd = ord(L[mid])
        print(midOrd, 'midOrd', mid, 'mid')
        if midOrd == itemOrd:
            #mid = L[midOrd+1]
            result += [(mid+1, chr(midOrd))]
            print('equals',result)
            result1 = result
            result = []
            return result1
        elif midOrd > itemOrd:
            s = len(L)
            high = mid - 1
            L = L[:mid]
            print("LLL",L)
            result += [(s//2 - 1, chr(midOrd))]
            print(result)
            return binarySearchValues(L, item, result,s)
            
        else:# midOrd < itemOrd:
            print('MIDS')
            s = len(L)
            low = mid + 1
            L = L[mid+1:]
            result += [(s//2-1, chr(midOrd))]
            print(result)
            return binarySearchValues(L, item, result,s)
            
        print('result', result)
        return result
'''
def binarySearchValues(L, item, low=0):
    # broken / does not work
    result = []
    high = len(L)- 1
    if low <= high:
        mid  = (low + high) //2 
        print(high, low, mid)
        if ord(L[mid]) > ord(item):
            result += [(mid, L[mid])]
            #high = mid-1
            print(result)
            result += binarySearchValues(L, item, low)
            #search lower
            #result +=
        if ord(L[mid]) < ord(item):
            #search higher
            result+= [(mid, L[mid])]
            print(result)
    return 1 #result



def secondLargest(L, largest = 0, index = 0, second = 0):
    #close but broken
    print('index', index)
    if len(L) < 2:
        return None
    elif index <= len(L)-1:
        
        if L[index] >= largest:
            second = largest
            largest = L[index] 
            
            print(largest, second)

            return secondLargest(L, largest, index+1, second)
        if L[index] < largest and L[index] >= second and index == len(L)-1:
            print('second')
            second = L[index]
            print('sec', second)
            return second
    else:
        print('second',second, largest)
        return second

    

#################################################
# Test Functions
#################################################

def testAlternatingSum():
    print('Testing alternatingSum()...', end='')
    assert(alternatingSum([1,2,3,4,5]) == 1-2+3-4+5)
    assert(alternatingSum([ ]) == 0)
    print('Passed!')

def testSecondLargest():
    print('Testing secondLargest()...', end='')
    assert(secondLargest([1,2,3,4,5]) == 4)
    assert(secondLargest([4,3]) == 3)
    assert(secondLargest([4,4,3]) == 4)
    assert(secondLargest([-3,-4]) == -4)
    assert(secondLargest([4]) == None)
    assert(secondLargest([ ]) == None)
    print('Passed!')

def testOnlyEvenDigits():
    print('Testing onlyEvenDigits()...', end='')
    assert(onlyEvenDigits([43, 23265, 17, 58344]) == [4, 226, 0, 844])
    assert(onlyEvenDigits([ ]) == [ ])
    print('Passed!')

def testPowersOf3ToN():
    print('Testing powersOf3ToN()...', end='')
    assert(powersOf3ToN(10.5) == [1, 3, 9])
    assert(powersOf3ToN(27) == [1, 3, 9, 27])
    assert(powersOf3ToN(26.999) == [1, 3, 9])
    assert(powersOf3ToN(-1) == [ ])
    print('Passed!')

def testBinarySearchValues():
    print('Testing binarySearchValues()...', end='')
    assert(binarySearchValues(['a', 'c', 'f', 'g', 'm', 'q'], 'c') ==
           [(2, 'f'), (0, 'a'), (1, 'c')])
    assert(binarySearchValues(['a', 'c', 'f', 'g', 'm', 'q'], 'n') ==
           [(2, 'f'), (4, 'm'), (5, 'q')])
    print('Passed!')

#################################################
# testAll and main
#################################################

def testAll():
    print()
    print('Testing **** non-spicy *** hw9 problems!')
    print()

    # mild+medium problems:
    testAlternatingSum()
    testOnlyEvenDigits()
    testPowersOf3ToN()
    #testBinarySearchValues()
    testSecondLargest()

    # spicy problems:  NOT HERE!!!
    pass

def main():
    cs112_s20_unit9_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
