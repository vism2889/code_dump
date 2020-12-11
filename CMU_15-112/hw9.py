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
        if currMultiple ==1:
            nto3List += powersOf3ToN(n, currMultiple + 2)
        else:
            nto3List += powersOf3ToN(n, currMultiple + 3)
    return nto3List

def binarySearchValues(L, item):
    return 42


def secondLargest(L):
    return 42

    

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
    testBinarySearchValues()
    testSecondLargest()

    # spicy problems:  NOT HERE!!!
    pass

def main():
    cs112_s20_unit9_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
