import sys
input = sys.stdin.readline

n = int(input())
res = 0
for i in range(1, 500):
    for j in range(1, 500):
        if j**2 == i**2 + n:
            res += 1
print(res)