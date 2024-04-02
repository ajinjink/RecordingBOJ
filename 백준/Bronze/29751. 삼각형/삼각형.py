import sys
input = sys.stdin.readline

w, h = map(int, input().split())
print(f"{w * h * 0.5:.1f}")
