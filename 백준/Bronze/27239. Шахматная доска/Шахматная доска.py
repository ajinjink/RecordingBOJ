import sys
input = sys.stdin.readline

n = int(input())
print(chr(ord('a') + (n - 1) % 8) + str(int((n - 1)/8 + 1)))