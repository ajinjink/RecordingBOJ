import sys

N = int(sys.stdin.readline())

count = 0
sss = 666
while (1):
    if '666' in str(sss):
        count += 1
    if count == N:
        print(sss)
        break
    sss += 1