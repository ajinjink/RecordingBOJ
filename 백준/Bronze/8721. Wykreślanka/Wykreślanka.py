import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
cnt = 0
t = 1
for i in l:
    if i != t:
        cnt += 1
    else:
        t += 1
print(cnt)