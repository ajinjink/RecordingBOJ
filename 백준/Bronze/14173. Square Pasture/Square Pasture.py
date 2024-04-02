import sys
input = sys.stdin.readline

x1, y1, x2, y2 = map(int, input().split())
x11, y11, x22, y22 = map(int, input().split())
r1 = max(x2, x22) - min(x1, x11)
r2 = max(y2, y22) - min(y1, y11)
print(max(r1, r2)**2)