import sys
input = sys.stdin.readline

while True:
    l = list(map(str, input().split()))
    if l[0] == '0' and l[1] == 'W' and l[2] == '0':
        break
    res = 0
    if l[1] == 'W':
        res = int(l[0]) - int(l[2])
    else:
        res = int(l[0]) + int(l[2])
    if res < -200:
        print("Not allowed")
    else:
        print(res)