import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
two, E = 0, 0
for c in s:
    if c == '2':
        two += 1
    else:
        E += 1
if two == E:
    print("yee")
elif two > E:
    print(2)
else:
    print('e')