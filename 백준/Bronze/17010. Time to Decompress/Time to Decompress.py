import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, x = input().split()
    print(x * int(n))