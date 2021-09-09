import re

class Ranger:
    def __init__(self):
        self.combos = []
        self.hypothesis = []
        
    def addCombo(self, lower, upper, lower2, upper2):
        print(str(lower) + "-" + str(upper) + " " + str(lower2) + "-" + str(upper2))
        self.combos.append([lower, upper, lower2, upper2])

    def closeCombos(self):
        for i in range(len(self.combos)):
            self.hypothesis.append(list(range(len(self.combos))))

    def checkValue(self, hypo, value):
        n = 0
        while n < len(self.hypothesis[hypo]):
            i = self.hypothesis[hypo][n]
            if not (self.combos[i][0] <= value <= self.combos[i][1] or self.combos[i][2] <= value <= self.combos[i][3]):
                #print(str(self.combos[i][0]) + "-" + str(self.combos[i][1]) + " " + str(self.combos[i][2]) + "-" + str(self.combos[i][3]) + "? " + str(hypo) + " " + str(value) + " DEL")
                del self.hypothesis[hypo][n]
            else:
                #print(str(self.combos[i][0]) + "-" + str(self.combos[i][1]) + " " + str(self.combos[i][2]) + "-" + str(self.combos[i][3]) + "? " + str(hypo) + " " + str(value) + " KEEP")
                n += 1
                
    def getHypothesis(self):
        done = False
        while not done:
            done = True
            for hypo in self.hypothesis:
                if len(hypo) == 1:
                    for scrub_hypo in self.hypothesis:
                        if len(scrub_hypo) > 1 and hypo[0] in scrub_hypo:
                            scrub_hypo.remove(hypo[0])
                else:
                    done = False
                            
        print(self.hypothesis)
        return self.hypothesis
        

# create regex
rangeRegex = re.compile("(\d+)-(\d+) (or (\d+)-(\d+))?")
intRegex = re.compile("\d+")
ranger = Ranger()

arq = open("output.txt", 'r')
lines = arq.readlines()
arq.close()

my_ticket = []
stage = 0

for line in lines:
    if line == "your ticket:\n" or line == "nearby tickets:\n":
        stage += 1
        if stage == 2:
            ranger.closeCombos()

    elif stage == 0:
        match = rangeRegex.search(line)
        if match != None:
            ranger.addCombo(int(match.group(1)), int(match.group(2)), int(match.group(4)), int(match.group(5)))

    elif stage == 1:
        numbers = intRegex.findall(line)
        if len(numbers) > 0:
            my_ticket = intRegex.findall(line).copy()

    elif stage == 2:
        numbers = intRegex.findall(line)
        n = 0
        for value in numbers:
            ranger.checkValue(n, int(value))
            n += 1

print(my_ticket)

n = 0
answer = 1
for i in ranger.getHypothesis():
    if i[0] in range(6):
        answer *= int(my_ticket[n])
    n += 1

print(answer)

