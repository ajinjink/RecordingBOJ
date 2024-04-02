import sys
input = sys.stdin.readline

n, m = map(int, input().split())
res = 1
for i in list(map(int, input().split())):
  res *= i
print(res % m)