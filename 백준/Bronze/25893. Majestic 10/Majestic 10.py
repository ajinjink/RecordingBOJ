import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b, c = map(int, input().split())
    num = 0
    if a >= 10:
        num += 1
    if b >= 10:
        num += 1
    if c >= 10:
        num += 1
    print(a, b, c)
    if num == 3:
        print("triple-double")
    elif num == 2:
        print("double-double")
    elif num == 1:
        print("double")
    else:
        print("zilch")
    print()