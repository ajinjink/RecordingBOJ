import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b = input().split()
    if int(b) >= 97:
        res = "A+"
    elif int(b) >= 90:
        res = "A"
    elif int(b) >= 87:
        res = "B+"
    elif int(b) >= 80:
        res = "B"
    elif int(b) >= 77:
        res = "C+"
    elif int(b) >= 70:
        res = "C"
    elif int(b) >= 67:
        res = "D+"
    elif int(b) >= 60:
        res = "D"
    else:
        res = "F"
    print(a, res)