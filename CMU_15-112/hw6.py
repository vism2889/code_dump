#################################################
# hw6.py: Tetris!
#
# Your name: Morgan Visnesky
# Your andrew id: mvisnesk
#
#################################################

import cs112_s20_unit6_linter
import math, copy, random

from cmu_112_graphics import *

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
########## Functions for you to write ###########
#################################################

def gameDimensions():
    # Sets size of gameboard, cell size, and margin
    rows = 15
    cols = 10
    cellSize = 20
    margin = 25
    return (rows,cols,cellSize,margin)

def playTetris():
    # Converts given dimensions to height and width needed to display
    # tetris board with margins // screen height and screen width
    dimensions = gameDimensions()
    rows, cols, cellSize, margins = dimensions
    width = cols*cellSize + 2*margins
    height = rows*cellSize + 2*margins
    runApp(width = width, height = height)

def shapes1():
    # First four "standard" pieces (tetrominoes)
    iPiece = [
        [  True,  True,  True,  True ]
    ]
    jPiece = [
        [  True, False, False ],
        [  True,  True,  True ]
    ]
    lPiece = [
        [ False, False,  True ],
        [  True,  True,  True ]
    ]
    oPiece = [
        [  True,  True ],
        [  True,  True ]
    ]
    return(iPiece, jPiece, lPiece, oPiece)

def shapes2():
    # Next three "standard" peices (tetrominoes)
    sPiece = [
        [ False,  True,  True ],
        [  True,  True, False ]
    ]
    tPiece = [
        [ False,  True, False ],
        [  True,  True,  True ]
    ]
    zPiece = [
        [  True,  True, False ],
        [ False,  True,  True ]
    ]
    return(sPiece, tPiece, zPiece)

def appStarted(app):
    # Holds our model 
    app.difficulty = 'Default'
    app.timerDelay = 500 # sets speed of fallingPiece
    app.isPaused = False
    app.score = 0
    app.isGameOver = False
    app.rows, app.cols, app.cellSize, app.margin = gameDimensions()
    app.emptyColor = 'blue'
    app.board = [[app.emptyColor]*app.cols for row in range(app.rows)]
    app.width = app.cols*app.cellSize + 2*app.margin
    app.height = app.rows*app.cellSize + 2*app.margin
    app.tetrisPieces = []
    app.tetrisPieces.extend(shapes1())
    app.tetrisPieces.extend(shapes2())
    app.tetrisPieceColors = [ "red", "yellow", "magenta", "pink", 
                            "cyan", "green", "orange" ]
    app.fallingPiece = []
    app.fallingColorPiece = 0
    app.fallingPieceRow = 0
    app.numFallingPieceCols = 0
    app.fallingPieceCol = 0
    newFallingPiece(app)

def drawBoard(app, canvas):
    # Generates a tetris gameboard by calling the drawCell function
    for row in range(app.rows):
        for col in range(app.cols):
            drawCell(app, canvas, row, col, app.board[row][col])

def drawCell(app, canvas, row, col, color): 
    # Taken from getCellBounds() function in notes. 
    # https://www.cs.cmu.edu/~112/notes/notes-animations-part1.html           
    gridWidth  = app.width - 2*app.margin
    gridHeight = app.height - 2*app.margin           
    x0 = app.margin + gridWidth * col / app.cols
    x1 = app.margin + gridWidth * (col+1) / app.cols
    y0 = app.margin + gridHeight * row / app.rows
    y1 = app.margin + gridHeight * (row+1) / app.rows
    canvas.create_rectangle(x0, y0, x1, y1, fill=color, width = 2)

