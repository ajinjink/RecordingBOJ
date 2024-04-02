import sys
input = sys.stdin.readline

for i in range(int(input())):
    n = int(input())
    l = [i for i in range(n + 1) if i % 2 == 1]
    print(sum(l))