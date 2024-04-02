import sys
input = sys.stdin.readline

n = int(input())
l = [0] * 2
for _ in range(n):
    c = input().strip()
    l[c == 'P'] += 1
    if abs(l[0] - l[1]) >= 2:
        break
print(f"{l[0]}:{l[1]}")