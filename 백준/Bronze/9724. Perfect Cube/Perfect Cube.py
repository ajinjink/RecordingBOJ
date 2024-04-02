import sys
input = sys.stdin.readline

for i in range(int(input())):
    a, b = map(int, input().split())
    print(f"Case #{i + 1}: {int(b**(1/3)) - int((a - 1)**(1/3))}")