import sys
input = sys.stdin.readline

while 1:
    n = input().strip()
    if n == '0':
        break
    d = 0
    for c in n:
        d += int(c)
    while d >= 10:
        temp = 0
        for c in str(d):
            temp += int(c)
        d = temp
    print(d)