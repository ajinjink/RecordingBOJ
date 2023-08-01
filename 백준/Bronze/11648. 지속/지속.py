import sys
input = sys.stdin.readline


def f(s):
    ret = 1
    if s == "0":
        return 0
    for c in s:
        ret *= int(c)
    return ret


s = input().strip()
res = 0
while True:
    if len(s) == 1:
        break
    res += 1
    num = f(s)
    s = str(num)

print(res)