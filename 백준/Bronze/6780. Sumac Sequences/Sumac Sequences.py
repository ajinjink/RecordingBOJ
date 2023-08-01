import sys
input = sys.stdin.readline

a = int(input())
b = int(input())
cnt = 2
while a >= b:
    cnt += 1
    c = a - b
    a = b
    b = c
print(cnt)