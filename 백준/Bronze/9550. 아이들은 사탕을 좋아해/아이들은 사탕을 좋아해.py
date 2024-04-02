import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    l = list(map(int, input().split()))
    print(sum([i // k for i in l]))