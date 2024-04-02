import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    num, a, b, c = map(int, input().split())
    sum = a + b + c
    flag = 1
    if sum < 55:
        flag = 0
    else:
        if a < 35*0.3 or b < 25*0.3 or c < 40*0.3:
            flag = 0

    if flag:
        print(num, sum, "PASS")
    else:
        print(num, sum, "FAIL")