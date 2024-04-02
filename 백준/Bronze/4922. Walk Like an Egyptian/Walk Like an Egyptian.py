import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    sum, cnt = 0, 1
    for _ in range(n):
        sum += cnt
        cnt += 2
    print(f"{n} => {sum - n + 1}")