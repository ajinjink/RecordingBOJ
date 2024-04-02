import sys
input = sys.stdin.readline

str = input().strip()

for i in range(len(str) - 1, -1, -1):
    print(str[i], end='')