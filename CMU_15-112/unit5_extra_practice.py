#################################################
# unit5_extra_practice.py
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
# First week you are not provided test cases or starter file 
#################################################

import cs112_s20_unit5_linter
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
def isRectangular(L):
    # Only works for three dimensions
    if isinstance(L, list):
        for i in L:
            if isinstance(i, list):
                if len(L) == len(i): continue
                else: return False
                for j in i:
                    if isinstance(j, list):
                        if len(j) == len(i): continue
                        else: return False 
    else: return False
    return True


def isPrime(n):
    # helper for hasNoPrimes(L)
    if n < 2: return False
    if n ==2: return True
    if n % 2 == 0: return False
    maxFactor = roundHalfUp(n**0.5)
    for factor in range(3,maxFactor+1,2):
        if (n% factor ==0):
            return False 
    return True

def hasNoPrimes(L):
    if not isinstance(L, list): return False
    if not isinstance(L[0], list): return False
    rows, cols = (len(L), len(L[0]))
    for row in range(rows):
        for col in range(cols):
            if isPrime(L[row][col]): return False 
    return True

def hasDuplicates(L):
    assert(isinstance(L, list))
    alreadyExists = []
    rows, cols = (len(L),len(L[0]))
    for row in range(rows):
        for col in range(cols):
            if L[row][col] in alreadyExists:
                return True    
            else: alreadyExists.append(L[row][col])
    return False

def fixMostlyMagicSquare(L):
    # finds one element in the 2D list and replaces it to make the square 
    # a mostlyMagicSquare.
    rows, cols = (len(L), len(L[0]))
    for row in range(rows):
        print('rowsum : ', sum(L[row]))
        colSum = []
        for col in range(cols):
            colSum.append(L[row][col])
        print('colsum : ', sum(colSum))
        colSum = []

    

def makeMagicSquare(n):
    return 42

def isLatinSquare(board):
    return 42

def getCol(L, colNum):
    rows, cols = (len(L), len(L[0]))
    resultCol = []
    for col in range(cols):
        resultCol.append(L[col][colNum])
    return resultCol

def matrixMultiply(m1,m2):
    assert(isinstance(m1, list) and isinstance(m2, list))
    rows1, cols1 = (len(m1),len(m1[0]))
    rows2, cols2 = (len(m2),len(m2[0]))
    if cols1 != rows2:
        return None
    result = [] 
    summ = []
    for row1 in m1:
        for item in range(cols2):


        

    
    
    return 42

def isKnightsTour(board):
    return 42

def nQueensChecker(board):
    return 42

def writeYourOwnGame(someParameters):
    return 42

#################################################
# Test Functions
#################################################


def testIsRectangular():
    print('Testing isRectangular()...', end = '')
    assert(isRectangular([5]) == True)
    a = [4,4,4]
    assert(isRectangular(a) == True)
    a = [
    [[4,4,4],[4,4,4],[4,4,4]],
    [[4,4,4],[4,4,4],[4,4,4]],
    [[4,4,4],[4,4,4],[4,4,4]]] 
    assert(isRectangular(a) == True)
    a = [
    [[4,4,4],[4,4,4]],
    [[4,4,4],[4,4,4],[4,4,4]],
    [[4,4,4],[4,4,4],[4,4,4]]] 
    assert(isRectangular(a) == False)
    assert(isRectangular((1,2)) == False)
    assert(isRectangular('This is a string') == False)
    print('Passed')

def testHasNoPrimes():
    print('Testing hasNoPrimes()...', end='')
    a = [
        [3,13,3],
        [1,2,7],
        [5,6,7]]
    assert(hasNoPrimes(a) == False)
    a = [
        [1,4,6],
        [8,10,12],
        [14,16,18]]
    assert(hasNoPrimes(a) == True)
    print('Passed!')

def testHasDuplicates():
    print('Testing hasDuplicates()...', end = '')
    a = [
        [1,4,6],
        [8,10,12],
        [14,16,18]]
    assert(hasDuplicates(a) == False)
    a = [
        [1,1,6],
        [8,10,12],
        [14,16,18]]
    assert(hasDuplicates(a) == True)
    print('Passed!')

def testFixMostlyMagicSquare():
    assert(fixMostlyMagicSquare([[2, 7, 6],
                                [9, 5, 2],
                                [4, 3, 8]]) 
                                == 
                                [[2, 7, 6],
                                [9, 5, 1],
                                [4, 3, 8]])
    

def testMakeMagicSquare():
    assert(isMostlyMagicSquare(makeMagicSquare(3)))
    assert(isMostlyMagicSquare(makeMagicSquare(4)))
    assert(isMostlyMagicSquare(makeMagicSquare(5)))
    assert(isMostlyMagicSquare(makeMagicSquare(15)))

def testIsLatinSquare():
    a = [
        [1,2,3],
        [3,1,2],
        [2,3,1]]
    assert(isLatinSquare(a) == True)
    a = [
        [1,2,3],
        [3,1,2],
        [2,3,5]]
    assert(isLatinSquare(a) == False)
    a = [
        [1,2,3,4],
        [4,1,2,3],
        [3,4,1,2]
        [2,3,4,1]]
    assert(isLatinSquare(a) == True)
    a = [
        [1,2,3,4],
        [4,2,1,3],
        [3,4,1,2]
        [2,3,4,1]]
    assert(isLatinSquare(a) == False)
    return 42

def testMatrixMultiply():

    return 42

def testIsKnightsTour():
    return 42

def testNQueensChecker():
    return 42

def testWriteYourOwnGame():
    return 42

#################################################
# testAll and main
#################################################

def testAll():
    # required
    testIsRectangular()
    testHasNoPrimes()
    testHasDuplicates()
    testFixMostlyMagicSquare()
    testMakeMagicSquare()
    testIsLatinSquare()
    testMatrixMultiply()
    testIsKingsTour()
    testNQueensChecker()
    testWriteYourOwnGame()

def main():
    cs112_s20_unit5_linter.lint()
      
    #print(isRectangular(a))
    testAll()

if __name__ == '__main__':
    main()