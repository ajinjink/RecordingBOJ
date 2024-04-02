import sys
input = sys.stdin.readline

while True:
    l = sorted(list(map(int, input().split())))
    if sum(l) == 0:
        break
    print(sum(l[1:5]) // 4 if sum(l[1:5]) % 4 == 0 else sum(l[1:5]) / 4)