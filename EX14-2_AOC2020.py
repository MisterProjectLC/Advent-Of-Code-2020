import re

# create regex
maskRegex = re.compile("mask")
digitRegex = re.compile("X|\d")
memRegex = re.compile("mem\[(\d+)\] = (\d+)")


file = open("input.txt", 'r')
lines = file.readlines()

mask = [0, 0]
memory = {}

for line in lines:
    findMask = maskRegex.search(line)
    if findMask != None:
        maskDigits = digitRegex.findall(line)
        mask = [0, 0]
        pos = 36
        for c in maskDigits:
            pos -= 1
            if c == 'X':
                continue
            mask[int(c)] += 2**pos
    
    else:
        command = memRegex.search(line)
        
        value = ((int(command.group(2)) | mask[1]) ^ mask[0]) & ~mask[0]
        memory[command.group(1)] = value
            
                
print(sum(memory.values()))

