import sys
input = sys.stdin.readline

l = sorted(list(map(int, input().split())))
print(max(l[1] - l[0] - 1, l[2] - l[1] - 1))