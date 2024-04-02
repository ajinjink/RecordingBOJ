import sys
input = sys.stdin.readline

n, T = map(int, input().split())
l = list(map(int, input().split()))
sum = 0
for i in range(n):
    sum += l[i]
    if sum > T:
        print(i)
        exit(0)
print(n)