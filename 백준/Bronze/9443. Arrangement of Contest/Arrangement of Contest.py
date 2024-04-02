import sys
input = sys.stdin.readline

res = set()
for i in range(int(input())):
    s = input()
    res.add(s[0])
alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
i = 0
while i < 26:
    if alpha[i % 26] not in res:
        break
    i += 1
print(i)