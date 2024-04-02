import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l = []
    for _ in range(int(input())):
        temp = list(map(int, input().split()))
        l.append(temp)
    money = list(map(int, input().split()))
    total = 0
    for i in l:
        temp = i[0]*money[0] + i[2]*money[2] - i[1]*money[1]
        if temp > 0:
            total += temp
    print(total)