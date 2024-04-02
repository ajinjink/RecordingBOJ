import sys
input = sys.stdin.readline

n = int(input())
l = [input().strip() for _ in range(n)]
l2 = [int(i[:-1])**int(i[-1]) for i in l]
print(sum(l2))