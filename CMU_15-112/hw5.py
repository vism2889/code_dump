#################################################
# hw5.py
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
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

class CokeMachine(object):

    def __init__(self, numBottles, costPerBottle):
        # constructor that takes number of bottles and
        # the price per bottle as arguments
        self.bottleCount = numBottles
        self.bottleCost = costPerBottle
        self.paidValue = 0
        self.owe = 0 # initializes at zero
        self.owe += self.bottleCost # then adds cost of current bottle cost

    def getBottleCount(self):
        # returns the number of bottles left in the machine
        return self.bottleCount

    def isEmpty(self):
        # returns True if the amount of bottles is zero
        # returns False if the machine still has bottles left for sale
        if self.bottleCount > 0:
            return False
        else:
            return True

    def getBottleCost(self):
        # returns the price of a bottle
        return self.bottleCost

    def getPaidValue(self):
        # returns the amount of money the machine has made so far
        return self.bottleCost - self.owe

    def insert(self,amount):
        # inserts money into the machine for a purchase
        if self.bottleCount > 0:
            self.owe -= amount
            if self.owe > 0:
                return -1
            if self.owe == 0:
                self.owe += self.bottleCost
                self.bottleCount -= 1
                return 0
            if self.owe < 0:
                # stores value for change if we overpaid
                change = abs(self.owe)
                # sets what we owe to zero because the transaction is over
                # then adds the cost of a bottle to signify a new transaction
                self.owe = 0
                self.owe += self.bottleCost
                self.bottleCount -=1
                return change
        else:
            # Returns -999 to signal that the coke machine is empty
            return -999

    def stillOwe(self):
        # returns the amount still owed for present transaction
        # if machine is not empty
        return self.owe

    def addBottles(self, numBottles):
        # adds more bottles to the coke machine
        self.bottleCount += numBottles

    pass

#################################################
#           isKingsTour(board)
#################################################


def hasNoZero(board):
    # Ensures there is not a zero on the board, as that is not a
    # legal value in this problem
    rows = len(board)
    cols = len(board[0])
    for row in range(rows):
        for col in range(cols):
            if board[row][col] == 0:
                return False
    return True

def findStart(board,currVal):
    # Finds the column and row positions of a number in a board
    # Used to find the start position, then every position after that
    rows = len(board)
    cols = len(board[0])
    startRow = None
    startCol = None
    for row in range(rows):
        for col in range(cols):
            if board[row][col] == currVal:
                startRow = row
                startCol = col
    return(startRow, startCol)

def hasNeighbors(board,currVal, startRow, startCol):
    # Compares the current position with the position of the next valid
    # value and ensures that that position is somehow neighboring our
    # current value
    currVal = currVal
    while currVal != len(board)**2:
        nextNum = findStart(board, currVal+1)
        if nextNum == (startRow + 1,startCol + 1) or \
            nextNum == (startRow - 1, startCol - 1) or \
            nextNum == (startRow - 1, startCol + 1) or \
            nextNum == (startRow + 1, startCol - 1) or \
            nextNum == (startRow, startCol - 1) or \
            nextNum == (startRow, startCol + 1) or \
            nextNum == (startRow + 1, startCol) or \
            nextNum == (startRow - 1, startCol):
                currVal += 1
                startRow, startCol = nextNum
        else:
            return False
    if currVal == len(board)**2:
        return True
    else:
        return False

def isKingsTour(board):
    # Tests to see if a provided kings tour board is a legal one.
    if hasNoZero(board):
        startVal = 1
        startRow, startCol = findStart(board, startVal)
        if hasNeighbors(board, startVal, startRow, startCol):
            return True
    return False



#################################################
#           isLegalSodoku() + helpers
#################################################

def areLegalValues(values):
    # tests if a list of values is legal for a given sodoku board size
    length = len(values)
    count = 0
    for i in range(1,length+1):
        if values[i-1] == 0:
            count += 1
        if i in values and values.count(i) == 1:
            count += 1
    if count == length:
        return True
    else:
        return False

def isLegalRow(board,row):
    # tests if a single row is a legal for a given sodoku board size
    maybeLegalRow = board[row]
    if areLegalValues(maybeLegalRow):
        return True
    else:
        return False


def isLegalCol(board, col):
    # tests if a single col is a legal for a given sodoku board size
    colList = []
    for i in range(len(board)):
        colList += [board[i][col]]
    if areLegalValues(colList):
        return True
    else:
        return False

