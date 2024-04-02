import sys
input = sys.stdin.readline

n = int(input())
o = int(input())
if o - (o // (n - 1)) * (n - 1) == 0:
    print(o + (o // (n - 1)) - 1, o + (o // (n - 1)))
else:
    print(o + (o // (n - 1)), o + (o // (n - 1)))