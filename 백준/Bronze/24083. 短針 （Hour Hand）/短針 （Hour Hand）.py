import sys
input = sys.stdin.readline

a = int(input())
b = int(input())
print((a + b) % 12 if (a + b) % 12 else 12)