import re

# create regex
file = open("input.txt", 'r')
lines = file.readlines()

count = 0
questions = []
removed = []
first_line = True

for line in lines:
    if line == "\n":
        count += len(questions) - len(removed)
        questions = []
        removed = []
        first_line = True
    
    elif first_line:
        first_line = False
        for c in line:
            if c not in questions and c.islower():
                questions.append(c)
    
    else:
        for q in questions:
             if q not in line and q not in removed:
                removed.append(q)
        
print(count)

