import sys
input = sys.stdin.readline

n = float(input())
print(f"{100 / ((1.609344 / 3.785411784) * n):.6f}")