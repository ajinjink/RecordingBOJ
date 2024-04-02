import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
b = 100
prevp = -1
prevu = 0
for i in range(n):
    if l[i] != prevp:
        b -= 2
        prevu = 2
    else:
        b -= prevu * 2
        prevu *= 2
    prevp = l[i]
    if b <= 0:
        b = 100
        prevp = -1
        prevu = 0
print(100 - b)