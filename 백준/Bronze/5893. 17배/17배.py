import sys
input = sys.stdin.readline

s = input().strip()
n = int(s, 2)
n *= 17
print(bin(n)[2:])