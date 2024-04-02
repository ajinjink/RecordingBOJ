import sys
input = sys.stdin.readline

n = int(input())
res = 0
for _ in range(n):
    s = input().strip()
    flag = 1
    if 'CD' in s:
        flag = 0
    if flag:
        res += 1
print(res)