import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
print(abs((l[0] + l[3]) - (l[1] + l[2])))