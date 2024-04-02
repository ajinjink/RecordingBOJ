import sys
input = sys.stdin.readline

table = [list(map(int, input().split())) for _ in range(9)]
n = 0
row, col = 0, 0
for r in range(9):
    for c in range(9):
        if n <= table[r][c]:
            row = r + 1
            col = c + 1
            n = table[r][c]
print(n)
print(row, col)