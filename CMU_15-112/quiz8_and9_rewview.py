













def makeCourseDictionary(courseData):
    result = dict()
    data = courseData.splitlines()[2:]
    for line in data:
        name, role, course = line.split(">")
        if course not in result:
            result[course]= dict()
        if role not in result[course]:
            result[course][role] = set()
        result[course][role].add(name)
    return result



####################### Test Cases ###########################
courseData = '''
name>role>course
koz>prof>112
lisanne>ta>112
mike>prof>112
kelly>prof>110
jimothy>ta>110
'''

resultDict = {'112':{'prof':{'mike','koz'}, 'ta':{'lisanne'}}, \
                '110':{'prof':{'kelly'}, 'ta':{'jimothy'}}}

def testMakeCourseDictionary():
    print('Testing makeCourseDictionary()   ', end='')
    assert(makeCourseDictionary(courseData)== resultDict)
    print('Passed...')






def testFunctions():
    print('<------> Running Test Cases: Unit 8 and 9 Practice <------>')
    testMakeCourseDictionary()


def main():
    testFunctions()

main()

