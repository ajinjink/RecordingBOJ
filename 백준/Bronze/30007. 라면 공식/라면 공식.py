import sys

for _ in range(int(sys.stdin.readline())):
    a, b, x = map(int, sys.stdin.readline().split())
    print(a * (x - 1) + b)