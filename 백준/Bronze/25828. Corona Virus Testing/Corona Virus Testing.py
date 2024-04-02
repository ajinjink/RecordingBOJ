import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())
c1 = a + c*b

if a * b < c1:
    print(1)
elif a * b > c1:
    print(2)
else:
    print(0)