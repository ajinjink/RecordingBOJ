import sys

N, M = map(int, sys.stdin.readline().split())
board = []

for i in range(N):
    board.append(list(sys.stdin.readline()))
    board[i].remove('\n')

res = []
for i in range(N-7):
    for j in range(M-7):
        count1 = 0
        count2 = 0
        for a in range(i, i + 8):
            for b in range(j, j + 8):
                if (a + b) % 2 == 0:
                    if board[a][b] != 'B':
                        count1 += 1
                    if board[a][b] != 'W':
                        count2 += 1
                else:
                    if board[a][b] != 'W':
                        count1 += 1
                    if board[a][b] != 'B':
                        count2 += 1
        res.append(count1)
        res.append(count2)

print(min(res))