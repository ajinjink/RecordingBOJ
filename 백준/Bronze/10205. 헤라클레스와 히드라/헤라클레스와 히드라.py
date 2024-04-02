import sys
input = sys.stdin.readline

for i in range(int(input())):
    h = int(input())
    for c in input().strip():
        if c == 'c':
            h += 1
        else:
            h -= 1
    print(f"Data Set {i + 1}:")
    print(h)
    print()