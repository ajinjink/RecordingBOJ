import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = list(map(int, input().split()))
    print(f"Case #{(i + 1):d}: {max(l):d}")