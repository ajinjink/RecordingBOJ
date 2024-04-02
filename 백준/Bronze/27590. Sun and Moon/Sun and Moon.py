import sys
input = sys.stdin.readline

ds, ys = map(int, input().split())
dm, ym = map(int, input().split())
sun = ys - ds
moon = ym - dm

while sun != moon:
    if sun < moon:
        sun += ys
    else:
        moon += ym
print(sun)