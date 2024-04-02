import sys
input = sys.stdin.readline

for _ in range(3):
    l = list(map(int, input().split()))
    if sum(l) == 0:
        print("D")
    if sum(l) == 1:
        print("C")
    if sum(l) == 2:
        print("B")
    if sum(l) == 3:
        print("A")
    if sum(l) == 4:
        print("E")