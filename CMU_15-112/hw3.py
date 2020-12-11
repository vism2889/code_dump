#################################################
# hw3.py
#
# Your name:
# Your andrew id:
#################################################

import cs112_s20_unit3_linter
import basic_graphics
import string, copy, random
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

def topScorer(data):
    '''
    Returns name of top scorer, or multiples names if there is a tie.
    Return players names in order they origally appeared in if multiple.
    Return None if nobody wins
    '''
    if len(data) < 1: return None
    topScorer = "None"
    topScore = 0
    scorer = ""
    score = 0
    for line in data.splitlines(): # iterate over lines
        score = 0
        for part in line.split(','): # iterate over elements in line
            if part.isalpha():
                scorer = part
            if part.isdigit():
                score = score + int(part)
        if score > topScore:
            topScorer = scorer
            topScore = score

        elif score == topScore:
            topScorer = topScorer + ("," + scorer)

            topScore = score
        elif score == 0:
            topScorer = None
        else:
            pass

    return topScorer

def sepLines(text, width):

    return 42

def wordWrap(text, width):
    '''
    Takes a string and firstly replaces all spaces with dashes, then
    puts a new line after so many characters, determined by the width parameter
    '''
    result = ''
    if len(text) <= width:
        return text
    while len(text):
        tmp = text[:width].strip()
        tmp = tmp.replace(" ", "-")
        result += tmp + '\n'
        text = text[width:]
    result = result.strip()

    return result





def isPalindrome(s):
    '''Compares reversed string with s'''
    if s[::-1] == s:
        return True
    else:
        return False

def longestSubpalindrome(s):
    '''should return the longest substring palindrome
    if two substring palindromes are equal in length
    the lexigraphically larger of the values will be returned
    '''

    best = ''
    for i in range(len(s)):
        for j in range(i,len(s)+1):
            sub = s[i:j]
            print(sub)
            if (isPalindrome(sub) and \
                    len(sub) > len(best)) or \
                    (isPalindrome(sub) and \
                    len(sub) == len(best) and \
                    sub > best):
                best = sub
    #print(best)
    return best



def formatMessage(exactMatches, partialMatches):
    '''
    formats return message for mastermindScore()
    '''

    message = ''

    if exactMatches == 1 and partialMatches == 1:
        message = ("%d exact match, %d partial match"
                    % (exactMatches, partialMatches))
    elif exactMatches == 1 and partialMatches > 1:
        message = ("%d exact match, %d partial matches"
                    % (exactMatches, partialMatches))
    elif exactMatches > 1 and partialMatches == 1:
        message = ("%d exact matches, %d partial match"
                    % (exactMatches, partialMatches))
    elif exactMatches > 1 and partialMatches > 1:
        message = ("%d exact matches, %d partial matches"
                    % (exactMatches, partialMatches))

    elif exactMatches == 0 and partialMatches == 1:
        message = ("%d partial match" % (partialMatches))

    elif exactMatches == 0 and partialMatches > 1:
        message = ("%d partial matches" % (partialMatches))

    elif exactMatches == 1 and partialMatches == 0:
        message = ("%d exact match" % (exactMatches))

    elif exactMatches > 1 and partialMatches == 0:
        message = ("%d exact matches" % (exactMatches))

    else:
        message = ("No matches")
    return message

def mastermindScore(target, guess):
    outputMessage = ''
    exactMatches = 0
    partialMatches = 0
    # guessTracker prevents an exact match from also
    # being counted as a partial match
    guessTracker = ''
    if target == guess:
        return "You win!!!"
    for i in range(len(target)):
        if guess[i] == target[i]:
            exactMatches +=1
            guessTracker += guess[i]

        elif (guess[i] in target) and \
            (guess[i] != target[i]) and \
            (guess[i] not in guessTracker):
            partialMatches +=1
            guessTracker += guess[i]
        else:
            continue
    outputMessage = formatMessage(exactMatches,partialMatches)
    return outputMessage

def evalHand(hand):
    return 42

def playPoker(deck, players):
    return 42

def encodeRightLeftRouteCipher(text, rows):
    return 42

def decodeRightLeftRouteCipher(cipher):
    return 42

def topLevelFunctionNames(code):
    return 42

def getEvalSteps(expr):
    return 42

def bonusEncode1(msg):
    return 42

def funDecode1(msg):
    return 42

def bonusEncode2(msg):
    return 42

def funDecode2(msg):
    return 42

def bonusEncode3(msg):
    return 42

def funDecode3(msg):
    return 42

#################################################
# Test Functions
#################################################

def testTopScorer():
    print('Testing topScorer()...', end='')
    data = '''\
Fred,10,20,30,40
Wilma,10,20,30
'''
    assert(topScorer(data) == 'Fred')

    data = '''\
Fred,10,20,30
Wilma,10,20,30,40
'''
    assert(topScorer(data) == 'Wilma')

    data = '''\
Fred,11,20,30
Wilma,10,20,30,1
'''
    assert(topScorer(data) == 'Fred,Wilma')

    data = '''\
Betty,0,0,0,0
Pebbles,0,0,0,0,123,0
Fred,11,20,30
Wilma,10,20,30,1
Barney,123
BamBam,120,1,1,0,1
'''
    assert(topScorer(data)=='Pebbles,Barney,BamBam')
    assert(topScorer('') == None)
    print('Passed!')

