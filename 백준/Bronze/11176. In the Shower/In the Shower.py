import sys
input = sys.stdin.readline

for _ in range(int(input())):
    e, n = map(int, input().split())
    l = [int(input()) for _ in range(n)]
    cnt = 0
    for i in l:
        if i > e:
            cnt += 1
    print(cnt)