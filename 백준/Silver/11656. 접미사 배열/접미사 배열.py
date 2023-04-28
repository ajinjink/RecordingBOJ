import sys
S = sys.stdin.readline()

listS = []

for i in range(len(S)):
    listS.append(S[i:len(S) - 1])

listS.sort()

for i in range(1, len(S)):
    print(listS[i])