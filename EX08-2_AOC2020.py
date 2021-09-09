import re


def checkTimeline(lines, pc, acc, visited_lines, timeline_prime = False):
    saved_acc = []
    
    while True:
        if pc >= len(lines):
            break
        
        current_line = lineRegex.search(lines[pc])
        
        if pc in visited_lines:
            if not timeline_prime:
                print("fail")
                return (False, acc)
            else:
                print("rewind time")
                for i in range(len(visited_lines)-1, -1, -1):
                    print("rewind at " + str(visited_lines[i]))
                    result = (False, 0)

                    target_line = lineRegex.search(lines[visited_lines[i]])

                    # transform nop into jmp
                    if target_line[1] == "nop":
                        result = checkTimeline(lines, int(target_line[2]), saved_acc[i], visited_lines.copy()[:i])

                    # transform jmp into nop
                    elif target_line[1] == "jmp":
                        result = checkTimeline(lines, visited_lines[i]+1, saved_acc[i], visited_lines.copy()[:i])

                    if result[0]:
                        return result
            
        visited_lines.append(pc)
        saved_acc.append(acc)

        #print(current_line[1] + " " + current_line[2])
        if (current_line[1] == "acc"):
            acc += int(current_line[2])

        elif (current_line[1] == "jmp"):
            pc += int(current_line[2]) - 1
            
        pc += 1

    return (True, acc)


# create regex
lineRegex = re.compile("(\w\w\w) (\W\d+)")

file = open("input.txt", 'r')
lines = file.readlines()

print(checkTimeline(lines, 0, 0, [], True)[1])

