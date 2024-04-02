import sys
input = sys.stdin.readline

a = int(input())
b = int(input())
print(2 * (a + b) - 4 if a != 1 and b != 1 else a + b - 1)