import sys
input = sys.stdin.readline

n = int(input())
s1 = input()
s2 = input()
cnt = 0
for i in range(n):
    if s1[i] == s2[i]:
        cnt += 1
print(cnt)