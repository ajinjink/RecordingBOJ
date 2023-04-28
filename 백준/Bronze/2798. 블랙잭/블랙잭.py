import sys

N, M = map(int, sys.stdin.readline().split())

num = list(map(int, sys.stdin.readline().split()))
    
res = []

for i in range(len(num) - 2):
    for j in range(i+1, len(num) - 1):
        for k in range (j + 1, len(num)):
            temp = num[i] + num[j] + num[k]
            if temp <= M:
                res.append(temp)

print(max(res))