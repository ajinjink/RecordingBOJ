import sys
input = sys.stdin.readline

pl, nl = [], []
n = int(input())
exp = int(input())
l = list(map(int, input().split()))
for i in l:
    if i > 0:
        pl.append(i)
    else:
        nl.append(i)
res = 0
for i in pl:
    res += i ** exp
if exp % 2 == 0:
    for i in nl:
        res += i ** exp
print(res)