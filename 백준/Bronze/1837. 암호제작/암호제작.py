import sys
input = sys.stdin.readline

p, k = map(int, input().split())
flag = 1
for i in range(2, k):
    if p % i == 0:
        print("BAD", i)
        flag = 0
        break
if flag:
    print("GOOD")