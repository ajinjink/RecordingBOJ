import sys
input = sys.stdin.readline

z = int(input())

for _ in range(z):
    w, k = map(int, input().split())
    print(w * k // 2)