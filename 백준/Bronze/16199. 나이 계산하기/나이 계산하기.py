import sys
input = sys.stdin.readline

y1, m1, d1 = map(int, input().split())
y2, m2, d2 = map(int, input().split())

a1 = 0
if m1 < m2:
    a1 = y2 - y1
elif m1 == m2:
    if d1 <= d2:
        a1 = y2 - y1
    else:
        a1 = y2 - y1 - 1
else:
    a1 = y2 - y1 - 1
a2 = y2 - y1 + 1
a3 = y2 - y1

print(a1)
print(a2)
print(a3)