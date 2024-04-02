import sys
input = sys.stdin.readline

n = input().strip()
if len(n) == 3:
    if n[1] == '0':
        print(int(n[:2]) + int(n[2]))
    else:
        print(int(n[0]) + int(n[1:]))
elif len(n) == 4:
    print(int(n[:2]) + int(n[2:]))
else:
    print(int(n[0]) + int(n[1]))