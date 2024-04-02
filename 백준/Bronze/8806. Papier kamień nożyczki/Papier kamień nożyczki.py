import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l1 = list(map(float, input().split()))
    l2 = list(map(float, input().split()))
    a = l1[0]*l2[1] + l1[1]*l2[2] + l1[2]*l2[0]
    g = l2[0]*l1[1] + l2[1]*l1[2] + l2[2]*l1[0]
    if a == g:
        print('=')
    else:
        print("ADAM" if a > g else "GOSIA")