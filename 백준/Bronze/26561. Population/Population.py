import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    a -= b // 7
    a += b // 4
    print(a)