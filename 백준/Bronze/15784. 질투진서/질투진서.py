import sys
input = sys.stdin.readline

n, a, b = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(n)]
if l[a-1][b-1] < max([l[i][b-1] for i in range(n)]) or l[a-1][b-1] < max([l[a-1][j] for j in range(n)]):
    print("ANGRY")
else:
    print("HAPPY")