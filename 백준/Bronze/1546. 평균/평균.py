import sys

num = int(sys.stdin.readline())

numbers = list(map(int, sys.stdin.readline().split()))
numbers.sort()


max = numbers[num-1]
for i in range(num):
    numbers[i] = (numbers[i] / max) * 100

sum = 0
for i in range(num):
    sum += numbers[i]

print(sum/num)