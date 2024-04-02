import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = input().strip()
    res = sum([int(i) for i in n])
    res += int(n[10:]) * 10
    if res > 9999:
        print(str(res % 10000).zfill(4))
    elif res < 1000:
        print(res + 1000)
    else:
        print(res)