
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


def drawHallwayIllusion(canvas, width, height):
    margin = 15
    lineWidth = 20
    spacing = 4
    startx = (width+margin)-width
    stopx = width - margin
    starty = (height+margin)-height
    stopy = height -margin
    lines = (width)//(lineWidth)
    linesh = (height)//(lineWidth)
    for i in range(lines):
        canvas.create_rectangle(startx+(lines*(i)), starty+(linesh*i), stopx-(lines*i), stopy-(linesh*i), width=10)


def db(canvas,width,height,rows,cols):
    cellw = width/cols
    cellh = height/rows
    for row in range(rows):
        for col in range(cols):
            if (row +col)%2 ==0:
                squareColor= "red"
                circleColor= "black"
            else:
                squareColor = "black"
                circleColor = "red"
            x0 = cellw * col
            x1 = cellw * (col + 1)
            y0 = cellh * row
            y1 = cellh * (row +1)
            canvas.create_rectangle(x0,y0,x1,y1, fill=squareColor)
            canvas.create_oval(x0,y0,x1,y1,outline="white", fill = circleColor, width=3)

def digitCount(n):
    count = 0
    n = abs(n)
    while n:
        count+=1
        n//=10
    return count


print(digitCount(123456))
#basic_graphics.run(10,10,width=500, height=500,drawFn=db)
#basic_graphics.run(width=500, height=500, drawFn=drawHallwayIllusion)
#basic_graphics.run(4, 6, width=900, height=600, drawFn=drawFancyWheels)
