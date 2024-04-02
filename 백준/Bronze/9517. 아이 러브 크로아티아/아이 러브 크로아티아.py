import sys
input = sys.stdin.readline

K = int(input())
l = [list(map(str, input().split())) for _ in range(int(input()))]
t = 0
for i in l:
    if i[1] == "T":
        if t + int(i[0]) < 210:
            t += int(i[0])
            K += 1
            if K == 9:
                K = 1
        else:
            print(K)
            break
    else:
        t += int(i[0])
        if t >= 210:
            print(K)
            break