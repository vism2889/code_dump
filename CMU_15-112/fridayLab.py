import basic_graphics


def lineParse(s):
    val = ''
    command = ''
    valll = ''
    if s.startswith('#') or s.startswith(' '):
        return None
    else:
        val = s.split(' ')
        if val != ['']:
        #command = s.split(' ')[0]

            print(val)
            command = val[0]
            valll = val[1]
        '''
            color = line.split(' ')[1]
        if line.startswith('move'):
            moveAngle = line.split(' ')[1]

        if line.startswith('left'):
            # multiply by negative 1 to set direction
            directVal = line.split(' ')[1]
        if line.startswith('right'):
            directVal = line.split(' ')[1]
        print(directVal, moveAngle, color)
        '''
    #print(command, val)
    return(command, val)

def drawLines(canvas, s, width, height):
    # starts in center of the screen
    cenx = width/2
    ceny = height/2



def runDrawSimpleTortoiseProgram(program, width, height):
    color = ''
    moveAngle = ''
    directVal = ''
    command = ''
    val = ''
    for line in program.splitlines():
        split = lineParse(line)
        if split[0] == 'color':
            color = split[1]
            print(split[1])



        #canvas.create_line(oldX, oldY, newX, newY, fill = color, width = 4)



runDrawSimpleTortoiseProgram("""
# This is a simple tortoise program
color blue
move 50

left 90

color red
move 100

color none # turns off drawing
move 50

right 45

color green # drawing is on again
move 50

right 45

color orange
move 50

right 90

color purple
move 100
""",300,400)




lineParse("""
# This is a simple tortoise program
color blue
move 50

left 90

color red
move 100

color none # turns off drawing
move 50

right 45

color green # drawing is on again
move 50

right 45

color orange
move 50

right 90

color purple
move 100
""")
