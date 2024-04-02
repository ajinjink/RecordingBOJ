import sys
input = sys.stdin.readline

a, b, c, d = map(int, input().split())
if a * b == c * d:
    print("E")
else:
    print(["M", "P"][a * b < c * d])