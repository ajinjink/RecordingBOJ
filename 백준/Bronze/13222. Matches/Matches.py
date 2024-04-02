import sys
input = sys.stdin.readline

n, w, h = map(int, input().split())
for _ in range(n):
    l = int(input())
    print("YES" if l*l <= w*w + h*h else "NO")