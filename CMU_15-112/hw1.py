#################################################
# hw1.py
#
# Your name:Morgan Visnesky
# Your andrew id: mvisnesk
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

#########
# MORGANS TODO:
#   - clean up functions
#   - complete 80pts worth of functions and then focus
#   on 'spicier' problems
#   - replace functions using math library with pure math in python


def isEvenPositiveInt(x):
    if isinstance(x, int) and (x > 0) and (x % 2 == 0):
        return True
    else:
        return False

def nearestBusStop(street):
    freq = 8
    stop = 0

    if street % freq == 0:
        stop = street
    else:
        closestUp = (street + freq) - (street % freq)
        closestDown = street - (street % freq)
        if (closestUp - street) > (street - closestDown):
            stop = closestDown
        elif (closestUp - street) < (street - closestDown):
            stop = closestUp
        else:
            stop = closestDown
    return stop

def isPerfectSquare(n):
    perfectSquare = None
    if isinstance(n, int) and (n >= 0):
        if n**0.5 % 1 == 0:
            perfectSquare = True
        else:
            perfectSquare = False
    else:
        perfectSquare = False
    return perfectSquare

def nthFibonacciNumber(n):
    if n == 0:
        return 1
    else:
        # binet's formula for fibonacci number
        sq5 = 5**0.5 # square root of 5
        expon = (n + 1) # making sure n starts at 1 not 0
        nth = (
            ((1 + sq5) / 2)**expon -
            ((1 - sq5) / 2)**expon
            ) / sq5
        return int(nth)

def numberOfPoolBalls(rows):
    numberOfBalls = 0

    if isinstance(rows, int) and (rows >0):
        if rows == 0:
            numberOfBalls = 0
        else:
            numberOfBalls = (rows*(rows+1))//2
    return numberOfBalls

