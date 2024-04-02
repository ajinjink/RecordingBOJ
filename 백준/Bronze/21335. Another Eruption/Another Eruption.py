import math
import sys
input = sys.stdin.readline

area = int(input())
r = math.sqrt(area / math.pi)
print(2 * r * math.pi)