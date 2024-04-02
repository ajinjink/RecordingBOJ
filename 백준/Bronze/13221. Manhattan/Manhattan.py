import sys
input = sys.stdin.readline


class Taxi:
    def __init__(self, x, y, dist):
        self.x = x
        self.y = y
        self.dist = dist


x, y = map(int, input().split())
tl = []
for i in range(int(input())):
    tx, ty = map(int, input().split())
    dist = abs(x - tx) + abs(y - ty)
    tl.append(Taxi(tx, ty, dist))
tl.sort(key=lambda taxi: taxi.dist)
print(tl[0].x, tl[0].y)