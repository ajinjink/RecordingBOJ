import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()
    l = [0] * 4
    for c in s:
        if c == 'N': l[0] += 1
        if c == 'S': l[1] += 1
        if c == 'W': l[2] += 1
        if c == 'E': l[3] += 1
    print(abs(l[0] - l[1]) + abs(l[2] - l[3]))