import sys
input = sys.stdin.readline

for i in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    print(min(l), max(l))