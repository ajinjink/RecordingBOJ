import sys
input = sys.stdin.readline

l = sorted(list(map(int, input().split())))
print(2*l[2] - l[0] - l[1])