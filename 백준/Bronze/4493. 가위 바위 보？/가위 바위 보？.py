import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    p1, p2 = 0, 0
    for _ in range(n):
        a, b = input().split()
        if a == b:
            pass
        elif (a=='R' and b=='S') or (a=='S' and b=='P') or (a=='P' and b=='R'):
            p1 += 1
        else:
            p2 += 1
    if p1 == p2:
      print("TIE")
    else:
      print("Player 1" if p1 > p2 else "Player 2")