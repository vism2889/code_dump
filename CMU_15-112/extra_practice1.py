#################################################
# extra_practice1.py
#################################################

import cs112_s20_week1_linter
import math

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

def fabricYards(inches):
    #if (inches < 36) and (inches > 0):
        #return 1
    return math.ceil(inches/36)

def fabricExcess(inches):
    #print(fabricYards(inches))
    total = fabricYards(inches) * 36
    excess = (total - inches)
    #print(excess)
    return excess


def isMultiple(m, n):

    if (n ==0) and (m == 0):
        return True
    if n and (m % n == 0):
        #print(m % n)
        return True
    return False

def eggCartons(eggs):

    return math.ceil(eggs/12)

def isLegalTriangle(s1,s2,s3):

    max1 = max(s1,s2,s3)
    min1 = min(s1,s2,s3)
    middle = s1+s2+s3-max1-min1
    return max1 == (middle**2 + min1**2) ** 0.5

def distance(x1,y1,x2,y2):
    # helper function for isRightTriangle()
    return( (x2-x1)**2 + (y2-y1)**2)**0.5

def isRightTriangle(x1, y1, x2, y2, x3, y3):

    # the length of three sides.
    s1 = distance(x1, y1, x2, y2)
    s2 = distance(x2, y2, x3, y3)
    s3 = distance(x1, y1, x3, y3)

    if s1 > 0 and s2 > 0 and s2 > 0:
        # Test if it's a right triangle
        if almostEqual(s1 ** 2 + s2 ** 2, s3 ** 2) or \
        almostEqual(s2 ** 2 + s3 ** 2, s1 ** 2) or \
        almostEqual(s1 ** 2 + s3 ** 2, s2 ** 2):
            return True
    return False

#################################################
# Test Functions
#################################################

def testFabricYards():
    print('Testing fabricYards()... ', end='')
    assert(fabricYards(0) == 0)
    assert(fabricYards(1) == 1)
    assert(fabricYards(35) == 1)
    assert(fabricYards(36) == 1)
    assert(fabricYards(37) == 2)
    assert(fabricYards(72) == 2)
    assert(fabricYards(73) == 3)
    assert(fabricYards(108) == 3)
    assert(fabricYards(109) == 4)
    print('Passed.')

def testFabricExcess():
    print('Testing fabricExcess()... ', end='')
    assert(fabricExcess(0) == 0)
    assert(fabricExcess(1) == 35)
    assert(fabricExcess(35) == 1)
    assert(fabricExcess(36) == 0)
    assert(fabricExcess(37) == 35)
    assert(fabricExcess(72) == 0)
    assert(fabricExcess(73) == 35)
    assert(fabricExcess(108) == 0)
    assert(fabricExcess(109) == 35)
    print('Passed.')

def testIsMultiple():
    print('Testing isMultiple()... ', end='')
    assert(isMultiple(1,1) == True)
    assert(isMultiple(2,10) == False)
    assert(isMultiple(-5,25) == False)
    assert(isMultiple(5,0) == False)
    assert(isMultiple(0,0) == True)
    assert(isMultiple(2,11) == False)
    assert(isMultiple(10,2) == True)
    assert(isMultiple(0,5) == True)
    assert(isMultiple(25,-5) == True)
    print('Passed.')

def testEggCartons():
    print('Testing eggCartons()... ', end='')
    assert(eggCartons(0) == 0)
    assert(eggCartons(1) == 1)
    assert(eggCartons(12) == 1)
    assert(eggCartons(13) == 2)
    assert(eggCartons(24) == 2)
    assert(eggCartons(25) == 3)
    print('Passed.')

def testIsLegalTriangle():
    print('Testing isLegalTriangle()... ', end='')
    assert(isLegalTriangle(3, 4, 5) == True)
    assert(isLegalTriangle(5, 4, 3) == True)
    assert(isLegalTriangle(3, 5, 4) == True)
    assert(isLegalTriangle(0.3, 0.4, 0.5) == True)
    assert(isLegalTriangle(3, 4, 7) == False)
    assert(isLegalTriangle(7, 4, 3) == False)
    assert(isLegalTriangle(3, 7, 4) == False)
    assert(isLegalTriangle(5, -3, 1) == False)
    assert(isLegalTriangle(-3, -4, -5) == False)
    print('Passed.')

def testIsRightTriangle():
    print('Testing isRightTriangle()... ', end='')
    assert(isRightTriangle(0, 0, 0, 3, 4, 0) == True)
    assert(isRightTriangle(1, 1.3, 1.4, 1, 1, 1) == True)
    assert(isRightTriangle(9, 9.12, 8.95, 9, 9, 9) == True)
    assert(isRightTriangle(0, 0, 0, math.pi, math.e, 0) == True)
    assert(isRightTriangle(0, 0, 1, 1, 2, 0) == True)
    assert(isRightTriangle(0, 0, 1, 2, 2, 0) == False)
    assert(isRightTriangle(1, 0, 0, 3, 4, 0) == False)
    print('Passed.')

#################################################
# testAll and main
#################################################

def testAll():
    testFabricYards()
    testFabricExcess()
    testIsMultiple()
    testEggCartons()
    testIsLegalTriangle()
    testIsRightTriangle()

def main():
    cs112_s20_week1_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
