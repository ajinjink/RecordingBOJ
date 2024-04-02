import sys
input = sys.stdin.readline

n = int(input())
if n * 0.01 + 25 < 100:
    print(f"{(100):.2f}")
elif n * 0.01 + 25 > 2000:
    print(f"{(2000):.2f}")
else:
    print(f"{(n * 0.01 + 25):.2f}")