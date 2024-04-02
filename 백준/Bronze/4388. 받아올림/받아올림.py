import sys
input = sys.stdin.readline

while True:
    a, b = map(str, input().split())
    cnt, carry = 0, 0
    if a == b == '0':
        break
    a, b = a.zfill(max(len(a), len(b))), b.zfill(max(len(a), len(b)))
    for i in range(len(a) - 1, -1, -1):
        if int(a[i]) + int(b[i]) + carry >= 10:
            carry = 1
            cnt += carry
        else:
            carry = 0
    print(cnt)