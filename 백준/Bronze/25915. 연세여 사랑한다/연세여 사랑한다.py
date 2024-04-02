import sys
input = sys.stdin.readline

c = input().strip()
print(abs(ord(c) - ord('I')) + 84)