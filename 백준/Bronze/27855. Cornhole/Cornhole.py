import sys
input = sys.stdin.readline

h1, b1 = map(int, input().split())
h2, b2 = map(int, input().split())
p1 = h1 * 3 + b1
p2 = h2 * 3 + b2
if p1 == p2:
    print("NO SCORE")
else:
    print(1 if p1 > p2 else 2, end=' ')
    print(max(p1, p2) - min(p1, p2))