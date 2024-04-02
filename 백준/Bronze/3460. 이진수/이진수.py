import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    bn = bin(n)
    for i in range(len(bn)):
        if bn[-i -1] == '1':
            print(i, end=' ')