import sys
input = sys.stdin.readline

n = int(input())
d1 = int(input())
for _ in range(n - 1):
    d1 += int(input())
print(d1)