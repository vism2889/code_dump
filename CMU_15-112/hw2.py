#################################################
# hw2.py
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
#################################################

import cs112_s20_unit2_linter
import basic_graphics
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

def rgbString(red, green, blue):
    # Don't worry about how this code works yet.
    return "#%02x%02x%02x" % (red, green, blue)

#################################################
# Functions for you to write
#################################################
def drawFancyLines(canvas, cx, cy, r, n):

    return 42

def drawFancyWheel(canvas, cx, cy, r, n, color):
    # helper function for drawFancyWheels()
    colors = color
    n=n
    r = 0.9*r
    #diameter = width/n
    canvas.create_oval(cx-r,cy-r,cx+r, cy+r, outline = colors)

    # need to do +4 because first one has 4 points
    # red based on column and green based on row blue is always 0
    # create loop to make lines for value of n
    # whole helper function for drawing lines
    # y = (cy-r)*angle you're at, need to use sin and
    m = n+4
    v = m
    for j in range(1,m+1):
        #startAngle = math.pi/2 - (2*math.pi) * (math.pi/j)
        #stopAngle = startAngle +(2*math.pi)*(math.pi/j)

        for i in range(1,m+1):

            startAngle = math.pi/2 - (2*math.pi) *(v/m)
            startLineX = cx + r * math.cos(startAngle)
            startLineY = cy - r * math.sin(startAngle)
            for i in range(1,m+1):
                stopAngle = math.pi/2 + (2*math.pi)*(i/m)
                #print(stopAngle)
                stopLineX = cx + r * math.cos(stopAngle)
                stopLineY = cy - r * math.sin(stopAngle)
                canvas.create_line(startLineX, startLineY, \
                                    stopLineX, stopLineY, fill=colors)
            v -= 1


