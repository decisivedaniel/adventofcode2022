def findPosition(char):
    if ord(char) > 91:
        return ord(char) - ord("a")
    else:
        return ord(char) - ord("A") + 26

f = open("input.txt")
conflicts = [0] * 52
groupItems = [0] * 52
score = 0
lines = f.readlines()
currentElf = 0
for line in lines:
    modElf = (currentElf % 3) + 1
    for char in line.strip("\n"):
        if groupItems[findPosition(char)] == modElf - 1:
            groupItems[findPosition(char)] = modElf

    currentElf += 1
    if modElf == 3:
        for x in range(52):
            if groupItems[x] == 3:
                conflicts[x] += 1
        groupItems = [0] * 52


for x in range(52):
    if conflicts[x] > 0:
        score += ((x + 1) * conflicts[x])

print(score)