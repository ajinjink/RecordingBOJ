import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = max(map(int, input().split()))
b = max(map(int, input().split()))
print(a + b)