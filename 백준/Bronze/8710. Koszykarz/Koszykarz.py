import math
import sys
input = sys.stdin.readline

k, w, m = map(int, input().split())
print(math.ceil((w - k) / m))


