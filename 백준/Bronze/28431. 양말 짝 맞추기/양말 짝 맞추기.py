import sys
input = sys.stdin.readline

l = [int(input()) for _ in range(5)]

for i in l:
    if l.count(i) % 2 == 1:
        print(i)
        break