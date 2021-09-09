import re

class Ranger:
    def __init__(self):
        self.valueRange = []
        self.directionRange = []
        
    def addCombo(self, lower, upper):
        i = 0
        while i < len(self.valueRange) and lower > self.valueRange[i]:
            i += 1
        print("Lower " + str(i))
        self.valueRange.insert(i, lower)
        self.directionRange.insert(i, False)

        i += 1
        while i < len(self.valueRange) and upper > self.valueRange[i]:
            del self.valueRange[i]
            del self.directionRange[i]
        
        print("Upper " + str(i))
        self.valueRange.insert(i, upper)
        self.directionRange.insert(i, True)

        self.update()


    def update(self):
        lastIsUpper = True
        i = 0
        while i < len(self.directionRange):
            if self.directionRange[i] == lastIsUpper:
                if not lastIsUpper:
                    del self.valueRange[i]
                    del self.directionRange[i]
                    i -= 1
                else:
                    del self.valueRange[i-1]
                    del self.directionRange[i-1]
                    i -= 1

            lastIsUpper = self.directionRange[i]
            i += 1

        print(self.valueRange)
        print(self.directionRange)
        print("-----------")


    def checkValue(self, value):
        lastIsUpper = True
        i = 0
        while i < len(self.directionRange) and int(value) > self.valueRange[i]:
            lastIsUpper = self.directionRange[i]
            i += 1

        return not lastIsUpper
        

# create regex
rangeRegex = re.compile("(\d+)-(\d+) (or (\d+)-(\d+))?")
intRegex = re.compile("\d+")
ranger = Ranger()

arq = open("input.txt", 'r')
lines = arq.readlines()
arq.close()

output = open("output2.txt", 'a')

stage = 0
error_rate = 0

for line in lines:
    if line == "your ticket:\n" or line == "nearby tickets:\n":
        stage += 1

    elif stage == 0:
        match = rangeRegex.search(line)
        if match != None:
            ranger.addCombo(int(match.group(1)), int(match.group(2)))
            if match.group(4) != None:
                ranger.addCombo(int(match.group(4)), int(match.group(5)))

    elif stage == 2:
        numbers = intRegex.findall(line)
        test = False
        for i in numbers:
            if not ranger.checkValue(i):
                test = True
                error_rate += int(i)
                break

        if not test:
            output.write(str(numbers) + "\n")
output.close()


print(error_rate)

