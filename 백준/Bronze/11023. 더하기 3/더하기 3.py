import sys

n = list(map(int,sys.stdin.readline().split()))

sum = 0

for i in range(len(n)):
    sum += n[i]

print(sum)