import sys
input = sys.stdin.readline

res = 0
for i in range(int(input())):
    res += 1
    if '50' in str(i):
        res += 1
print(res)