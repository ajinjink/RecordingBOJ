import sys
input = sys.stdin.readline

n = input().strip()
flag = 1
for i in range(3):
    if n[i] != '5':
        flag = 0

print("YES" if flag else "NO")