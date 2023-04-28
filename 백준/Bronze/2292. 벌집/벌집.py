import sys

N = int(sys.stdin.readline())

num = []
sum = 1
for i in range(18258):
    sum = sum + 6 * i
    num.append(sum)

for i in range(18258):
    if N == 1:
        print(1)
        break
    if num[i] < N <= num[i+1]:
        print(i+2)
        break