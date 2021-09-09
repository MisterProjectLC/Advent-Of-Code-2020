import re

class BagType:
    name = ""
    children = {}

    def __init__(self, name):
        self.name = name
        self.children = []

    def addChild(self, bag, quantity):
        self.children.append((bag, quantity))

    def getName(self):
        return self.name

    def isInside(self, name):
        for c in self.children:
            if c[0].getName() == name or c[0].isInside(name):
                return True
        return False

    def getQuantity(self):
        count = 1
        for c in self.children:
            count += c[0].getQuantity()*c[1]
        return count


# create regex
mainRegex = re.compile("(\w+ \w+)( bags contain )")
contentRegex = re.compile("(\d+) (\w+ \w+)( bag(s)?)")
bags = {}

target = "shiny gold"

file = open("input.txt", 'r')
lines = file.readlines()

for line in lines:
    name = mainRegex.search(line)[1]
    children_matches = contentRegex.findall(line)
    children = []

    # create bag's children (if not there)
    for c in children_matches:
        c_name = c[1]
        children.append(c_name)
        if c_name not in bags:
            bags[c_name] = BagType(c_name)

    # create bag (if not there)
    if name not in bags:
        bags[name] = BagType(name)

    # populate bag
    for c in children_matches:
        c_name = c[1]
        c_qtd = c[0]
        bags[name].addChild(bags[c_name], int(c_qtd))


# actually calculate   
print(bags[target].getQuantity()-1)
    
        


