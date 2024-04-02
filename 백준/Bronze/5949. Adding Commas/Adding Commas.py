import sys
input = sys.stdin.readline

s = input().strip()
for i in range(len(s)):
    if (len(s) - i) % 3 == 0 and i != 0:
        print(',', end='')
    print(s[i], end='')