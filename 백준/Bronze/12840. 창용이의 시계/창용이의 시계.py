import sys
input = sys.stdin.readline

h, m, s = map(int, input().split())
for _ in range(int(input())):
    l = list(map(int, input().split()))
    if len(l) == 1 and l[0] == 3:
        print(h, m, s)
    else:
        t = h*3600 + m*60 + s
        if l[0] == 1:
            t += l[1]
        else:
            t -= l[1]
        t %= 86400
        if t < 0:
            t += 86400
        h, m, s = t // 3600, (t % 3600)//60, t % 60