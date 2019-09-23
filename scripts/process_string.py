code_table = {}

fd = {}


def gcodetable():
    with open("scripts/CodeTable.txt", encoding="utf-8") as file:
        for line in file:
            line = line.strip().split("=")
            k = line[1]
            if k.startswith("\\"):
                c = line[1][1:]
                if c == 'n':
                    k = '\n'
                elif c == 'r':
                    k = '\r'
                elif c == 'f':
                    k = '\f'
            code_table[k] = line[0]


def gfd():
    with open("scripts/fd.txt" , encoding="utf-8") as file:
        for line in file:
            line = line.strip().split("=")
            fd[line[1]] = line[0]

def readstrings():
    with open("scripts/strings.json", encoding="utf-8") as file:
        return eval(file.read())

def gfile(string):
    length = len(string)
    start = 0
    newstring = "{"
    while start < length:
        c = string[start:start+1]
        if c == '$':
            start += 2
            end = string.find("}", start)
            c = string[start:end]
            start = end + 1
            newstring += tohex(c)
        elif c == '{':
            start += 1
            end = string.find("}", start)
            c = string[start:end]
            start = end + 1
            c = fd[c]
            newstring += "0xFD, " + c + ", "
        else:
            newstring += tohex(code_table[c])
            start = start + 1

    return newstring + "0xFF};"

def tohex(c):
    newstring = ""
    for x in range(0, len(c)//2):
        newstring += "0x" + c[x*2:x*2+2] + ", "
    return newstring

item = readstrings().items()
if len(item) > 0:
    with open("src/string_file.c" , "w") as file:
        gcodetable()
        gfd()
        for k,v in item:
            strs = "const unsigned char " + k + "[] = " + gfile(v)
            print(strs, file = file)