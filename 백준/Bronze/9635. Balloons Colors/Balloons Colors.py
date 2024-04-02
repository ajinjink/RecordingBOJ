import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, x, y = map(int, input().split())
    l = list(map(int, input().split()))
    if l[0] == x and l[-1] == y:
        print("BOTH")
    elif l[0] == x:
        print("EASY")
    elif l[-1] == y:
        print("HARD")
    else:
        print("OKAY")