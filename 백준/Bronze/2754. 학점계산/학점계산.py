import sys
input = sys.stdin.readline

a = input().strip()

res = 0

if a[0] == 'A':
    res = 4.0
if a[0] == 'B':
    res = 3.0
if a[0] == 'C':
    res = 2.0
if a[0] == 'D':
    res = 1.0



if a[0] == 'F':
    res = 0.0
else:
    if a[1] == '+':
        res += 0.3
    if a[1] == '-':
        res -= 0.3

print(res)