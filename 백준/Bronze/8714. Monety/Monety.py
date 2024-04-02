import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
cnt = l.count(1)
print(min(cnt, n - cnt))