import sys
input = sys.stdin.readline

while True:
    M, A, B = map(float, input().split())
    if M == A == B == 0:
        break
    t = round((M / A - M / B) * 3600)
    h = t // 3600
    m = (t % 3600) // 60
    s = t % 60
    print(f"{h}:{m:02d}:{s:02d}")