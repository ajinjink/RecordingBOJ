import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    l = list(map(str, input().split()))
    if l[1] == "kg":
        print(f"{float(l[0]) * 2.2046:.4f} lb")
    elif l[1] == "lb":
        print(f"{float(l[0]) * 0.4536:.4f} kg")
    elif l[1] == "l":
        print(f"{float(l[0]) * 0.2642:.4f} g")
    elif l[1] == "g":
        print(f"{float(l[0]) * 3.7854:.4f} l")