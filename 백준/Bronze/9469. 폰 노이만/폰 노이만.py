import sys
input = sys.stdin.readline

for i in range(int(input())):
    n, d, a, b, f = map(float, input().split())
    print(int(n), d / (a + b) * f)