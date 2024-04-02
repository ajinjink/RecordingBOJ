import sys
input = sys.stdin.readline

a = int(input())
b = int(input())
l1 = [input().strip() for _ in range(a)]
l2 = [input().strip() for _ in range(b)]
for i in l1:
    for j in l2:
        print(i, "as", j)