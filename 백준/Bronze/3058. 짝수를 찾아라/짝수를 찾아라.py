import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    sum, minn = 0, 101
    for i in l:
        if i % 2 == 0:
            sum += i
            minn = min(minn, i)
    print(sum, minn)