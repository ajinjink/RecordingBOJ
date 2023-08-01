import sys
input = sys.stdin.readline

k = int(input())
for i in range(1, k):
    if 1 + i + i**2 == k:
        print(i)
        exit(0)