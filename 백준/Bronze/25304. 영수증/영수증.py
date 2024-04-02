import sys
input = sys.stdin.readline

res = 0

X = int(input())
N = int(input())
for _ in range(N):
    a, b = map(int, input().split())
    res += a * b

if res == X:
    print("Yes")
else:
    print("No")