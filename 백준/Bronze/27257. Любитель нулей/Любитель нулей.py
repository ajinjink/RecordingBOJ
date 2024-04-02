import sys
input = sys.stdin.readline

s = input().strip()
cnt = s.count('0')
for i in range(len(s) -1, -1, -1):
    if s[i] == '0':
        cnt -=1
    else:
        break
print(cnt)