def isLegalBlock(board, block):
    # tests if a single block is a legal for a given sodoku board size
    rows = int(len(board)**0.5)
    cols = int(len(board)**0.5)
    startRow = block * rows
    startCol = block * cols
    blockList = []
    for row in range(startRow, rows):
        for col in range(startCol, cols):
            blockList += [board[row][col]]
    if areLegalValues(blockList):
        return True
    else:
        return False

def isLegalSudoku(board):
    # tests if the given board is a legal sodoku board
    rows = len(board)
    cols = len(board)
    blocks = int(len(board)**0.5)
    for block in range(blocks):
        if not isLegalBlock(board, block):
            return False
    for row in range(rows):
        if not isLegalRow(board, row):
            return False

    for col in range(cols):
        if not isLegalCol(board, col):
            return False
    return True

#################################################
#           playSimplifiedChess + helpers
#################################################
# Taken from: https://www.cs.cmu.edu/~112/notes/notes-2d-lists.html#printing
# Helper function for print2dList.

def maxItemLength(a):
    maxLen = 0
    rows = len(a)
    cols = len(a[0])
    for row in range(rows):
        for col in range(cols):
            maxLen = max(maxLen, len(str(a[row][col])))
    return maxLen

def print2dList(a):
    if (a == []):
        # So we don't crash accessing a[0]
        print([])
        return
    rows = len(a)
    cols = len(a[0])
    fieldWidth = maxItemLength(a)
    print("[ ", end="")
    for row in range(rows):
        if (row > 0): print("\n  ", end="")
        print("[ ", end="")
        for col in range(cols):
            if (col > 0): print(", ", end="")
            # The next 2 lines print a[row][col] with the given fieldWidth
            formatSpec = "%" + str(fieldWidth) + "s"
            print(formatSpec % str(a[row][col]), end="")
        print(" ]", end="")
    print("]")

class Pawn(object):
    pass

class King(object):
    pass

class Queen(object):
    pass

class Rook(object):
    pass

class Bishop(object):
    pass

class Knight(object):
    pass

class Player(object):
    pass

# R = rook/castle, KT = knight, B = bishop, K = king, Q = queen
import curses
def playSimplifiedChess():
    rows = 7
    cols = 8
    board = [([0]* cols) for row in range(rows)]


    startPosPawn = ['PAWN','PAWN','PAWN','PAWN','PAWN','PAWN','PAWN','PAWN']
    startPosOthers = ['ROOK','KNIGHT','BISHOP','QUEEN',
                        'KING','BISHOP','KNIGHT','ROOK']
    board[0] = [] + startPosOthers
    board[1] = [] + startPosPawn
    board[6] = [] + startPosOthers
    board[5] = [] + startPosPawn
    print2dList(board)

    # put your answer here if you do this problem!

    return 42

#################################################
# Test Functions
#################################################

def testCokeMachineClass():
    print('Testing CokeMachine class...', end='')
    cm1 = CokeMachine(100, 125) # make a CokeMachine holding 100 bottles
                                # that each cost 125 cents ($1.25)
    assert(cm1.getBottleCount() == 100)
    assert(cm1.isEmpty() == False)
    assert(cm1.getBottleCost() == 125)  # $1.25 (125 cents)
    assert(cm1.getPaidValue() == 0)     # starts with no coins inserted

    # insert a dollar
    change = cm1.insert(100)  # we paid $1.00, it costs $1.25, so change == -1
                              # to indicate that not only is there no change,
                              # but we still owe money
    assert(change == -1)
    assert(cm1.stillOwe() == 25)

    # insert a dime more
    change = cm1.insert(10)
    assert(change == -1)
    assert(cm1.stillOwe() == 15)

    # and insert a quarter more.  Here, we finally pay enough, so we get a
    # bottle and some change!
    change = cm1.insert(25)
    assert(change == 10)
    assert(cm1.stillOwe() == 125)      # this is for the NEXT bottle
    assert(cm1.getBottleCount() == 99) # because we just got one!

    # second instance
    cm2 = CokeMachine(2, 50) # 2 bottles, $0.50 each

    # buy a couple bottles
    change = cm2.insert(25)
    assert(change == -1)
    assert(cm2.stillOwe() == 25)
    change = cm2.insert(25)
    assert(change == 0) # bought with exact change
    assert(cm2.isEmpty() == False)
    assert(cm2.getBottleCount() == 1)
    change = cm2.insert(100) # overpaid by $0.50
    assert(change == 50)
    assert(cm2.isEmpty() == True)
    assert(cm2.getBottleCount() == 0)

    # cannot buy anything more -- the machine is empty.
    # this is signified by returning -999 as the change
    change = cm2.insert(50)
    assert(change == -999)
    assert(cm2.isEmpty() == True)
    assert(cm2.getBottleCount() == 0)

    # addBottles method
    cm2.addBottles(50)
    assert(cm2.isEmpty() == False)
    assert(cm2.getBottleCount() == 50)
    change = cm2.insert(50)
    assert(change == 0)
    assert(cm2.getBottleCount() == 49)

    # independence of two instances
    assert(cm1.getBottleCount() == 99)
    assert(cm2.getBottleCount() == 49)

    print('Passed')

