import sys
input = sys.stdin.readline

for i in range(int(input())):
    im, iy = map(int, input().split())
    sm, sy = map(int, input().split())
    res = 0.0
    if iy == sy:
        res += 0.5 * (sm - im) / (12.0 - im + 1)
    else:
        res += 0.5 + (sy - iy - 1) + (sm - 1) / 12.0
    print(f"{res:.4f}")