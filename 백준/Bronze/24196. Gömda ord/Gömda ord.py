import sys
input = sys.stdin.readline

s = input().strip()
index = 0
while index < len(s):
    print(s[index], end='')
    index += ord(s[index]) - ord('A') + 1