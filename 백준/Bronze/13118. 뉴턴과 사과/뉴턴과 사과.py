import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
x, y, r = map(int, input().split())

flag = 0
for i in range(len(l)):
    if l[i] == x:
        print(i + 1)
        flag = 1
if flag == 0:
    print(0)