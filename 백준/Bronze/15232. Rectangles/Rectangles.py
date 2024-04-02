import sys
input = sys.stdin.readline

a = int(input())
b = int(input())

for i in range(a):
    for j in range(b):
        print("*", end='')
    print()