import sys
input = sys.stdin.readline

for _ in range(3):
    N = int(input())
    l = [int(input()) for _ in range(N)]
    if sum(l) == 0:
        print(0)
    else:
        print('+' if sum(l) > 0 else '-')