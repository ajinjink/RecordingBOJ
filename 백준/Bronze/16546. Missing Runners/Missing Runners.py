import sys
input = sys.stdin.readline

n = int(input())
l = [0] * (n + 1)
cnt = list(map(int, input().split()))
for i in cnt:
    l[i] += 1
print(l[1:].index(0) + 1)