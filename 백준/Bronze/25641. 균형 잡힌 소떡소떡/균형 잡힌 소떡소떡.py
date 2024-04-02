import sys
input = sys.stdin.readline

n = int(input())
l = list(input().strip())
while True:
    if l.count('s') == l.count('t'):
        break
    else:
        l.remove(l[0])
print(''.join(l))