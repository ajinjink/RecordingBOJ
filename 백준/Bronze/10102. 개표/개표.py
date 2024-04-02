import sys
input = sys.stdin.readline

input()
s = input().strip()
a, b = 0, 0
for c in s:
    if c == 'A':
        a += 1
    else:
        b += 1
if a == b:
    print("Tie")
else:
    print("A" if a > b else "B")