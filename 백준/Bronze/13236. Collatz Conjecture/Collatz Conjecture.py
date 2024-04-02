import sys
input = sys.stdin.readline


def cc(n):
    l = [n]
    while n > 1:
        n = (n * 3 + 1 if n % 2 == 1 else n // 2)
        l.append(n)
    return l


n = int(input())
res = cc(n)
print(*res)