import sys
input = sys.stdin.readline

a, b = map(int, input().split())
l = []
for i in range(1, a + 1):
    if a % i == 0:
        l.append(i)
print(l[b - 1] if len(l) >= b else 0)