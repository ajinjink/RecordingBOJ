import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    a, b, c = map(str, input().split())
    s = ''.join(a[i] for i in range(len(a)) if not int(b) <= i < int(c))
    print(s)