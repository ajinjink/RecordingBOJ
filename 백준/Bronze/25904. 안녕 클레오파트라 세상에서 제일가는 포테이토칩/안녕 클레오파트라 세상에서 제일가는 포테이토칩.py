import sys
input = sys.stdin.readline

n, x = map(int, input().split())
l = list(map(int, input().split()))
while True:
    for i in range(n):
        if l[i] >= x:
            x += 1
        else:
            print(i + 1)
            exit()