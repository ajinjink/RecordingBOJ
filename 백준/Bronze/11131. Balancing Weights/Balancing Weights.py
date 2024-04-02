import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    temp = sum(100 * i for i in l)
    if temp == 0:
        print("Equilibrium")
    elif temp > 0:
        print("Right")
    else:
        print("Left")