def isFactorish(n):
    # needs some work :p
    if isinstance(n, int):
        n = abs(n)
        if (n//1000 == 0) and (n//100 > 0):
            ones = n % 10
            tens = (n // 10) % 10
            hundreds = n // 100
            if (ones != 0):
                if (hundreds % tens == 0) or (tens % hundreds == 0):
                    if (tens % ones == 0) or (ones % tens == 0):
                        if (hundreds != tens != ones):
                            return True
    return False

def nearestOdd(n):
    # needs some work
    # hint use roundHalfUp() function
    nearest = 0
    if (n % 1 > 0) and ((n//1) % 2 == 0):
        if (n % 1 > 0) and (n % 2 != 0):
            nearest = (n // 1) + 1
    elif (n % 2 == 0):
        nearest = (n // 1) - 1
    else:
        nearest = (n // 1)
    return int(nearest)


def rectanglesOverlap(x1, y1, w1, h1, x2, y2, w2, h2):
    # (x1,y1) = point of top left corner of rectangle_1
    # BR = Bottom Right

    # possiibly move whole coordinate system
    BRX1 = x1 + w1
    BRY1 = y1 + h1
    BRX2 = x2 + w2
    BRY2 = y2 + h2
    if (x2 <= BRX1) and (x2 >= x1):

        print('GL')
        if (y2 <= BRY1) and (y2 >= y1): # breaks beacause y2 less than 1
            print('t')
            return True

    elif (x1 <= BRX2) and (x1 >= x2):
        if (y1 <= BRY2) and (y1 >= y2):
            print('t')
            return True
    print('f', "- ", BRX2, BRY2, x1, y1, BRX1, BRY1, x2, y2) # for testing
    return False

    '''
    # broken
    distance = ((x2 - x1)**2 + (y2-y1)**2) ** 0.5
    if (distance < (w1+w2)) or (distance < (h1+h2)):
        return True
    return False
    '''

    '''
    # broken
    if (y2) <= (y1 + h1):
        print ("from 0, height: ", y1+h1)
        if (x2) <= (x1 + w1):
            print ("from 0, width: ", x1+w1)
            return True
    return False
    '''
def numberOfPoolBallRows(balls):
    # this is the inverse of numberOfPoolBalls() function above
    # use quadratic formula
    rows = math.ceil((-1+(1+8*balls)**0.5)/2)
    # print(rows) # for testing
    return rows

def distance(x1, y1, x2, y2):
    return ((x2 - x1)**2 + (y2-y1)**2) ** 0.5

def threeLinesArea(m1, b1, m2, b2, m3, b3):
    # treat like system of equations
    # herons formula for triangle area A = sqrt( s(s-a)(s-b)(s-c))
    # s = semiperimeter which is half of actual perimeter of triangle
    # use distance formula to find distance of each side
    if (m1 != m2) and (m1 != m3) and (m2 != m3):
        x1 = (b2 - b1) / (m1 - m2)
        y1 = m1 * x1 + b1

        x2 = (b3 - b2) / (m2 - m3)
        y2 = m2 * x2 + b2

        x3 = (b3 - b1) / (m1 - m3)
        y3 = m1 * x3 + b1

        dist1 = distance(x1,y1,x2,y2)
        dist2 = distance(x2,y2,x3,y3)
        dist3 = distance(x3,y3,x1,y1)

        p = dist1 + dist2 + dist3 # perimeter
        s = p / 2 # semiperimeter
        A = (s*(s-dist1)*(s-dist2)*(s-dist3))**0.5 # Herons Formula
        return A
    return 0



def colorBlender(rgb1, rgb2, midpoints, n):
    # 000,000,000
    if (n < 0) or (n > midpoints):
        return None
    if n == 0:
        return rgb1

    stepp = (n)*(1/midpoints) # step you want to return

    # indivial R G and B's seperated
    x = rgb1 // 1000000
    x2 = (rgb1 % 1000000) // 1000
    x3 = rgb1 % 1000
    #print(x)
    y = rgb2 // 1000000
    y2 = (rgb2 % 1000000) // 1000
    y3 = rgb2 % 1000

    # differences between colors
    diff1 = roundHalfUp(abs(x-y))
    diff2 = abs(x2-y2)
    diff3 = abs(x3-y3)

    newx1 = newx2  = newx3 = 0


    # find out if middle point is above or below rgb1
    # add or subtract (stepp * diff) to each rgb1 value
    if x > y:
        newx1 = x - roundHalfUp(stepp * diff1)
        print("step:", stepp)
        print("diff1:", diff1)
        print("value to alter by:", roundHalfUp(stepp*diff1))
        print("new value:", newx1)
    else:
        newx1 = x + stepp * diff1

    if x2 > y2:
        newx2 = x2 - stepp * diff2
    else:
        newx2 = x2 + stepp * diff2

    if x3 > y3:
        newx3 = x3 - stepp * diff3
    else:
        newx3 = x3 + stepp * diff3


    # turn back into one number from the three parts
    newRGB1 = (
                (roundHalfUp(newx1) * 1000000) +
                (roundHalfUp(newx2) * 1000) +
                roundHalfUp(newx3)
                )
    newRGB2 = ((y * 1000000) + (y2 * 1000) + y3)

    print(newRGB1)
    print(newRGB2)
    return None

def playThreeDiceYahtzee(dice):
    return 42

def real(z):
    return (complex(z)).real # since in 2.5 non-complex don't have .real

def findIntRootsOfCubic(a, b, c, d):
    return 42

#################################################
# Test Functions
#################################################

def testIsEvenPositiveInt():
    print('Testing isEvenPositiveInt()... ', end='')
    assert(isEvenPositiveInt(809) == False)
    assert(isEvenPositiveInt(810) == True)
    assert(isEvenPositiveInt(2389238001) == False)
    assert(isEvenPositiveInt(2389238000) == True)
    assert(isEvenPositiveInt(-2389238000) == False)
    assert(isEvenPositiveInt(0) == False)
    assert(isEvenPositiveInt('do not crash here!') == False)
    print('Passed.')

def testNearestBusStop():
    print('Testing nearestBusStop()... ', end='')
    assert(nearestBusStop(0) == 0)
    assert(nearestBusStop(4) == 0)
    assert(nearestBusStop(5) == 8)
    assert(nearestBusStop(12) == 8)
    assert(nearestBusStop(13) == 16)
    assert(nearestBusStop(20) == 16)
    assert(nearestBusStop(21) == 24)
    print('Passed.')

def testIsPerfectSquare():
    print('Testing isPerfectSquare()... ', end='')
    assert(isPerfectSquare(0) == True)
    assert(isPerfectSquare(1) == True)
    assert(isPerfectSquare(16) == True)
    assert(isPerfectSquare(1234**2) == True)
    assert(isPerfectSquare(15) == False)
    assert(isPerfectSquare(17) == False)
    assert(isPerfectSquare(-16) == False)
    assert(isPerfectSquare(1234**2+1) == False)
    assert(isPerfectSquare(1234**2-1) == False)
    assert(isPerfectSquare(4.0000001) == False)
    assert(isPerfectSquare('Do not crash here!') == False)
    print('Passed.')

def testNthFibonacciNumber():
    print('Testing nthFibonacciNumber()... ', end='')
    assert(nthFibonacciNumber(0) == 1)
    assert(nthFibonacciNumber(1) == 1)
    assert(nthFibonacciNumber(2) == 2)
    assert(nthFibonacciNumber(3) == 3)
    assert(nthFibonacciNumber(4) == 5)
    assert(nthFibonacciNumber(5) == 8)
    assert(nthFibonacciNumber(6) == 13)
    print('Passed.')

def testNumberOfPoolBalls():
    print('Testing numberOfPoolBalls()... ', end='')
    assert(numberOfPoolBalls(0) == 0)
    assert(numberOfPoolBalls(1) == 1)
    assert(numberOfPoolBalls(2) == 3)   # 1+2 == 3
    assert(numberOfPoolBalls(3) == 6)   # 1+2+3 == 6
    assert(numberOfPoolBalls(10) == 55) # 1+2+...+10 == 55
    print('Passed.')

def testIsFactorish():
    print('Testing isFactorish()...', end='')
    assert(isFactorish(412) == True)      # 4, 1, and 2 are all factors of 412
    assert(isFactorish(-412) == True)     # Must work for negative numbers!
    assert(isFactorish(4128) == False)    # has more than 3 digits
    assert(isFactorish(112) == False)     # has duplicates digits (two 1's)
    assert(isFactorish(420) == False)     # has a 0 (no 0's allowed)
    assert(isFactorish(42) == False)      # has a leading 0 (no 0's allowed)
    assert(isFactorish(1.0) == False)     # floats are not factorish
    assert(isFactorish('nope!') == False) # don't crash on strings
    print('Passed!')

def testNearestOdd():
    print('Testing nearestOdd()... ', end='')
    assert(nearestOdd(13) == 13)
    assert(nearestOdd(12.001) == 13)
    assert(nearestOdd(12) == 11)
    assert(nearestOdd(11.999) == 11)
    assert(nearestOdd(-13) == -13)
    assert(nearestOdd(-12.001) == -13)
    assert(nearestOdd(-12) == -13)
    assert(nearestOdd(-11.999) == -11)
    # results must be int's not floats
    assert(isinstance(nearestOdd(13.0), int))
    assert(isinstance(nearestOdd(11.999), int))
    print('Passed.')

def testRectanglesOverlap():
    print('Testing rectanglesOverlap()...', end='')
    assert(rectanglesOverlap(1, 1, 2, 2, 2, 2, 2, 2) == True)
    assert(rectanglesOverlap(1, 1, 2, 2, -2, -2, 6, 6) == True)
    assert(rectanglesOverlap(1, 1, 2, 2, 3, 3, 1, 1) == True)
    assert(rectanglesOverlap(1, 1, 2, 2, 3.1, 3, 1, 1) == False)
    assert(rectanglesOverlap(1, 1, 1, 1, 1.9, -1, 0.2, 1.9) == False)
    assert(rectanglesOverlap(1, 1, 1, 1, 1.9, -1, 0.2, 2) == True)
    assert(rectanglesOverlap(1, 1, 2, 2, 2, 2, 2, 6) == True)
    assert(rectanglesOverlap(1, 1, 2, 2, 3,4,5,6) == False)
    print('Passed.')

def testNumberOfPoolBallRows():
    print('Testing numberOfPoolBallRows()... ', end='')
    assert(numberOfPoolBallRows(0) == 0)
    assert(numberOfPoolBallRows(1) == 1)
    assert(numberOfPoolBallRows(2) == 2)
    assert(numberOfPoolBallRows(3) == 2)
    assert(numberOfPoolBallRows(4) == 3)
    assert(numberOfPoolBallRows(6) == 3)
    assert(numberOfPoolBallRows(7) == 4)
    assert(numberOfPoolBallRows(10) == 4)
    assert(numberOfPoolBallRows(11) == 5)
    assert(numberOfPoolBallRows(55) == 10)
    assert(numberOfPoolBallRows(56) == 11)
    print('Passed.')

def testThreeLinesArea():
    print('Testing threeLinesArea()... ', end='')
    assert(almostEqual(threeLinesArea(1, 2, 3, 4, 5, 6), 0))
    assert(almostEqual(threeLinesArea(0, 7, 1, 0, -1, 2), 36))
    assert(almostEqual(threeLinesArea(0, 3, -.5, -5, 1, 3), 42.66666666666666))
    assert(almostEqual(threeLinesArea(1, -5, 0, -2, 2, 2), 25))
    assert(almostEqual(threeLinesArea(0, -9.75, -6, 2.25, 1, -4.75), 21))
    assert(almostEqual(threeLinesArea(1, -5, 0, -2, 2, 25), 272.25))
    print('Passed.')

def testColorBlender():
    print('Testing colorBlender()... ', end='')
    # http://meyerweb.com/eric/tools/color-blend/#DC143C:BDFCC9:3:rgbd
    assert(colorBlender(220020060, 189252201, 3, -1) == None)
    assert(colorBlender(220020060, 189252201, 3, 0) == 220020060)
    assert(colorBlender(220020060, 189252201, 3, 1) == 212078095)
    assert(colorBlender(220020060, 189252201, 3, 2) == 205136131)
    assert(colorBlender(220020060, 189252201, 3, 3) == 197194166)
    assert(colorBlender(220020060, 189252201, 3, 4) == 189252201)
    assert(colorBlender(220020060, 189252201, 3, 5) == None)
    # http://meyerweb.com/eric/tools/color-blend/#0100FF:FF0280:2:rgbd
    assert(colorBlender(1000255, 255002128, 2, -1) == None)
    assert(colorBlender(1000255, 255002128, 2, 0) == 1000255)
    assert(colorBlender(1000255, 255002128, 2, 1) == 86001213)
    assert(colorBlender(1000255, 255002128, 2, 2) == 170001170)
    assert(colorBlender(1000255, 255002128, 2, 3) == 255002128)
    print('Passed.')

def testPlayThreeDiceYahtzee():
    print('Testing playThreeDiceYahtzee()...', end='')
    assert(handToDice(123) == (1,2,3))
    assert(handToDice(214) == (2,1,4))
    assert(handToDice(422) == (4,2,2))
    assert(diceToOrderedHand(1,2,3) == 321)
    assert(diceToOrderedHand(6,5,4) == 654)
    assert(diceToOrderedHand(1,4,2) == 421)
    assert(diceToOrderedHand(6,5,6) == 665)
    assert(diceToOrderedHand(2,2,2) == 222)
    assert(playStep2(413, 2312) == (421, 23))
    assert(playStep2(421, 23) == (432, 0))
    assert(playStep2(413, 2345) == (544, 23))
    assert(playStep2(544, 23) == (443, 2))
    assert(playStep2(544, 456) == (644, 45))
    assert(score(432) == 4)
    assert(score(532) == 5)
    assert(score(443) == 10+4+4)
    assert(score(633) == 10+3+3)
    assert(score(333) == 20+3+3+3)
    assert(score(555) == 20+5+5+5)
    assert(playThreeDiceYahtzee(2312413) == (432, 4))
    assert(playThreeDiceYahtzee(2315413) == (532, 5))
    assert(playThreeDiceYahtzee(2345413) == (443, 18))
    assert(playThreeDiceYahtzee(2633413) == (633, 16))
    assert(playThreeDiceYahtzee(2333413) == (333, 29))
    assert(playThreeDiceYahtzee(2333555) == (555, 35))
    print('Passed!')

def getCubicCoeffs(k, root1, root2, root3):
    # Given roots e,f,g and vertical scale k, we can find
    # the coefficients a,b,c,d as such:
    # k(x-e)(x-f)(x-g) =
    # k(x-e)(x^2 - (f+g)x + fg)
    # kx^3 - k(e+f+g)x^2 + k(ef+fg+eg)x - kefg
    e,f,g = root1, root2, root3
    return k, -k*(e+f+g), k*(e*f+f*g+e*g), -k*e*f*g

def testFindIntRootsOfCubicCase(k, z1, z2, z3):
    a,b,c,d = getCubicCoeffs(k, z1, z2, z3)
    result1, result2, result3 = findIntRootsOfCubic(a,b,c,d)
    m1 = min(z1, z2, z3)
    m3 = max(z1, z2, z3)
    m2 = (z1+z2+z3)-(m1+m3)
    actual = (m1, m2, m3)
    assert(almostEqual(m1, result1))
    assert(almostEqual(m2, result2))
    assert(almostEqual(m3, result3))

def testFindIntRootsOfCubic():
    print('Testing findIntRootsOfCubic()...', end='')
    testFindIntRootsOfCubicCase(5, 1, 3,  2)
    testFindIntRootsOfCubicCase(2, 5, 33, 7)
    testFindIntRootsOfCubicCase(-18, 24, 3, -8)
    testFindIntRootsOfCubicCase(1, 2, 3, 4)
    print('Passed.')

#################################################
# testAll and main
#################################################

def testAll():
    # comment out the tests you do not wish to run!
    # mild
    testIsEvenPositiveInt()
    testNearestBusStop()
    testIsPerfectSquare()
    testNthFibonacciNumber()
    testNumberOfPoolBalls()
    testIsFactorish()
    testNearestOdd()

    # medium
    #testRectanglesOverlap()
    testNumberOfPoolBallRows()
    testThreeLinesArea()

    # spicy
    testColorBlender()
    testPlayThreeDiceYahtzee()
    testFindIntRootsOfCubic()

def main():
    cs112_s20_week1_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
