import math
import sys
input = sys.stdin.readline

res = 0
for _ in range(int(input())):
    l = list(map(str, input().split()))
    if l[0] == 'S':
        res = max(res, (4 / 3) * math.pi * float(l[1])**3)
    elif l[0] == 'C':
        res = max(res, (1 / 3) * math.pi * float(l[1])**2 * float(l[2]))
    else:
        res = max(res, math.pi * float(l[1])**2 * float(l[2]))
print(f"{res:.3f}")