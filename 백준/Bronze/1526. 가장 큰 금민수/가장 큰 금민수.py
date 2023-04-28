import sys
N = int(sys.stdin.readline())

while N>0:
    strn = str(N)
    flag = True
    for i in strn:
        if (i != '4') and (i != '7'):
            flag = False
            break
    if flag:
        print(N)
        break
    N = N - 1