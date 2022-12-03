
def findPosition(char):
    if ord(char) > 91:
        return ord(char) - ord("a")
    else:
        return ord(char) - ord("A") + 26

f = open("input.txt")
conflicts = [0] * 52
score = 0
lines = f.readlines()
for line in lines:
    firstCompartment = [0] * 52
    secondCompartment = [0] * 52
    halfLength = len(line) / 2
    currentPosition = 0
    for char in line.strip("\n"):
        if currentPosition < halfLength - 1:
            firstCompartment[findPosition(char)] += 1
        else:
            secondCompartment[findPosition(char)] += 1
        currentPosition += 1
    for x in range(52):
        if firstCompartment[x] > 0 and secondCompartment[x] > 0:
            conflicts[x] += 1
            break
for x in range(52):
    if conflicts[x] > 0:
        score += ((x + 1) * conflicts[x])

print(score)
f.close()

    
