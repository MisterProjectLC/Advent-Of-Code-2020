import re    

def add_addresses(source, q_mask, progress, addresses):   
    if len(q_mask) > progress:
        this_mask = 2**q_mask[progress]
        addresses = add_addresses(source | this_mask, q_mask, progress+1, addresses)
        addresses = add_addresses((source ^ this_mask) & ~this_mask, q_mask, progress+1, addresses)
    else:
        addresses.append(source)

    return addresses

# create regex
maskRegex = re.compile("mask")
digitRegex = re.compile("X|\d")
memRegex = re.compile("mem\[(\d+)\] = (\d+)")

file = open("input.txt", 'r')
lines = file.readlines()

mask = [0, 0]
quantum_mask = []
memory = {}

for line in lines:
    findMask = maskRegex.search(line)
    if findMask != None:
        maskDigits = digitRegex.findall(line)
        mask = [0, 0]
        quantum_mask = []

        pos = len(maskDigits)
        for c in maskDigits:
            pos -= 1
            if c == 'X':
                quantum_mask.append(pos)
            else:
                mask[int(c)] += 2**pos
    
    else:
        command = memRegex.search(line)
        
        source = int(command.group(1)) | mask[1]
        addresses = []
        addresses = add_addresses(source, quantum_mask, 0, addresses)
        
        for address in addresses:
            memory[address] = int(command.group(2))
                         
print(sum(memory.values()))

