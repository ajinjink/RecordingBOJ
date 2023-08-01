import sys
input = sys.stdin.readline

N = int(input())
l = list(map(int, input().split()))
y, m = 0, 0
for i in l:
    y += 10 * (i // 30 + [1, 0][(i + 1) % 30 == 0])
    m += 15 * (i // 60 + [1, 0][(i + 1) % 60 == 0])
if y == m:
    print("Y M", y)
else:
    print(f"M {m}" if m < y else f"Y {y}")