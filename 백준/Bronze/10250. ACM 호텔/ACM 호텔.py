import sys

T = int(sys.stdin.readline())

for _ in range(T):
    H, W, N = map(int, sys.stdin.readline().split())
    if N % H == 0:
        res = H * 100 + N//H
    else:
        res = N%H*100 + N//H + 1
    print(res)
