import sys
input = sys.stdin.readline

a = int(input())
res = 0
for i in range(1, a + 1):
    res += i*i*i
print(res)