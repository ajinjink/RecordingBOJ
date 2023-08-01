import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    bn = int(bin(n)[2:])
    print(1 if bn & (-bn) == n else 0)