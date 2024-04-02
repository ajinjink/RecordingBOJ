import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l = list(map(int, input().split()))[1:]
    r = [0] * 8
    for i in range(len(l)):
        if i % 2:
            r[l[i] - 1] += 1
    print(max(r))