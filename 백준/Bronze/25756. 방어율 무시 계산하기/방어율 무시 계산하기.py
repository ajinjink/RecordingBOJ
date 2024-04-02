import sys
input = sys.stdin.readline

n = int(input())
v = 0
for i in map(int, input().split()):
    a = 1 - (v / 100)
    b = 1 - (i / 100)
    v = (1 - a*b) * 100
    print(v)