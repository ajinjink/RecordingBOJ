import sys
input = sys.stdin.readline

p = int(input())
c = int(input())
print(50*p - 10*c + 500 if p > c else 50*p - 10*c)