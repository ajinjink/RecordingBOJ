import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print("NO BRAINS" if a < b else "MMM BRAINS")