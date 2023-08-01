import sys
input = sys.stdin.readline

xl = []
yl = []
for _ in range(3):
    x, y = map(int, input().split())
    xl.append(x)
    yl.append(y)
for i in xl:
    if xl.count(i) == 1:
        print(i, end=' ')
        break
for i in yl:
    if yl.count(i) == 1:
        print(i, end=' ')