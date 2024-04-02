import sys
input = sys.stdin.readline

while True:
    n = float(input())
    if n == 0:
        break
    cnt, temp, i = 1, 0, 1
    while True:
        temp += 1.0 / (i + 1)
        if temp >= n:
            cnt = i
            break
        i += 1
    print(cnt, "card(s)")