def testIsKingsTour():
    print("Testing isKingsTour()...", end="")
    a = [ [  3, 2, 1 ],
          [  6, 4, 9 ],
          [  5, 7, 8 ] ]
    assert(isKingsTour(a) == True)
    a = [ [  2, 8, 9 ],
          [  3, 1, 7 ],
          [  4, 5, 6 ] ]
    assert(isKingsTour(a) == True)
    a = [ [  7, 5, 4 ],
          [  6, 8, 3 ],
          [  1, 2, 9 ] ]
    assert(isKingsTour(a) == True)
    a = [ [  7, 5, 4 ],
          [  6, 8, 3 ],
          [  1, 2, 1 ] ]
    assert(isKingsTour(a) == False)
    a = [ [  3, 2, 9 ],
          [  6, 4, 1 ],
          [  5, 7, 8 ] ]
    assert(isKingsTour(a) == False)
    a = [ [  3, 2, 1 ],
          [  6, 4, 0 ],
          [  5, 7, 8 ] ]
    assert(isKingsTour(a) == False)
    a = [ [  1, 2, 3 ],
          [  7, 4, 8 ],
          [  6, 5, 9 ] ]
    assert(isKingsTour(a) == False)
    a = [ [ 3, 2, 1 ],
          [ 6, 4, 0 ],
          [ 5, 7, 8 ] ]
    assert(isKingsTour(a) == False)
    print("Passed!")

