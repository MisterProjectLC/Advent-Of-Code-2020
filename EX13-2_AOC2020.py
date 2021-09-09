import re

# create regex
intRegex = re.compile("\d+|x")

file = open("input.txt", 'r')
vector = intRegex.findall(file.read())

time = 0
step = 1
for i in range(2, len(vector)):
    print(vector[i] + " " + str(step) + " " + str(time))
    if vector[i-1] != 'x':
        step *= int(vector[i-1])
    
    if vector[i] == 'x':
        time += 1
        continue
    
    while True:
        if (time+1) % int(vector[i]) == 0:
            time += 1
            break
        else:
            time += step
        
print(time-len(vector)+2)


