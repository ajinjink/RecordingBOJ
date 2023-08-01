import math
import sys
input = sys.stdin.readline

n, w, h = map(int, input().split())
for _ in range(n):
    s = int(input())
    if s <= w or s <= h:
        print("DA")
    elif s <= math.sqrt(w**2 + h**2):
        print("DA")
    else:
        print("NE")