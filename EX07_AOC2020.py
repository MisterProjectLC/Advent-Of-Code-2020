import re

class BagType:
    name = ""
    children = []

    def __init__(self, name):
        self.name = name
        self.children = []

    def addChild(self, bag):
        self.children.append(bag)

    def getName(self):
        return self.name

    def isInside(self, name):
        for c in self.children:
            if c.getName() == name or c.isInside(name):
                return True
        return False


# create regex
mainRegex = re.compile("(\w+ \w+)( bags contain )")
contentRegex = re.compile("(\d+) (\w+ \w+)( bag(s)?)")
bags = {}

target = "shiny gold"

file = open("input.txt", 'r')
lines = file.readlines()

for line in lines:
    name = mainRegex.search(line)[1]
    print("Name: " + name)
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
    for c in children:
        print("Child: " + c)
        bags[name].addChild(bags[c])


# actually calculate
count = 0
for b in bags:
    if bags[b].isInside(target):
        count += 1
    
print(count)
    
        


