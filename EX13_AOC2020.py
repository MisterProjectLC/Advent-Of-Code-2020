import re

# create regex
intRegex = re.compile("\d+")

file = open("input.txt", 'r')
vector = intRegex.findall(file.read())

time = int(vector[0])

best_time = 100000
best_id = 0
for i in range(1, len(vector)):
    this_id = int(vector[i])

    if time % this_id != 0:
        ceiling = this_id*(1 + time//this_id)
        wait_time = ceiling-time
    else:
        wait_time = 0
    
    if wait_time < best_time:
        best_time = wait_time
        best_id = this_id


print(str(best_time*best_id))

