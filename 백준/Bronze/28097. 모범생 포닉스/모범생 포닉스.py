import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
h = sum(l) + 8 * (len(l) - 1)
print(h // 24, h % 24)