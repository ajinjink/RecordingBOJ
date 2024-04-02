import sys
input = sys.stdin.readline

l = [int(input()) for _ in range(4)]

if l[0] == 8 or l[0] == 9:
    if l[3] == 8 or l[3] == 9:
        if l[1] == l[2]:
            print("ignore")
        else:
            print("answer")
    else:
        print("answer")
else:
    print("answer")