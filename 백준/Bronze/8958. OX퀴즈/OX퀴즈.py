import sys

T = int(sys.stdin.readline())
for _ in range(T):
    A = str(sys.stdin.readline())
    A_len = len(A) - 1
    point = 0
    sum = 0
    for i in range (A_len):
        if A[i] == 'O':
            point = point + 1
        else:
            point = 0
        sum = sum + point
    print(sum)
    