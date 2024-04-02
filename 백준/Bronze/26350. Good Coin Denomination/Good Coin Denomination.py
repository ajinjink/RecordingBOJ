import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    l = list(map(int, input().split()))
    print("Denominations: ", end='')
    flag = 1
    for i in range(1, len(l)):
        print(l[i], end=' ')
        if i < len(l) - 1 and l[i + 1] < l[i] * 2:
            flag = 0
    print()
    if flag:
        print("Good coin denominations!")
    else:
        print("Bad coin denominations!")
    print()