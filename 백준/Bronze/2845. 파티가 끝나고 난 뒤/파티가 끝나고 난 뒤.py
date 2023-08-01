import sys
input = sys.stdin.readline

l, p = map(int, input().split())
arr = list(map(int, input().split()))

total = l * p
for i in arr:
    print(i - total, end=' ')
