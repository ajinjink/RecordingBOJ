import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b = map(float, input().split())
    print("golden" if 1.61803399 * 0.99 <= a / b <= 1.61803399 * 1.01 else "not")