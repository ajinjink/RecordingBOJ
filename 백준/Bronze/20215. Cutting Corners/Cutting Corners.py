import math
import sys
input = sys.stdin.readline

w, h = map(int, input().split())

print(abs((w + h) - (math.sqrt(w*w + h*h))))