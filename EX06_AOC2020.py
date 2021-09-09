import re

# create regex
file = open("input.txt", 'r')
lines = file.readlines()

count = 0
questions = []

for line in lines:
    if line == "\n":
        count += len(questions)
        questions = []
    
    else:
        for c in line:
            if c not in questions and c.islower():
                questions.append(c)
        
print(count)

