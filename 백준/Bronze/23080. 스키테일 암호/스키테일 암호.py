import sys
input = sys.stdin.readline

k = int(input())
s = input().strip()
for i in range(0, len(s), k):
    print(s[i], end='')