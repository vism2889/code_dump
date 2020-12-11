#################################################
# unit4_extra_practice.py
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
# Write your own file and test cases
#################################################

import cs112_s20_unit4_linter
import basic_graphics
import string, copy, random, math

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

def isPalindromicList(a):
    return 42

def reverse(a):
    return 42

def vectorSum(a,b):
    return 42

def dotProduct(a,b):
    return 42

def moveToBack(a,b):
    return 42

def binaryListToDecimal(a):
    return 42

def split(s, delimiter):
    return 42

def join(L, delimiter):
    return 42

def repeatingPattern(a):
    return 42

def mostAnagrams(wordList):
    return 42

def map(f, a):
    return 42

def firstNEvenFibonacciNumbers(n):
    return 42

def mostCommonName(a):
    return 42

def histogram(a):
    return 42

def nearestWords(wordList, word):
    return 42

def bowlingScore(pinsPerThrowList):
    return 42

def evalPolnomial(coeffs, x):
    return 42

def polynomialToString(p1,p2):
    return 42

def multiplyPolynoials(p1,p2):
    return 42

def areaOfPolygon(L):
    return 42

#################################################
# Test Functions
#################################################




#################################################
# testAll and main
#################################################

def testAll():
    # required
    return 42

def main():
    cs112_s20_unit4_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
