import sys
input = sys.stdin.readline

a = int(input())
stu = [input() for _ in range(a)]
ans = [input() for _ in range(a)]
cnt = 0
for i in range(a):
    if stu[i] == ans[i]:
        cnt += 1
print(cnt)