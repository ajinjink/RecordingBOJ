import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
l.sort()
print(1 if l[1] == 1 else 2)