def drawFancyWheels(canvas, width, height, rows, cols):
    diameter = width/cols
    r = 0
    g = 255
    b = 0
    for row in range(rows):

        for col in range(cols):

            cx = diameter*col + (diameter/2)
            cy = diameter*row + (diameter/2)
            #r = 0
            if rows == 1:
                r = 0
            else:
                r = (255//(rows-1)) * ((row)//1)
            #print(r)
            g = (255//(col+1))
            #print(g)

            #b = 0
            color = rgbString(r,g,b)
            drawFancyWheel(canvas, cx,cy,diameter/2,col+row,color)
            #r += 255//(rows)
            #g -= 255//(cols)
    return 42

def numOccurances(n, currNum):
    # helper function for mostFrequentDigit(n)
    count = 0
    while n:
        if (n % 10 == currNum):
            count +=1
        n = int(n/10)
    return count

def mostFrequentDigit(n):
    # use a helper function to count occurances of a single digit
    if (n < 0):
        n *= -1
    mFreq = 0
    maxVal = 0
    for i in range(10):
        count2 = numOccurances(n,i)
        if count2 > maxVal:
            maxVal = count2;
            mFreq = i;
            #print(maxVal, i)
    #print(mFreq) # testing
    return mFreq

'''
START nthPalindromicPrime()
'''
def fasterIsPrime(n):
    if (n < 2):
        return False
    if (n == 2):
        return True
    if (n % 2 == 0):
        return False
    maxFactor = roundHalfUp(n**0.5)
    for factor in range(3,maxFactor+1,2):
        if (n % factor == 0):
            return False
    return True


def digitCounter(n):
    # helper for numberReverser() and isPalindrome()
    count = 0
    while n:
        count += 1
        n //=10
    return(count)

def numberReverser(n):
    # helper for isPalindrome()
    num = abs(n)
    numDigs = digitCounter(num)
    reverseNum = 0
    for i in range(numDigs):
        dig = n % 10
        reverseNum += dig*(10**(numDigs-i))
        n //= 10
    reverseNum //=10
    if n < 0:
        reverseNum *= -1
    return reverseNum

def isPalindrome(n):
    # helper for nthPalindromicPrime()
    if numberReverser(n) == n:
        return True
    return False

def nthPalindromicPrime(n):
    if n == 0:
        return 2
    count = 0
    counter = 0
    nthPal = 0
    while (count != (n+1)):
        if fasterIsPrime(counter) and isPalindrome(counter):
            nthPal = counter
            count += 1
            #print(nthPal)
        else:
            pass
        counter += 1
    #print(nthPal)
    return nthPal

'''
END nthPalindromicPrime()
'''


def carrylessAdd(x, y):
    result = 0
    digit = 1
    digitSum = 0
    #print('start')
    while (x or y): # while x and y are not zero
        #print('x: ',x,'y: ',y)
        digitSum = ((x % 10) + (y % 10)) # add ones places together
        #print(digitSum, x, y)
        digitSum %= 10 # get rid of remainder
        #print(digitSum)

        # add to corresponding place in result 'digit' multiplier
        # starts at 1, goes to 10 next iteration, than 100
        # puts reults back into proper digit place
        result = (digitSum * digit) + result
        #print(result)
        x = math.floor(x / 10) # removes 1's place
        #print(x)
        y = math.floor(y / 10) # removes 1's place
        #print(y)
        digit *= 10 # increase multiplier
        #print(digit, "s")
    #print("result: ", result)
    return result

def integral(f, a, b, N):
    # keep track of x0 and x1
    sum = 0
    integral = 0
    for i in range(1,N+1):
        sum += (f(a+i)*(b-a)/N)
        print(sum)
    integral = ((b-a)/N)*sum
    print(integral)
    return integral

''' ########## ##########
    START nthWithProperty309()
    ########## ##########
'''
def findDigit(dig, n):
    # helper for hasEveryDigit()
    while n:
        m = n % 10
        if m == dig:
            return True
        n //= 10
    return False

def hasEveryDigit(n):
    # helper for hasPoperty309()
    n = abs(n)
    count = 0
    for i in range(10):
        if findDigit(i,n):
            count += 1
    if count == 10:
        return True
    return False

def nthWithProperty309(n):
    count = -1
    currNum = 300
    while count != n:
        currNum +=1
        if hasEveryDigit(currNum**5):
            count+=1
            #print(currNum)
    return currNum

''' ########## ##########
    END nthWithProperty309()
    ########## ##########
'''

def isCircularPrime(n):
    counter = 0
    n = abs(n)
    numDigs = digitCounter(n)
    #print('numDigits: ', numDigs)
    sum = 0
    if fasterIsPrime(n):
        #counter +=1
        #print(n)
        while counter < (numDigs):
            m = n % 10
            n//=10
            n += m*(10**(numDigs-1))
            if fasterIsPrime(n):

            #print(n)
                if fasterIsPrime(n):
                    counter+=1
                    #print('prime is: ',n, counter,numDigs)
            else: return False
    if (counter == numDigs) and fasterIsPrime(n):
        #print(counter)
        return True
    else:
        return False
def nthCircularPrime(n):
    # do a similar thing to what were doing with palindrome()

    # count the num of digits might be required

    counter = 0
    incrementer = 0
    while counter <= n:
        incrementer += 1
        if isCircularPrime(incrementer):
            #print(incrementer)
            counter +=1
    #print(incrementer)
    return incrementer


def findZeroWithBisection(f, x0, x1, epsilon):

    # find what parameters equal zero
    # intermediate value theorem
    return 42

def nthSmithNumber(n):

    #find which factors are prime and then add and see if thats prime too
    return 42

def carrylessMultiply(x1, x2):
    # calulate the mulitplication for each digit of smaller number,
    # each time multiply result by proper position multiplier
    # and carrylessAdd() the results together
    # close but needs work
    counter = 0
    minn = min(x1,x2);
    maxx = max(x1,x2);
    product = 0
    sum = 0
    while minn:
        num = minn % 10
        print(num)
        while maxx:
            num2 = maxx % 10
            print(num2)
            result = (num * num2) % 10
            print(result)
            result = result*(10**counter)
            counter += 1
            print(result)
            sum += result
            print('sum: ',sum)

            maxx //= 10
            minn //= 10
        minn //=10

        #sum = sum*(10**counter)
        print('sum: ', sum)
        product += sum

    print(sum)
    return sum



def isKaprekarNumber(n):
    n = abs(n)
    # helper function for nthKaprekaNumber()
    orgNPow = n**2
    varN = n
    nPow = n**2
    part1 = 0
    part2 = 0
    half1 = 0
    half2 = 0
    # if numDigits even sum equal parts, if num digits odd
    # right hand part takes odd left over
    # EX: 0000 = 00+00      00000 = 00+000
    digNum = digitCounter(nPow)
    halfs = digNum // 2
    if (digNum % 2 == 0):
        # DO NOTHING
        half1 = halfs
        half2 = halfs
    else:
        half1 = halfs
        half2 = halfs + 1
        #print('half1', half1, 'half2', half2)
        # get half2
    for i in range(half2):
        m = nPow % 10
        part2 += (m * (10**i))
        nPow //= 10
    part1 = (orgNPow - part2)//(10**half2)
    #print('part1: ', part1, 'part2: ', part2)
    if (part1+part2) == n:
        return True
    return False

def nthKaprekarNumber(n):
    n = abs(n)
    guess = 0
    count = 0
    result = 0
    while count <= n:
        guess += 1
        if isKaprekarNumber(guess):
            count += 1
            result = guess
    return result

def fastestIsPrime(n):
    if (n < 2):
        return False
    if (n == 2):
        return True
    if (n % 2 == 0):
        return False
    maxFactor = roundHalfUp(n**0.5)
    for factor in range(3,maxFactor+1,2):
        if (n % factor == 0):
            return False
    return True

def isCarolPrime(n):
    # helper function for nthCarolPrime(n)
    kn = ((2**n-1)**2)-2
    if fastestIsPrime(kn) and fasterIsPrime(n):
        print('n', n)
        print('kn', kn)
        return True
    return False



def nthCarolPrime(n):
    count = -1
    incrementer = 0
    while count < (n+1):
        incrementer += 1
        if isCarolPrime(incrementer):
            count +=1
    print(incrementer)
    result = ((2**(incrementer)-1)**2)-2
    print(result)
    return result

def play112(game):
    return 42

############################
# integerDataStructures
# If you do this spicy problem,
# place your solutions here!
############################

#################################################
# Test Functions
# ignore_rest (tell autograder to ignore everything below here)
#################################################

def testDrawFancyWheels():
    print('Testing drawFancyWheels()... (confirm visually)')
    print('  drawFancyWheels: 1 row x 1 col, win size of 400x400...', end='')
    basic_graphics.run(1, 1, width=400, height=400, drawFn=drawFancyWheels)
    print('  drawFancyWheels: 4 rows x 6 cols, win size of 900x600...', end='')
    basic_graphics.run(4, 6, width=900, height=600, drawFn=drawFancyWheels)

    #print('  drawFancyWheels: 10 rows x 10 cols, win size of 900x600...',
    #end='')
    #basic_graphics.run(6, 8, width=1080, height=900, drawFn=drawFancyWheels)

def testMostFrequentDigit():
    print('Testing mostFrequentDigit()...', end='')
    assert mostFrequentDigit(0) == 0
    assert mostFrequentDigit(1223) == 2
    assert mostFrequentDigit(12233) == 2
    assert mostFrequentDigit(-12233) == 2
    assert mostFrequentDigit(1223322332) == 2
    assert mostFrequentDigit(123456789) == 1
    assert mostFrequentDigit(1234567789) == 7
    assert mostFrequentDigit(1000123456789) == 0
    print('Passed.')

def testNthPalindromicPrime():
    print('Testing nthPalindromicPrime()...', end='')
    assert nthPalindromicPrime(0) == 2
    assert nthPalindromicPrime(4) == 11
    assert nthPalindromicPrime(10) == 313
    assert nthPalindromicPrime(15) == 757
    assert nthPalindromicPrime(20) == 10301
    print('Passed.')

def testCarrylessAdd():
    print('Testing carrylessAdd()... ', end='')
    assert(carrylessAdd(785, 376) == 51)
    assert(carrylessAdd(0, 376) == 376)
    assert(carrylessAdd(785, 0) == 785)
    assert(carrylessAdd(30, 376) == 306)
    assert(carrylessAdd(785, 30) == 715)
    assert(carrylessAdd(12345678900, 38984034003) == 40229602903)
    print('Passed.')

def f1(x): return 42
def i1(x): return 42*x
def f2(x): return 2*x  + 1
def i2(x): return x**2 + x
def f3(x): return 9*x**2
def i3(x): return 3*x**3
def f4(x): return math.cos(x)
def i4(x): return math.sin(x)
def testIntegral():
    print('Testing integral()...', end='')
    epsilon = 10**-4
    assert(almostEqual(integral(f1, -5, +5, 1), (i1(+5)-i1(-5)),
                      epsilon=epsilon))
    assert(almostEqual(integral(f1, -5, +5, 10), (i1(+5)-i1(-5)),
                      epsilon=epsilon))
    assert(almostEqual(integral(f2, 1, 2, 1), 4,
                      epsilon=epsilon))
    assert(almostEqual(integral(f2, 1, 2, 250), (i2(2)-i2(1)),
                      epsilon=epsilon))
    assert(almostEqual(integral(f3, 4, 5, 250), (i3(5)-i3(4)),
                      epsilon=epsilon))
    assert(almostEqual(integral(f4, 1, 2, 250), (i4(2)-i4(1)),
                      epsilon=epsilon))
    print("Passed!")

def testNthWithProperty309():
    print('Testing nthWithProperty309()... ', end='')
    assert(nthWithProperty309(0) == 309)
    assert(nthWithProperty309(1) == 418)
    assert(nthWithProperty309(2) == 462)
    assert(nthWithProperty309(3) == 474)
    print("Passed!")

def testNthCircularPrime():
    print('Testing nthCircularPrime()...', end='')
    # [2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113,
    #  131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, ...]
    assert(nthCircularPrime(0) == 2)
    assert(nthCircularPrime(5) == 13)
    assert(nthCircularPrime(10) == 73)
    assert(nthCircularPrime(15) == 197)
    assert(nthCircularPrime(20) == 719)
    assert(nthCircularPrime(25) == 1193)
    print('Passed!')

def testFindZeroWithBisection():
    print('Testing findZeroWithBisection()... ', end='')
    def f1(x): return x*x - 2 # root at x=sqrt(2)
    x = findZeroWithBisection(f1, 0, 2, 0.000000001)
    assert(almostEqual(x, 1.41421356192))
    def f2(x): return x**2 - (x + 1)  # root at x=phi
    x = findZeroWithBisection(f2, 0, 2, 0.000000001)
    assert(almostEqual(x, 1.61803398887))
    def f3(x): return x**5 - 2**x # f(1)<0, f(2)>0
    x = findZeroWithBisection(f3, 1, 2, 0.000000001)
    assert(almostEqual(x, 1.17727855081))
    print('Passed.')

def testNthSmithNumber():
    print('Testing nthSmithNumber()... ', end='')
    assert(nthSmithNumber(0) == 4)
    assert(nthSmithNumber(1) == 22)
    assert(nthSmithNumber(2) == 27)
    assert(nthSmithNumber(3) == 58)
    assert(nthSmithNumber(4) == 85)
    assert(nthSmithNumber(5) == 94)
    print('Passed.')

def testCarrylessMultiply():
    print("Testing carrylessMultiply()...", end="")
    assert(carrylessMultiply(643, 59) == 417)
    assert(carrylessMultiply(6412, 387) == 807234)
    print("Passed!")

def testNthKaprekarNumber():
    print('Testing nthKaprekarNumber()...', end='')
    assert(nthKaprekarNumber(0) == 1)
    assert(nthKaprekarNumber(1) == 9)
    assert(nthKaprekarNumber(2) == 45)
    assert(nthKaprekarNumber(3) == 55)
    assert(nthKaprekarNumber(4) == 99)
    assert(nthKaprekarNumber(5) == 297)
    assert(nthKaprekarNumber(6) == 703)
    assert(nthKaprekarNumber(7) == 999)
    print('Passed.')

def testNthCarolPrime():
    print("Testing nthCarolPrime()...", end='')
    assert(nthCarolPrime(0) == 7)
    assert(nthCarolPrime(1) == 47)
    assert(nthCarolPrime(2) == 223)
    assert(nthCarolPrime(3) == 3967)
    assert(nthCarolPrime(6) == 16769023)
    assert(nthCarolPrime(8) == 68718952447)
    assert(nthCarolPrime(9) == 274876858367)
    print("Passed!")

def testPlay112():
    print("Testing play112()... ", end="")
    assert(play112( 5 ) == "88888: Unfinished!")
    assert(play112( 521 ) == "81888: Unfinished!")
    assert(play112( 52112 ) == "21888: Unfinished!")
    assert(play112( 5211231 ) == "21188: Unfinished!")
    assert(play112( 521123142 ) == "21128: Player 2 wins!")
    assert(play112( 521123151 ) == "21181: Unfinished!")
    assert(play112( 52112315142 ) == "21121: Player 1 wins!")
    assert(play112( 523 ) == "88888: Player 1: move must be 1 or 2!")
    assert(play112( 51223 ) == "28888: Player 2: move must be 1 or 2!")
    assert(play112( 51211 ) == "28888: Player 2: occupied!")
    assert(play112( 5122221 ) == "22888: Player 1: occupied!")
    assert(play112( 51261 ) == "28888: Player 2: offboard!")
    assert(play112( 51122324152 ) == "12212: Tie!")
    print("Passed!")

def testLengthEncode():
    print('Testing lengthEncode()...', end='')
    assert(lengthEncode(789) == 113789)
    assert(lengthEncode(-789) == 213789)
    assert(lengthEncode(1234512345) == 12101234512345)
    assert(lengthEncode(-1234512345) == 22101234512345)
    assert(lengthEncode(0) == 1110)
    print('Passed!')

def testLengthDecode():
    print('Testing lengthDecode()...', end='')
    assert(lengthDecode(113789) == 789)
    assert(lengthDecode(213789) == -789)
    assert(lengthDecode(12101234512345) == 1234512345)
    assert(lengthDecode(22101234512345) == -1234512345)
    assert(lengthDecode(1110) == 0)
    print('Passed!')

def testLengthDecodeLeftmostValue():
    print('Testing lengthDecodeLeftmostValue()...', end='')
    assert(lengthDecodeLeftmostValue(111211131114) == (2, 11131114))
    assert(lengthDecodeLeftmostValue(112341115) == (34, 1115))
    assert(lengthDecodeLeftmostValue(111211101110) == (2, 11101110))
    assert(lengthDecodeLeftmostValue(11101110) == (0, 1110))
    print('Passed!')

def testIntList():
    print('Testing intList functions...', end='')
    a1 = newIntList()
    assert(a1 == 1110) # length-encoded 0
    assert(intListLen(a1) == 0)
    assert(intListGet(a1, 0) == 'index out of range')

    a1 = intListAppend(a1, 42)
    assert(a1 == 111111242) # [1, 42]
    assert(intListLen(a1) == 1)
    assert(intListGet(a1, 0) == 42)
    assert(intListGet(a1, 1) == 'index out of range')
    assert(intListSet(a1, 1, 99) == 'index out of range')

    a1 = intListSet(a1, 0, 567)
    assert(a1 == 1111113567) # [1, 567]
    assert(intListLen(a1) == 1)
    assert(intListGet(a1, 0) == 567)

    a1 = intListAppend(a1, 8888)
    a1 = intListSet(a1, 0, 9)
    assert(a1 == 111211191148888) # [1, 9, 8888]
    assert(intListLen(a1) == 2)
    assert(intListGet(a1, 0) == 9)
    assert(intListGet(a1, 1) == 8888)

    a1, poppedValue = intListPop(a1)
    assert(poppedValue == 8888)
    assert(a1 == 11111119) # [1, 9]
    assert(intListLen(a1) == 1)
    assert(intListGet(a1, 0) == 9)
    assert(intListGet(a1, 1) == 'index out of range')

    a2 = newIntList()
    a2 = intListAppend(a2, 0)
    assert(a2 == 11111110)
    a2 = intListAppend(a2, 0)
    assert(a2 == 111211101110)
    print('Passed!')

def testIntSet():
    print('Testing intSet functions...', end='')
    s = newIntSet()
    assert(s == 1110) # [ 0 ]
    assert(intSetContains(s, 42) == False)
    s = intSetAdd(s, 42)
    assert(s == 111111242) # [ 1, 42]
    assert(intSetContains(s, 42) == True)
    s = intSetAdd(s, 42) # multiple adds --> still just one
    assert(s == 111111242) # [ 1, 42]
    assert(intSetContains(s, 42) == True)
    print('Passed!')

def testIntMap():
    print('Testing intMap functions...', end='')
    m = newIntMap()
    assert(m == 1110) # [ 0 ]
    assert(intMapContains(m, 42) == False)
    assert(intMapGet(m, 42) == 'no such key')
    m = intMapSet(m, 42, 73)
    assert(m == 11121124211273) # [ 2, 42, 73 ]
    assert(intMapContains(m, 42) == True)
    assert(intMapGet(m, 42) == 73)
    m = intMapSet(m, 42, 98765)
    assert(m == 11121124211598765) # [ 2, 42, 98765 ]
    assert(intMapGet(m, 42) == 98765)
    m = intMapSet(m, 99, 0)
    assert(m == 11141124211598765112991110) # [ 4, 42, 98765, 99, 0 ]
    assert(intMapGet(m, 42) == 98765)
    assert(intMapGet(m, 99) == 0)
    print('Passed!')

def testIntFSM():
    print('Testing intFSM functions...', end='')
    fsm = newIntFSM()
    assert(fsm == 111211411101141110) # [ empty stateMap, empty startStateSet ]
    assert(isAcceptingState(fsm, 1) == False)

    fsm = addAcceptingState(fsm, 1)
    assert(fsm == 1112114111011811111111)
    assert(isAcceptingState(fsm, 1) == True)

    assert(getTransition(fsm, 0, 8) == 'no such transition')
    fsm = setTransition(fsm, 4, 5, 6)
    # map[5] = 6: 111211151116
    # map[4] = (map[5] = 6):  111211141212111211151116
    assert(fsm == 1112122411121114121211121115111611811111111)
    assert(getTransition(fsm, 4, 5) == 6)

    fsm = setTransition(fsm, 4, 7, 8)
    fsm = setTransition(fsm, 5, 7, 9)
    assert(getTransition(fsm, 4, 5) == 6)
    assert(getTransition(fsm, 4, 7) == 8)
    assert(getTransition(fsm, 5, 7) == 9)

    fsm = newIntFSM()
    assert(fsm == 111211411101141110) # [ empty stateMap, empty startStateSet ]
    fsm = setTransition(fsm, 0, 5, 6)
    # map[5] = 6: 111211151116
    # map[0] = (map[5] = 6):  111211101212111211151116
    assert(fsm == 111212241112111012121112111511161141110)
    assert(getTransition(fsm, 0, 5) == 6)

    print('Passed!')

def testAccepts():
    print('Testing accepts()...', end='')
    fsm = newIntFSM()
    # fsm accepts 6*7+8
    fsm = addAcceptingState(fsm, 3)
    fsm = setTransition(fsm, 1, 6, 1) # 6* -> 1
    fsm = setTransition(fsm, 1, 7, 2) # 7 -> 2
    fsm = setTransition(fsm, 2, 7, 2) # 7* -> 2
    fsm = setTransition(fsm, 2, 8, 3) # 7* -> 3
    assert(accepts(fsm, 78) == True)
    assert(states(fsm, 78) == 1113111111121113) # [1,2,3]
    assert(accepts(fsm, 678) == True)
    assert(states(fsm, 678) == 11141111111111121113) # [1,1,2,3]

    assert(accepts(fsm, 5) == False)
    assert(accepts(fsm, 788) == False)
    assert(accepts(fsm, 67) == False)
    assert(accepts(fsm, 666678) == True)
    assert(accepts(fsm, 66667777777777778) == True)
    assert(accepts(fsm, 7777777777778) == True)
    assert(accepts(fsm, 666677777777777788) == False)
    assert(accepts(fsm, 77777777777788) == False)
    assert(accepts(fsm, 7777777777778) == True)
    assert(accepts(fsm, 67777777777778) == True)
    print('Passed!')

def testEncodeDecodeStrings():
    print('Testing encodeString and decodeString...', end='')
    assert(encodeString('A') == 111111265) # [1, 65]
    assert(encodeString('f') == 1111113102) # [1, 102]
    assert(encodeString('3') == 111111251) # [1, 51]
    assert(encodeString('!') == 111111233) # [1, 33]
    assert(encodeString('Af3!') == 1114112651131021125111233) # [4,65,102,51,33]
    assert(decodeString(111111265) == 'A')
    assert(decodeString(1114112651131021125111233) == 'Af3!')
    assert(decodeString(encodeString('WOW!!!')) == 'WOW!!!')
    print('Passed!')

def testIntegerDataStructures():
    testLengthEncode()
    testLengthDecode()
    testLengthDecodeLeftmostValue()
    testIntList()
    testIntSet()
    testIntMap()
    testIntFSM()
    testAccepts()
    testEncodeDecodeStrings()

#################################################
# testAll and main
#################################################

def testAll():
    # comment out the tests you do not wish to run!
    # required

    testDrawFancyWheels()

    # mild
    testMostFrequentDigit()
    testNthPalindromicPrime()
    testCarrylessAdd()
    testIntegral()
    testNthWithProperty309()
    testNthCircularPrime()

    # medium
    testFindZeroWithBisection()
    testNthSmithNumber()
    testCarrylessMultiply()
    testNthKaprekarNumber()
    testNthCarolPrime()

    # spicy
    testPlay112()
    testIntegerDataStructures()

def main():
    cs112_s20_unit2_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
