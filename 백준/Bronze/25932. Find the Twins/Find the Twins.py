import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    l = list(map(int, input().split()))
    for i in l:
        print(i, end=' ')
    print()
    if 18 in l and 17 in l:
        print("both")
    elif 18 in l:
        print("mack")
    elif 17 in l:
        print("zack")
    else:
        print("none")
    print()