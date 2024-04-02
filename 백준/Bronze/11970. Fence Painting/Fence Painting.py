import sys
input = sys.stdin.readline

a, b = map(int, input().split())
c, d = map(int, input().split())
print(b - a + d - c if c >= b or d <= a else max(b, d) - min(a, c))