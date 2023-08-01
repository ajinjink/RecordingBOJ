import sys
input = sys.stdin.readline

while 1:
    l = list(map(int, input().split()))
    if l[0] == 0:
        break
    n = 1
    for i in range(l[0]):
        n = n * l[2 * i + 1] - l[2 * i + 2]
    print(n)