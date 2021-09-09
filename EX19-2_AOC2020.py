import re

class Rule:
    def __init__(self, ruleNumbers, letter, number):
        self.ruleNumbers = ruleNumbers
        self.rules = []
        
        self.number = number
        if letter == None:
            self.letter = '.'
        else:
            self.letter = letter.group(0)


    def populateRules(self, rules):
        for ruleN in self.ruleNumbers:
            if ruleN == self.number:
                self.rules.append(self)
            elif ruleN != -1:
                self.rules.append(rules[ruleN])
            else:
                self.rules.append(None)


    def checkValidity(self, string):
        #print(str(self.ruleNumbers) + " - " + self.letter)       
        if self.letter == string[0]:
            return 1

        if self.rules[0] != None:
            offset = self.rules[0].checkValidity(string)
            if offset != 0:
                if self.rules[1] == None:
                    return offset
                offset2 = self.rules[1].checkValidity(string[offset:])
                if offset2 != 0:
                    return offset + offset2

        if self.rules[2] != None:
            offset = self.rules[2].checkValidity(string)
            if offset != 0:
                if self.rules[3] == None:
                    return offset
                offset2 = self.rules[3].checkValidity(string[offset:])
                if offset2 != 0:
                    if self.rules[4] == None:
                        return offset + offset2
                    offset3 = self.rules[4].checkValidity(string[(offset + offset2):])
                    if offset3 != 0:
                        return offset + offset2 + offset3
            
        return 0


# create regex
ruleRegex = re.compile("(\d+)\: (.+)")
intRegex = re.compile("(\d+)( (\d+))?( \| )?(\d+)?( (\d+))?( (\d+))?")
charRegex = re.compile("[a-z]")

# input
arq = open("input2.txt", 'r')
lines = arq.readlines()
arq.close()

total = 0
rulesVector = [None] * 300

for line in lines:
    ruleN = ruleRegex.search(line)
    # receive rules
    if ruleN != None:
        intMatch = intRegex.search(ruleN.group(2))
        rules = []
        for i in range(1, 10, 2):
            if intMatch != None and intMatch.group(i) != None:
                rules.append(int( intMatch.group(i) ))
            else:
                rules.append(-1)
        
        rulesVector[int(ruleN.group(1))] = Rule( rules, charRegex.search(ruleN.group(2)), int(ruleN.group(1)) )

    # populate rules
    elif len(line) == 1:
        for rule in rulesVector:
            if rule != None:
                rule.populateRules(rulesVector)
    
    # test against rule 0
    else:
        offset = 0
        offset2 = 0
        found = False
        i = 1
        while offset < len(line) and not found:
            offset = rulesVector[42].checkValidity(line[i*offset:])
            print("offset: " + str(offset))
            if offset == 0:
                break
            j = 1
            while i*offset + j*offset2 < len(line) and not found:
                offset2 = rulesVector[42].checkValidity(line[(i*offset)+(j*offset2):])
                print("offset2: "+ str(offset2))
                if offset2 == 0:
                    break
                offset2 = rulesVector[31].checkValidity(line[(i*offset)+(j*offset2):])
                if offset2 == 0:
                    break
                elif i*offset + j*offset2 == len(line)-1:
                    found = True
            i += 1

        if found:
            total += 1
        
print(total)
