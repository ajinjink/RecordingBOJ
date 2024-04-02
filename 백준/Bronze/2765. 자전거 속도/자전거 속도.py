import math
import sys
input = sys.stdin.readline

c = 1
while True:
    d, r, t = map(float, input().split())
    if r == 0:
        break
    dis = d / 63360 * math.pi * r
    mph = dis / t * 3600
    print(f"Trip #{c}: {dis:.2f} {mph:.2f}")
    c += 1