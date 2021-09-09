import pyperclip, re


def validDigit(minn, maxx, string):
    return (str.isdigit(string) and minn <= int(string) <= maxx)

def checkValid(classifier, string):
    #print(classifier + " - " + string)
    if classifier == "byr" and validDigit(1920, 2002, string):
        return True
    if classifier == "iyr" and validDigit(2010, 2020, string):
        return True
    if classifier == "eyr" and validDigit(2020, 2030, string):
        return True
    if (classifier == "hgt" and
        (validDigit(150, 193, string[:-2]) and string[-2:] == "cm") or
        (validDigit(59, 76, string[:-2]) and string[-2:] == "in")):
        return True
    if classifier == "pid" and str.isdigit(string) and len(string) == 9:
        return True

    eyes = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]
    if classifier == "ecl" and string in eyes:
        return True

    hairRegex = re.compile(r'#([a-f0-9]{6})')
    if classifier == "hcl" and hairRegex.search(string) != None and hairRegex.search(string)[0] == string:
        return True
    return False
    
required = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
# create regex
text = pyperclip.paste()
codeRegex = re.compile(r'((\w\w\w):(\S+)( |\r\n))(\r\n)?')

matches = codeRegex.findall(text)

count = 0
received = []

for match in matches:
    if match[1] in required and (match[1] not in received):
        if checkValid(match[1], match[2]):
            received.append(match[1])

    if match[4] == "\r\n":
        if len(received) >= 7:
            count += 1
        received = []

print(count)

