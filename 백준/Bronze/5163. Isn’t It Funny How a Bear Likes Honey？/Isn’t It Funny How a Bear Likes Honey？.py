import math
import sys
input = sys.stdin.readline

k = int(input())
for i in range(k):
    b, w = map(float, input().split())
    total = 0
    for j in range(int(b)):
        r = float(input())
        total += 4.0 / 3.0 * math.pi * r**3 / 1000
    print(f"Data Set {i + 1}:")
    print("Yes" if total >= w else "No")
    print()