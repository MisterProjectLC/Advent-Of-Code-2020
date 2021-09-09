import re

# create regex
lineRegex = re.compile("(\w\w\w) (\W\d+)")

file = open("input.txt", 'r')
lines = file.readlines()

visited_lines = []
acc = 0
pc = 0

while True:
    current_line = lineRegex.search(lines[pc])
    
    if pc in visited_lines:
        break
    visited_lines.append(pc)

    #print(current_line[1] + " " + current_line[2])
    if (current_line[1] == "acc"):
        acc += int(current_line[2])

    elif (current_line[1] == "jmp"):
        pc += int(current_line[2]) - 1
        
    pc += 1
    

print(visited_lines)
print(acc)

