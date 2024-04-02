import sys
input = sys.stdin.readline

a = int(input())
b = int(input())

y = a
while y <= b:
    print(f"All positions change in year {y}")
    y += 60

