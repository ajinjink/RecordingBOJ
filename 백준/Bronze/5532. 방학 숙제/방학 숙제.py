import sys
input = sys.stdin.readline

l = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())

math = b // d
if b % d:
    math += 1
lit = a // c
if a % c:
    lit += 1

print(l - max(math, lit))