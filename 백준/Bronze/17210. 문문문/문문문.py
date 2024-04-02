import sys
input = sys.stdin.readline

n = int(input())
a = int(input())
if n <= 5:
    for i in range(n - 1):
        a = not a
        print(int(a))
else:
    print("Love is open door")