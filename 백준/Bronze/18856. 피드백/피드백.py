import sys
input = sys.stdin.readline

n = int(input())
res = [1, 2] + [i for i in range(3, n)] + [53]
print(n)
print(*res)