import sys
input = sys.stdin.readline

for i in range(int(input())):
    n = int(input())
    l = [int(input()) for _ in range(n)]
    res = [i + 1 for i in l if i < 6]
    print(f"Case {i + 1}:")
    for j in res:
        print(j)