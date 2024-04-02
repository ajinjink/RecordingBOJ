import sys
input = sys.stdin.readline

for _ in range(int(input())):
    y, m = map(int, input().split())
    l = []
    if (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0):
        l = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    else:
        l = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if m == 1:
        print(y - 1, 12, l[m + 10])
    else:
        print(y, m - 1, l[m - 2])