import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b = map(int, input().split())
    print("TAK" if b % a == 0 else "NIE")