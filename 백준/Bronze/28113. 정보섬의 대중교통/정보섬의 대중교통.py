import sys
input = sys.stdin.readline

n, a, b = map(int, input().split())

if a > b:
    print("Subway")
if a == b:
    print("Anything")
if a < b:
    print("Bus")
