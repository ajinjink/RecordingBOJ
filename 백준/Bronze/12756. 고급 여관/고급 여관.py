import sys
input = sys.stdin.readline

a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())
a = a2 // b1 + [1, 0][a2 % b1 == 0]
b = b2 // a1 + [1, 0][b2 % a1 == 0]
if a == b:
    print("DRAW")
elif a > b:
    print("PLAYER A")
else:
    print("PLAYER B")