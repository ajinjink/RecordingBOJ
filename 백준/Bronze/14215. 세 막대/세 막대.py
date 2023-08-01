import sys
input = sys.stdin.readline

l = sorted(map(int, input().split()))
res = l[0] + l[1] + min(l[2], l[0] + l[1] - 1)
print(res)