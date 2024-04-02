import sys
input = sys.stdin.readline


def calc(sa, op, sb):
    a = int(sa)
    b = int(sb)
    if op == '+':
        return a + b
    if op == '-':
        return a - b
    if op == '*':
        return a * b
    if op == '/':
        if a * b < 0:
            return -1 * (abs(a) // abs(b))
        else:
            return a // b


s = input().strip().split()
temp = calc(s[0], s[1], s[2])
res1 = calc(str(temp), s[3], s[4])
temp = calc(s[2], s[3], s[4])
res2 = calc(s[0], s[1], str(temp))
print(min(res1, res2))
print(max(res1, res2))