import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

if a > c:
    a, c = c, a
if b > c:
    b, c = c, b

if a*a + b*b == c*c:
    print(1)
elif a == b and b == c:
    print(2)
else:
    print(0)