import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    l = list(map(int, input().split()))
    j, m = 0, 0
    for i in l:
        if i == 1:
            j += 1
        else:
            m += 1
    print(f"Mary won {m} times and John won {j} times")