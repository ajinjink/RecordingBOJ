import sys
input = sys.stdin.readline

s = input().strip()
cnt = 1
for i in range(len(s) - 1):
    if s[i] == s[i + 1]:
        cnt += 1
    else:
        break
print(cnt)