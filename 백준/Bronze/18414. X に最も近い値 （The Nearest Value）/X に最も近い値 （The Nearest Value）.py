import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

if b <= a <= c:
    print(a)
else:
    print(b if a < b else c)