import sys
input = sys.stdin.readline

M, S, G = map(float, input().split())
A, B = map(float, input().split())
L, R = map(float, input().split())

# 시간 계산
lw = L / A
rw = R / B

lv = M/G + 1 if M % G else M/G
rv = M/S + 1 if M % S else M/S

if lv + lw < rv + rw:
    print("friskus")
else:
    print("latmask")