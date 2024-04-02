import sys
input = sys.stdin.readline

for i in range(int(input())):
    a, b = map(int, input().split())
    c = a / b
    cnt = 0
    while c > 5:
        c /= 5
        cnt += 1
    print(f"Data Set {i + 1}:")
    if a <= b:
        print("no drought")
    else:
        print("mega " * cnt + "drought")
    print()