def testWordWrap():
    print('Testing wordWrap()...', end='')
    assert(wordWrap("abc", 3) == "abc")
    assert(wordWrap("abc",2) == "ab\nc")
    assert(wordWrap("abcdefghij", 4)  ==  """\
abcd
efgh
ij""")
    assert(wordWrap("a b c de fg",  4)  ==  """\
a-b
c-de
fg""")

    assert(wordWrap('a b c def  g h  ', 4) == """\
a-b
c-de
f--g
h""")
    print('Passed!')

def testLongestSubpalindrome():
    print("Testing longestSubpalindrome()...", end="")
    assert(longestSubpalindrome("ab-4-be!!!") == "b-4-b")
    assert(longestSubpalindrome("abcbce") == "cbc")
    assert(longestSubpalindrome("aba") == "aba")
    assert(longestSubpalindrome("a") == "a")
    print("Passed!")

def testMastermindScore():
    print("Testing mastermindScore()...", end="")
    assert(mastermindScore('abcd', 'aabd') ==
                           '2 exact matches, 1 partial match')
    assert(mastermindScore('efgh', 'abef') ==
                           '2 partial matches')
    assert(mastermindScore('efgh', 'efef') ==
                           '2 exact matches')
    assert(mastermindScore('ijkl', 'mnop') ==
                           'No matches')
    assert(mastermindScore('cdef', 'cccc') ==
                           '1 exact match')
    assert(mastermindScore('cdef', 'bccc') ==
                           '1 partial match')
    assert(mastermindScore('wxyz', 'wwwx') ==
                           '1 exact match, 1 partial match')
    assert(mastermindScore('wxyz', 'wxya') ==
                           '3 exact matches')
    assert(mastermindScore('wxyz', 'awxy') ==
                           '3 partial matches')
    assert(mastermindScore('wxyz', 'wxyz') ==
                           'You win!!!')
    assert(mastermindScore('aeiou', 'yaeio') ==
                            '4 partial matches')
    print("Passed!")

def testPlayPoker():
    print('Testing playPoker()...', end='')
    assert(playPoker('QD-3S', 1) == 'Player 1 wins with a high card of QD')
    assert(playPoker('QD-QC', 1) == 'Player 1 wins with a pair to QD')
    assert(playPoker('QD-JS', 1) == 'Player 1 wins with a straight to QD')
    assert(playPoker('TD-QD', 1) == 'Player 1 wins with a flush to QD')
    assert(playPoker('QD-JD', 1) == 'Player 1 wins with a straight flush to QD')
    assert(playPoker('QD-JD', 2) == 'Not enough cards')

    assert(playPoker('AS-2H-3C-4D', 2) ==
                                    'Player 2 wins with a high card of 4D')
    assert(playPoker('5S-2H-3C-4D', 2) ==
                                    'Player 1 wins with a high card of 5S')
    assert(playPoker('AS-2H-3C-2D', 2) == 'Player 2 wins with a pair to 2H')
    assert(playPoker('3S-2H-3C-2D', 2) == 'Player 1 wins with a pair to 3S')
    assert(playPoker('AS-2H-2C-2D', 2) == 'Player 1 wins with a straight to 2C')
    assert(playPoker('AS-2H-2C-3D', 2) == 'Player 2 wins with a straight to 3D')
    assert(playPoker('AS-2H-4S-3D', 2) == 'Player 1 wins with a flush to 4S')
    assert(playPoker('AS-2H-4S-3H', 2) ==
                                    'Player 2 wins with a straight flush to 3H')
    assert(playPoker('2S-2H-3S-3H', 2) ==
                                    'Player 1 wins with a straight flush to 3S')

    assert(playPoker('AS-2D-3C-4C-5H-6D-7S-8D', 2) ==
                                    'Player 2 wins with a high card of 4C')
    assert(playPoker('AS-2D-3S-4C-5H-6D-7S-8D', 4) ==
                                    'Player 3 wins with a flush to 7S')
    print('Passed!')

def testEncodeRightLeftRouteCipher():
    print('Testing encodeRightLeftRouteCipher()...', end='')
    assert(encodeRightLeftRouteCipher("WEATTACKATDAWN",4) ==
                                      "4WTAWNTAEACDzyAKT")
    assert(encodeRightLeftRouteCipher("WEATTACKATDAWN",3) ==
                                      "3WTCTWNDKTEAAAAz")
    assert(encodeRightLeftRouteCipher("WEATTACKATDAWN",5) ==
                                      "5WADACEAKWNATTTz")
    print('Passed!')

