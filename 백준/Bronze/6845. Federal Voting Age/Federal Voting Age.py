import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    y, m, d = map(int, input().split())
    if y < 1989:
        print("Yes")
        continue
    if y == 1989 and m < 2:
        print("Yes")
        continue
    if y == 1989 and m == 2 and d <= 27:
        print("Yes")
        continue
    print("No")