import math
import sys
input = sys.stdin.readline

i = 1
while 1:
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    print(f"Triangle #{i}")
    if c == -1:
        print(f"c = {math.sqrt(a**2 + b**2):.3f}")
    elif max(a, b) >= c:
        print("Impossible.")
    elif a == -1:
        print(f"a = {math.sqrt(c**2 - b**2):.3f}")
    elif b == -1:
        print(f"b = {math.sqrt(c**2 - a**2):.3f}")
    print()
    i += 1