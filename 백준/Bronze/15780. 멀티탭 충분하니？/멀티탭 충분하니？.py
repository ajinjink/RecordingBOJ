import sys
input = sys.stdin.readline

n, k = map(int, input().split())
l = list(map(int, input().split()))
cnt = sum([(i+1) // 2 for i in l])
print("YES" if cnt >= n else "NO")