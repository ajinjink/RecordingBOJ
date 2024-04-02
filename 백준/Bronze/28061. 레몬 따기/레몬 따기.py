import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
res = [[i, l[i] - (n - i)] for i in range(n)]
res.sort(key=lambda x: -x[1])
print(res[0][1])