import sys
input = sys.stdin.readline

for i in range(int(input())):
    n, m = map(int, input().split())
    print(f"Case {i + 1}: {m - n + 1}")