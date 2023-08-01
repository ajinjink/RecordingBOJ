import sys
input = sys.stdin.readline

h = int(input())
m = int(input())
for i in range(1, m + 1):
    if (-6)*(i**4) + h*(i**3) + 2*(i**2) + i <= 0:
        print("The balloon first touches ground at hour:", i)
        exit(0)
print("The balloon does not touch ground in the given time.")