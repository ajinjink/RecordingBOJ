import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, c = map(int, input().split())
    binn = list(bin(n))[2:]
    print("Valid" if sum(list(map(int, binn))) % 2 == c else "Corrupt")