import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l = list(map(int, input().split()))[1:]
    res = [0] * 2
    for i in l:
        res[i % 2] += i
    if res[0] == res[1]:
        print("TIE")
    else:
        print("EVEN" if res[0] > res[1] else "ODD")