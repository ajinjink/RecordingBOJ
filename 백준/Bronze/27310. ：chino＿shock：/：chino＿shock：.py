import sys
input = sys.stdin.readline

s = input().strip()
cnt = 0
for c in s:
    if c == ':':
        cnt += 1
    elif c == '_':
        cnt += 5
print(cnt + len(s))