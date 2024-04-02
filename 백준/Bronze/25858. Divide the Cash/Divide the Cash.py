import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = []

for _ in range(n):
    l.append(int(input()))

total = sum(l)
for i in l:
    print(m * i // total)