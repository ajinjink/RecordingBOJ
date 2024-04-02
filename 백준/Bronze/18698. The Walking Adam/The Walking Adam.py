import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()
    cnt = 0
    for i in range(len(s)):
        if s[i] == 'U':
            cnt += 1
        else:
            break
    print(cnt)