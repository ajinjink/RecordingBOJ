import sys
input = sys.stdin.readline

a = int(input())
for i in range(1, a + 1):
    if i % 6 == 0:
        print(i, "Go!", end=' ')
    else:
        print(i, end=' ')

if a % 6 != 0:
    print("Go!")