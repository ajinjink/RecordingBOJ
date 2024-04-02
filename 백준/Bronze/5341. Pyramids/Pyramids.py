import sys
input = sys.stdin.readline

def res(n):
    ret = 0
    for i in range(1, n + 1):
        ret += i
    return ret

while(1):
    a = int(input())

    if a == 0:
        break
        
    print(res(a))