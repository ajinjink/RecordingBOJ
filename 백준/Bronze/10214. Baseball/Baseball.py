import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = [list(map(int, input().split())) for _ in range(9)]
    y, k = 0, 0
    for s in l:
        y += s[0]
        k += s[1]
    if y == k:
        print("Draw")
    else:
        print("Yonsei" if y > k else "Korea")