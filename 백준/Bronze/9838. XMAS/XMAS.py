import sys
input = sys.stdin.readline

n = int(input())
l = [0] * (n + 1)
for i in range(n):
    l[int(input())] = i + 1
for i in range(n):
    print(l[i + 1])