import sys
input = sys.stdin.readline

for i in range(int(input())):
    max_x, min_x, max_y, min_y = -1000, 1000, -1000, 1000
    for _ in range(int(input())):
        x, y = map(float, input().split())
        max_x = max(max_x, x)
        max_y = max(max_y, y)
        min_x = min(min_x, x)
        min_y = min(min_y, y)
    print(f"Case {i + 1}:", end=' ')
    h = max_y - min_y
    w = max_x - min_x
    a = h * w
    p = 2 * (h + w)
    print(f"Area {a}, Perimeter {p}")