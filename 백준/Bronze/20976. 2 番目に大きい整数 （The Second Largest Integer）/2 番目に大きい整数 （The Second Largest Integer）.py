import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
l.sort()
print(l[1])