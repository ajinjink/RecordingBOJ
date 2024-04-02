import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
res = 0
for i in l:
    if i > 0:
        res += 1
print(res)