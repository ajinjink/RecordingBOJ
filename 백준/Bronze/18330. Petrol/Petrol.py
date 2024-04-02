import sys
input = sys.stdin.readline

n = int(input())
k = int(input()) + 60
print(1500*n if n <= k else 1500*k + 3000*(n - k))