def testIsLegalSudoku():
    # From Leon Zhang!
    print("Testing isLegalSudoku()...", end="")
    board = [[0]]
    assert isLegalSudoku(board) == True
    board = [[1]]
    assert isLegalSudoku(board) == True

    board = [[0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0]]
    assert isLegalSudoku(board) == True
    board = [[0, 4, 0, 0],
             [0, 0, 3, 0],
             [1, 0, 0, 0],
             [0, 0, 0, 2]]
    assert isLegalSudoku(board) == True
    board = [[1, 2, 3, 4],
             [3, 4, 1, 2],
             [2, 1, 4, 3],
             [4, 3, 2, 1]]
    assert isLegalSudoku(board) == True
    board = [[1, 2, 3, 4],
             [3, 4, 4, 2],
             [2, 4, 4, 3],
             [4, 3, 2, 1]]
    assert isLegalSudoku(board) == False

    board = [
    [ 5, 3, 0, 0, 7, 0, 0, 0, 0 ],
    [ 6, 0, 0, 1, 9, 5, 0, 0, 0 ],
    [ 0, 9, 8, 0, 0, 0, 0, 6, 0 ],
    [ 8, 0, 0, 0, 6, 0, 0, 0, 3 ],
    [ 4, 0, 0, 8, 0, 3, 0, 0, 1 ],
    [ 7, 0, 0, 0, 2, 0, 0, 0, 6 ],
    [ 0, 6, 0, 0, 0, 0, 2, 8, 0 ],
    [ 0, 0, 0, 4, 1, 9, 0, 0, 5 ],
    [ 0, 0, 0, 0, 8, 0, 0, 7, 9 ]
    ]
    assert isLegalSudoku(board) == True

    board = [
    [ 5, 3, 0, 0, 7, 0, 0, 0, 0 ],
    [ 6, 0, 0, 1, 9, 5, 0, 0, 0 ],
    [ 0, 9, 8, 0, 0, 0, 0, 6, 0 ],
    [ 8, 0, 0, 0, 6, 0, 0, 0, 3 ],
    [ 4, 0, 0, 8, 0, 3, 0, 0, 1 ],
    [ 7, 0, 0, 0, 2, 0, 0, 0, 6 ],
    [ 0, 6, 0, 0, 0, 0, 2, 8, 0 ],
    [ 0, 0, 0, 4, 1, 9, 0, 0, 5 ],
    [ 0, 0, 0, 0, 8, 0, 9, 7, 9 ]
    ]
    assert isLegalSudoku(board) == False
    board = [
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    assert isLegalSudoku(board) == True
    board = [
    [ 2,11, 9, 5, 8,16,13, 4,12, 3,14, 7,10, 6,15, 1],
    [ 4,12,15,10, 3, 6, 9,11,13, 5, 8, 1,16, 7,14, 2],
    [ 1,14, 6, 7,15, 2, 5,12,11, 9,10,16, 3,13, 8, 4],
    [16,13, 8, 3,14, 1,10, 7, 4, 6, 2,15, 9,11, 5,12],
    [12, 2,16, 9,10,14,15,13, 8, 1, 5, 3, 6, 4,11, 7],
    [ 6, 7, 1,11, 5,12, 8,16, 9,15, 4, 2,14,10, 3,13],
    [14, 5, 4,13, 6,11, 1, 3,16,12, 7,10, 8, 9, 2,15],
    [ 3, 8,10,15, 4, 7, 2, 9, 6,14,13,11, 1,12,16, 5],
    [13, 9, 2,16, 7, 8,14,10, 3, 4,15, 6,12, 5, 1,11],
    [ 5, 4,14, 6, 2,13,12, 1,10,16,11, 8,15, 3, 7, 9],
    [ 7, 1,11,12,16, 4, 3,15, 5,13, 9,14, 2, 8,10, 6],
    [10,15, 3, 8, 9, 5,11, 6, 2, 7, 1,12, 4,14,13,16],
    [11,10,13,14, 1, 9, 7, 8,15, 2, 6, 4, 5,16,12, 3],
    [15, 3, 7, 4,12,10, 6, 5, 1, 8,16,13,11, 2, 9,14],
    [ 8, 6, 5, 1,13, 3,16, 2,14,11,12, 9, 7,15, 4,10],
    [ 9,16,12, 2,11,15, 4,14, 7,10, 3, 5,13, 1, 6, 8]]
    assert isLegalSudoku(board) == True
    # last number is supposed to be 8, not 10
    board = [
    [ 2,11, 9, 5, 8,16,13, 4,12, 3,14, 7,10, 6,15, 1],
    [ 4,12,15,10, 3, 6, 9,11,13, 5, 8, 1,16, 7,14, 2],
    [ 1,14, 6, 7,15, 2, 5,12,11, 9,10,16, 3,13, 8, 4],
    [16,13, 8, 3,14, 1,10, 7, 4, 6, 2,15, 9,11, 5,12],
    [12, 2,16, 9,10,14,15,13, 8, 1, 5, 3, 6, 4,11, 7],
    [ 6, 7, 1,11, 5,12, 8,16, 9,15, 4, 2,14,10, 3,13],
    [14, 5, 4,13, 6,11, 1, 3,16,12, 7,10, 8, 9, 2,15],
    [ 3, 8,10,15, 4, 7, 2, 9, 6,14,13,11, 1,12,16, 5],
    [13, 9, 2,16, 7, 8,14,10, 3, 4,15, 6,12, 5, 1,11],
    [ 5, 4,14, 6, 2,13,12, 1,10,16,11, 8,15, 3, 7, 9],
    [ 7, 1,11,12,16, 4, 3,15, 5,13, 9,14, 2, 8,10, 6],
    [10,15, 3, 8, 9, 5,11, 6, 2, 7, 1,12, 4,14,13,16],
    [11,10,13,14, 1, 9, 7, 8,15, 2, 6, 4, 5,16,12, 3],
    [15, 3, 7, 4,12,10, 6, 5, 1, 8,16,13,11, 2, 9,14],
    [ 8, 6, 5, 1,13, 3,16, 2,14,11,12, 9, 7,15, 4,10],
    [ 9,16,12, 2,11,15, 4,14, 7,10, 3, 5,13, 1, 6,10]]
    assert isLegalSudoku(board) == False
    print("Passed!")

#################################################
# testAll and main
#################################################

def testAll():
    # required
    testCokeMachineClass()

    # mild
    testIsKingsTour()

    # medium
    testIsLegalSudoku()

    # spicy
    # Note that playSimplifiedChess is manually graded
    # so there is no test function for it.
    #playSimplifiedChess()

def main():
    cs112_s20_unit5_linter.lint()
    testAll()

if __name__ == '__main__':
    main()
