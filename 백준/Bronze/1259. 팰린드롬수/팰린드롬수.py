import sys

N = str(sys.stdin.readline().strip())

while (N != '0'):
    i = 0
    flag = 1

    for i in range(len(N)//2):
        if (N[i] != N[len(N)-1-i]):
            flag = 0
            break
        else:
            pass

    if flag == 1:
        print("yes")
    else:
        print("no")
    
    N = str(sys.stdin.readline().strip())