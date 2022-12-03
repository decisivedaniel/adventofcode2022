


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
        #print(char)
        if currentPosition < halfLength - 1:
            if ord(char) > 91:
                #print(" first lc \n")
                firstCompartment[ord(char) - ord("a")] += 1
            else:
                #print(" first uc \n")
                firstCompartment[ord(char) - ord("A") + 26] += 1
        else:
            if ord(char) > 91:
                #print(" second lc \n")
                secondCompartment[ord(char) - ord("a")] += 1
            else:
                #print(" second uc \n")
                secondCompartment[ord(char) - ord("A") + 26] += 1
        currentPosition += 1
    for x in range(52):
        if firstCompartment[x] > 0 and secondCompartment[x] > 0:
            if x < 26:
                foundConflict = chr(x + ord("a"))
            else:
                foundConflict = chr(x + ord("A"))
            #print("conflict ", foundConflict)
            conflicts[x] += 1
            break
for x in range(52):
    if conflicts[x] > 0:
        score += ((x + 1) * conflicts[x])

print(score)
f.close()

    
