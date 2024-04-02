import sys
input = sys.stdin.readline

s = input().strip()
for c in s:
    if ord('a') <= ord(c) <= ord('z'):
        print(f"{(ord(c) - ord('a') + 1):02d}", end='')
    elif ord('A') <= ord(c) <= ord('Z'):
        print(f"{(ord(c) - ord('A') + 27):02d}", end='')
    elif c in '0123456789':
        print(f"#{c}", end='')
    else:
        print(c, end='')