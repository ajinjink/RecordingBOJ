import sys
input = sys.stdin.readline

n = input().strip()
A = 0
B = 0
for i in range(len(n) // 2):
    if n[i * 2] == 'A':
        A += int(n[i * 2 + 1])
    else:
        B += int(n[i * 2 + 1])
print('A' if A > B else 'B')