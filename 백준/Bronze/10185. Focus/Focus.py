import sys
input = sys.stdin.readline

for _ in range(int(input())):
    p, q = map(int, input().split())
    print(f"f = {p * q / (p + q):.1f}")