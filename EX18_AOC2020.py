import re

def getResult(regex, text):
    firstMatch = regex.search(text)
    while (firstMatch != None):
        result = 0
        if firstMatch.group(2) == '+':
            result = int(firstMatch.group(1)) + int(firstMatch.group(3))
        else:
            result = int(firstMatch.group(1)) * int(firstMatch.group(3))

        text = regex.sub(str(result), text, 1)
        firstMatch = regex.search(text)
    
    return text


# create regex
parenRegex = re.compile("\(([^\(\)]+)\)")
operatRegex = re.compile("(\d+) (\+|\*) (\d+)")
intRegex = re.compile("\d+")

# input
arq = open("input.txt", 'r')
lines = arq.readlines()
arq.close()

total = 0

for line in lines:
    # deal with parenthesis
    firstMatch = parenRegex.search(line)
    while (firstMatch != None):
        text = firstMatch.group(1)
        result = getResult(operatRegex, text)
        line = parenRegex.sub(str(result), line, 1)
        firstMatch = parenRegex.search(line)

    # get entire result
    line = getResult(operatRegex, line)
    total += int(line)

print(total)
