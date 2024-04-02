import sys
input = sys.stdin.readline

l = ['a', 'e', 'i', 'o', 'u']
s = input().strip()
cnt = 0
for c in s:
    if c in l:
        cnt += 1
print(cnt)