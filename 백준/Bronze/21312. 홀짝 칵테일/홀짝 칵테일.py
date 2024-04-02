import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
odd = [i for i in l if i % 2]
res = 1
if not odd:
    print(l[0] * l[1] * l[2])
    exit()
for i in odd:
    res *= i
print(res)