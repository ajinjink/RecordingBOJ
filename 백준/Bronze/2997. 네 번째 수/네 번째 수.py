import sys
input = sys.stdin.readline

l = sorted(list(map(int, input().split())))
d1 = l[1] - l[0]
d2 = l[2] - l[1]
if d1 > d2:
    print(l[0] + d2)
elif d1 == d2:
    print(l[2] + d1)
else:
    print(l[1] + d1)