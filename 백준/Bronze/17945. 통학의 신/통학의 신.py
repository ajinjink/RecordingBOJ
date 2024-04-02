import math
import sys
input = sys.stdin.readline

a, b = map(int, input().split())
l = [-a + int(math.sqrt(a**2 - b)), -a - int(math.sqrt(a**2 - b))]
if l[0] == l[1]:
    print(l[0])
else:
    print(*sorted(l))