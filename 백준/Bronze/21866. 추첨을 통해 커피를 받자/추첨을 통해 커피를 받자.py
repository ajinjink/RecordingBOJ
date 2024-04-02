import sys
input = sys.stdin.readline

l = [100, 100, 200, 200, 300, 300, 400, 400, 500]
score = list(map(int, input().split()))
total = 0
flag = False
for i in range(9):
    if score[i] > l[i]:
        flag = True
    total += score[i]
if flag:
    print("hacker")
else:
    print("draw" if total >= 100 else "none")