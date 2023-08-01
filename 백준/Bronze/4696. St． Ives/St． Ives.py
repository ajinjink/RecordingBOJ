import sys
input = sys.stdin.readline

while True:
    a = float(input())
    if a == 0:
        break
    print(f"{(1 + a + a*a + a*a*a + a*a*a*a):.2f}")