def testDecodeRightLeftRouteCipher():
    print('Testing decodeRightLeftRouteCipher()...', end='')
    assert(decodeRightLeftRouteCipher("4WTAWNTAEACDzyAKT") ==
                                      "WEATTACKATDAWN")
    assert(decodeRightLeftRouteCipher("3WTCTWNDKTEAAAAz") ==
                                      "WEATTACKATDAWN")
    assert(decodeRightLeftRouteCipher("5WADACEAKWNATTTz") ==
                                      "WEATTACKATDAWN")
    text = "WEATTACKATDAWN"
    cipher = encodeRightLeftRouteCipher(text, 6)
    plaintext = decodeRightLeftRouteCipher(cipher)
    assert(plaintext == text)
    print('Passed!')

def testEncodeAndDecodeRightLeftRouteCipher():
    testEncodeRightLeftRouteCipher()
    testDecodeRightLeftRouteCipher()

def testTopLevelFunctionNames():
    print("Testing topLevelFunctionNames()...", end="")

    # no fn defined
    code = """\
# This has no functions!
# def f(): pass
print("Hello world!")
"""
    assert(topLevelFunctionNames(code) == "")

    # f is redefined
    code = """\
def f(x): return x+42
def g(x): return x+f(x)
def f(x): return x-42
"""
    assert(topLevelFunctionNames(code) == "f.g")

    # def not at start of line
    code = """\
def f(): return "def g(): pass"
"""
    assert(topLevelFunctionNames(code) == "f")

    # g() is in triple-quotes (''')
    code = """\
def f(): return '''
def g(): pass'''
"""
    assert(topLevelFunctionNames(code) == "f")

    # g() is in triple-quotes (""")
    code = '''\
def f(): return """
def g(): pass"""
'''
    assert(topLevelFunctionNames(code) == "f")

    # triple-quote (''') in comment
    code = """\
def f(): return 42 # '''
def g(): pass # '''
"""
    assert(topLevelFunctionNames(code) == "f.g")

    # triple-quote (""") in comment
    code = '''\
def f(): return 42 # """
def g(): pass # """
'''
    assert(topLevelFunctionNames(code) == "f.g")

    # comment character (#) in quotes
    code = """\
def f(): return '#' + '''
def g(): pass # '''
def h(): return "#" + '''
def i(): pass # '''
def j(): return '''#''' + '''
def k(): pass # '''
"""
    assert(topLevelFunctionNames(code) == "f.h.j")
    print("Passed!")

def testGetEvalSteps():
    print("Testing getEvalSteps()...", end="")
    assert(getEvalSteps("0") == "0 = 0")
    assert(getEvalSteps("2") == "2 = 2")
    assert(getEvalSteps("3+2") == "3+2 = 5")
    assert(getEvalSteps("3-2") == "3-2 = 1")
    assert(getEvalSteps("3**2") == "3**2 = 9")
    assert(getEvalSteps("31%16") == "31%16 = 15")
    assert(getEvalSteps("31*16") == "31*16 = 496")
    assert(getEvalSteps("32//16") == "32//16 = 2")
    assert(getEvalSteps("2+3*4") == "2+3*4 = 2+12\n      = 14")
    assert(getEvalSteps("2*3+4") == "2*3+4 = 6+4\n      = 10")
    assert(getEvalSteps("2+3*4-8**3%3") == """\
2+3*4-8**3%3 = 2+3*4-512%3
             = 2+12-512%3
             = 2+12-2
             = 14-2
             = 12""")
    assert(getEvalSteps("2+3**4%2**4+15//3-8") == """\
2+3**4%2**4+15//3-8 = 2+81%2**4+15//3-8
                    = 2+81%16+15//3-8
                    = 2+1+15//3-8
                    = 2+1+5-8
                    = 3+5-8
                    = 8-8
                    = 0""")
    print("Passed!")

def testFunDecoder(encodeFn, decodeFn):
    s1 = ''
    for c in range(15):
        if (random.random() < 0.80):
            s1 += random.choice(string.ascii_letters)
        else:
            s1 += random.choice(' \n\n') + random.choice(string.digits)
    for s in ['a', 'abc', s1]:
        if (decodeFn(encodeFn(s)) != s):
            raise Exception(f'Error in {decodeFn.__name__} on {repr(s)}')
    return True

def testFunDecoders():
    print('Testing funDecoders()...', end='')
    testFunDecoder(bonusEncode1, funDecode1)
    testFunDecoder(bonusEncode2, funDecode2)
    testFunDecoder(bonusEncode3, funDecode3)
    print('Passed!')

#################################################
# testAll and main
#################################################

def testAll():
    # required
    testTopScorer()

    # mild
    testWordWrap()
    testLongestSubpalindrome()

    # medium
    testMastermindScore()
    testPlayPoker()

    # spicy
    testEncodeAndDecodeRightLeftRouteCipher()
    testTopLevelFunctionNames()
    testGetEvalSteps()
    testFunDecoders()

def main():
    cs112_s20_unit3_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
