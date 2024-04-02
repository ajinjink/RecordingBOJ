import sys
input = sys.stdin.readline

n = int(input())
l = [2**i for i in range(31)]
print(1 if n in l else 0)