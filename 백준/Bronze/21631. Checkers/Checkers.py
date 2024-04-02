import sys
input = sys.stdin.readline

a, b = map(int, input().split())
print(b if a >= b else a + 1)