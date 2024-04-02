import sys
input = sys.stdin.readline

while True:
    a = int(input())
    if a == 0:
        break
    for i in range(1, a + 1):
        for j in range(i):
            print('*', end='')
        print()
