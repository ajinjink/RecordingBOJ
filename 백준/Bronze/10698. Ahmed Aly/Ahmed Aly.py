import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = input().split()
    res = "NO"
    if l[1] == '+' and int(l[0]) + int(l[2]) == int(l[4]):
        res = "YES"
    if l[1] == '-' and int(l[0]) - int(l[2]) == int(l[4]):
        res = "YES"
    print(f"Case {i + 1}: {res}")