def newFallingPiece(app):
    # Picks a random piece from our list of possible pieces and stores it in
    # model along with its corresponding color and start positions on the
    # board.
    import random
    randomIndex = random.randint(0,len(app.tetrisPieces)-1)
    app.fallingPiece = app.tetrisPieces[randomIndex]
    app.fallingColorPiece = app.tetrisPieceColors[randomIndex]
    app.fallingPieceRow = 0
    app.numFallingPieceCols = len(app.fallingPiece[0])
    app.fallingPieceCol = int(app.cols//2) - int((app.numFallingPieceCols)//2) 
    

def drawFallingPiece(app, canvas):
    # Draws the cells of the falling piece over the board usng the
    # drawCell() function.
    piece = app.fallingPiece
    for row in range(len(piece)):
        for col in range(len(piece[0])):
            if piece[row][col] == True:
                drawCell(app, canvas, row + app.fallingPieceRow, 
                            col + app.fallingPieceCol, app.fallingColorPiece)

def moveFallingPiece(app, drow, dcol):
    # Moves falling piece drows and dcols from its current position
    # on the board.
    app.fallingPieceRow += drow
    app.fallingPieceCol += dcol

def rotateFallingPiece(app):
    # Creates a new 2D list with the dimensions of our rotated piece
    # and finds the new center row and column.  We also map the True
    # and False values from thier old positions to their new ones. 
    rows = len(app.fallingPiece)
    cols = len(app.fallingPiece[0])
    newRows = cols
    newCols = rows
    newPiece = [[None]*newCols for row in range(newRows)]
    newPieceCol = int(app.cols//2)- int(newCols//2)
    newCenterRow = app.fallingPieceRow + int(rows//2) - int(newRows//2)
    newCenterCol = app.fallingPieceCol + int(cols//2) - int(newCols//2)
    for row in range(rows):
        for col in range(cols):
            newPiece[col][rows-1-row] = app.fallingPiece[row][col]
    app.fallingPiece = newPiece
    app.fallingPieceCol = newCenterCol 
    app.fallingPieceRow = newCenterRow
    
def fallingPieceIsLegal(app):
    # Checks to make sure the falling piece is on the board or not moving past 
    # or ontop of obstructing pieces that have been set on the board.
    piece = app.fallingPiece
    fpRow = app.fallingPieceRow
    fpCol = app.fallingPieceCol
    pieceNum, indexComp, resultNum = (0, 1, 0)
    for i in range(len(piece)):
        for j in range(len(piece[0])):
            if piece[i][j] == True:
                pieceNum += 1
    for row in range(len(piece)):
        for col in range(len(piece[0])):
            if (row+fpRow <= len(app.board)-indexComp) and \
                (col+fpCol <= len(app.board[0])-indexComp) and \
                (row+fpRow >= 0) and (col+fpCol >= 0) and \
                (piece[row][col] == True) and \
                (app.board[row+fpRow][col+fpCol] \
                    == app.emptyColor):
                resultNum +=1
            else:
                pass
    if resultNum == pieceNum:
        return True
    else:
        return False
    
def placeOnBoard(app):
    # Permantly stores the color values of our piece in the 2D list that 
    # makes up our board when they reach the bottom or run into another piece
    # stored in the board.  They are stored until they become part of a full 
    # row and get removed or the game is restarted.
    piece = app.fallingPiece
    for row in range(len(piece)):
        for col in range(len(piece[0])):
            if (piece[row][col] == True):
                app.board[row+app.fallingPieceRow][col + app.fallingPieceCol] \
                    = app.fallingColorPiece
    removeFullRows(app)

def removeFullRows(app):
    # Removes a row once it no longer contains any cells with the emptyColor
    # stored in them.  Makes a new board without full rows, and inserts the
    # same amount of rows removed as empty rows at the beginning of the list.
    newBoard = []
    removedRows = 0
    for row in app.board:
        if row.count(app.emptyColor) == 0:
            removedRows += 1
        else:
            newBoard.append(row)
    for row in range(removedRows):
        newBoard.insert(1,[app.emptyColor for i in range(app.cols)])
    app.board = newBoard
    app.score += removedRows

def drawScore(app,canvas):
    # Displays the players score in the top margin.
    canvas.create_text(app.width//2,app.margin//4, text=f'Score: {app.score}',
                        anchor='n', fill='blue',
                        font='Helvetica 16 bold') 

def drawDifficulty(app,canvas):
    # Displays the players score in the top margin.
    if app.difficulty != 'Default':
        canvas.create_text(app.width//2,app.rows*app.cellSize+app.margin+5, 
                            text=f'Difficulty: {app.difficulty}',
                            anchor='n', fill='slate gray',
                            font='Helvetica 12 bold') 

def drawBonusMenuPause(app,canvas):
    # Displays pause information.
    canvas.create_text(app.width/2,
                    app.margin+(4*app.cellSize),
                    text='* PAUSE -> Press (p)',
                    anchor='n',fill='yellow',
                    font='Helvetica 8 bold')
    
def drawBonusMenuMagicShape(app,canvas):
    # Displays Magic Shape Mode information.
    magicText = '* MAGIC SHAPE MODE -> Press (m) while paused. *'
    canvas.create_text(app.width/2,
                    app.margin+(5*app.cellSize),
                    text= magicText,
                    anchor='n',fill='salmon1',
                    font='Helvetica 8 bold')
    dimensionsText = '>> Larger board is recommended for this mode. <<'
    canvas.create_text(app.width/2,
                    app.margin+(5.5*app.cellSize),
                    text= dimensionsText,
                    anchor='n',fill='salmon1',
                    font='Helvetica 8 bold')

def drawBonusMenuDifficulty1(app, canvas):
    # Displays part 1 of the difficulty options.
    canvas.create_text(app.width/2,
                    app.margin+(6*app.cellSize),
                    text= '*  Difficulty *',
                    anchor='n',fill='green2',
                    font='Helvetica 8 bold underline')
    canvas.create_text(app.width/2,
                    app.margin+(6.5*app.cellSize),
                    text= '* Easy             -> 1',
                    anchor='n',fill='green2',
                    font='Helvetica 8 bold')
    canvas.create_text(app.width/2,
                    app.margin+(7*app.cellSize),
                    text= '* Default          -> 2',
                    anchor='n',fill='green2',
                    font='Helvetica 8 bold')

def drawBonusMenuDifficulty2(app, canvas):
    # Displays part 2 of the difficulty options.
    canvas.create_text(app.width/2,
                    app.margin+(7.5*app.cellSize),
                    text= '* Medium        -> 3',
                    anchor='n',fill='green2',
                    font='Helvetica 8 bold')
    canvas.create_text(app.width/2,
                    app.margin+(8*app.cellSize),
                    text= '* Hard              -> 4',
                    anchor='n',fill='green2',
                    font='Helvetica 8 bold')
    canvas.create_text(app.width/2,
                    app.margin+(8.5*app.cellSize),
                    text= '^ To set difficulty, press number while paused. ^',
                    anchor='n',fill='green2',
                    font='Helvetica 8 bold')

def drawBonusMenuRestart(app, canvas):
    canvas.create_text(app.width/2,
                    app.margin+(9.5*app.cellSize),
                    text= '>> Press "r" at anytime to restart. <<',
                    anchor='n',fill='orange',
                    font='Helvetica 12 bold')

def drawFinalBonusMenu(app, canvas):
    # Draws the bonus menu for the user to see additional features.
    # This is called when the user presses the 'b' key.
    canvas.create_rectangle(app.margin,app.margin+3*app.cellSize,
                    app.width-app.margin,app.margin+(12*app.cellSize),
                    fill='light slate gray')
    canvas.create_text(app.width/2,
                    app.margin+(3*app.cellSize+ \
                        app.cellSize/4),
                    text='>**<     BONUS MENU     >**<',
                    anchor='n',fill='black',
                    font='Helvetica 12 bold')
    drawBonusMenuPause(app, canvas)
    drawBonusMenuMagicShape(app, canvas)
    drawBonusMenuDifficulty1(app, canvas)
    drawBonusMenuDifficulty2(app, canvas)
    drawBonusMenuRestart(app, canvas)

    
def bShapes1():
    # Store first half of the bonus mode shapes.
    tPiece = [
        [  True,  True,  True,  True ],
        [  True,  False, True,  False ]
    ]
    uPiece = [
        [  True,  False, False, True ],
        [  True,  True,  True,  True ]
    ]
    vPiece = [
        [ True,  False,  True ],
        [ True,  True,   True ]
    ]
    nPiece = [
        [  False,  True ],
        [  True,  True ]
    ]
    bPiece = [
        [ False,  True,  False ],
        [ False,  True,  False ],
        [ True,   True,  True]
    ]
    return(tPiece, uPiece, vPiece, nPiece, bPiece)

def bShapes2():
    # Store second half of the bonus mode shapes.
    tPiece = [
        [ False,  False, True ],
        [ False,  False, True ],
        [ True,   True,  True ]
    ]
    ezPiece = [
        [ False,  False, True ],
        [ False, True, False ],
        [True, False, False]
    ]
    mPiece = [
        [ True,  True, True ],
        [ False, True, False ],
        [ True,  True, True ]
    ]
    return(tPiece, ezPiece, mPiece)

def bonusShapes(app):
    # Adds bonus shapes and colors to our tertrisPieces list.
    shapes1 = bShapes1()
    shapes2 = bShapes2()
    app.tetrisPieces.extend(shapes1)
    app.tetrisPieces.extend(shapes2)
    app.tetrisPieceColors.extend([ "purple", "gold", 
                            "seashell3", "dark slate gray", 
                            "white", "black", "spring green","turquoise1" ])


def timerFired(app):
    # Is used in our case to move the tetris pieces by themselves so they 
    # descend down the board so long as the game is not paused or over.  
    if app.isGameOver == False:
        if (not app.isPaused):
        
            moveFallingPiece(app,+1,0)
            if fallingPieceIsLegal(app):
                pass
            else:
                moveFallingPiece(app, -1, 0)
                placeOnBoard(app)
                if app.fallingPieceRow > 0:
                    newFallingPiece(app)
                else:
                    app.isGameOver = True
        else: pass
    else:pass

def bonusModeControls(app, event):
    if (event.key == 'p' or event.key == 'b') and app.isPaused == True:
        app.isPaused = False
    elif (event.key == 'p' or event.key == 'b') and app.isPaused == False:
        app.isPaused = True
    elif (app.isPaused == True) and (event.key == 'm'):
        bonusShapes(app)
    elif (app.isPaused == True) and (event.key == '1'):
        app.timerDelay = 1000
        app.difficulty = 'Easy'
    elif (app.isPaused == True) and (event.key == '2'):
        app.timerDelay = 500
        app.difficulty = 'Default'
    elif (app.isPaused == True) and (event.key == '3'):
        app.timerDelay = 250  
        app.difficulty = 'Medium'
    elif (app.isPaused == True) and (event.key == '4'):
        app.timerDelay = 100
        app.difficulty = 'Hard'
    else: pass

def leftRightControls(app, event):
    if event.key == 'Left':
        moveFallingPiece(app, 0, -1)
        if fallingPieceIsLegal(app):
            pass
        else: 
            moveFallingPiece(app, 0, +1)
    elif event.key == 'Right':
        moveFallingPiece(app,0, +1)
        if fallingPieceIsLegal(app):
            pass
        else:
            moveFallingPiece(app, 0, -1)

def upDownControls(app, event):
    if event.key == 'Down':
        moveFallingPiece(app,+1, 0)
        if fallingPieceIsLegal(app):
            pass
        else:
            moveFallingPiece(app, -1, 0)
    elif event.key == 'Up':
        rotateFallingPiece(app)
        if fallingPieceIsLegal(app):
            pass
        else:
            rotateFallingPiece(app)
            rotateFallingPiece(app)
            rotateFallingPiece(app)

def keyPressed(app, event):
    # This is part of our controller, it is used to rotate the pieces 
    # during game play, when they are able to make legal moves.  
    # Also takes input to restart the game, enter bonus mode, 
    # and pause the game.
    bonusModeControls(app, event)
    if app.isGameOver == False:
        leftRightControls(app, event)
        upDownControls(app, event)
        if event.key == 'Space':
            while fallingPieceIsLegal(app):
                moveFallingPiece(app, +1, 0)
                pass
            else:
                moveFallingPiece(app,-1, 0)
        else:
            pass
    if event.key == 'r':
            playTetris()
    else:
        pass
        
    
def redrawAll(app, canvas):
    # Draws game board and pieces on the screen in addition to
    # the game over, and bonus menu pop-up messages.
    canvas.create_rectangle(0,0,app.width, app.height, fill='orange')
    drawScore(app,canvas)
    drawDifficulty(app, canvas)
    drawBoard(app, canvas)
    drawFallingPiece(app,canvas)
    if app.isGameOver == True:
        canvas.create_rectangle(app.margin,app.margin+app.cellSize,
                                app.width-app.margin,app.margin+(3*app.cellSize)
                                ,fill='black')
        canvas.create_text(app.width/2,app.margin+(app.cellSize+app.cellSize/4),
                            text='Game Over',anchor='n',fill='yellow',
                            font='Helvetica 26 bold')
    if app.isPaused == True:
        drawFinalBonusMenu(app,canvas)



#################################################
##############        main        ###############
#################################################

def main():
    cs112_s20_unit6_linter.lint()
    playTetris()

if __name__ == '__main__':
    main()
