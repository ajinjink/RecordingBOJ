import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    l = sorted(list(map(int, input().split())))
    print(l[0])