import sys
input = sys.stdin.readline

n = int(input())
l = sorted(list(map(int, input().split())))
print(sum(l[:-1]))