import sys
input = sys.stdin.readline

a, b = map(int, input().split())

if a == 0 and b == 0:
    print("Not a moose")
elif a == b:
    print("Even", a + b)
else:
    print("Odd", max(a, b) * 2)