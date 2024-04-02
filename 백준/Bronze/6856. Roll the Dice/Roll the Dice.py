import sys
input = sys.stdin.readline

a = int(input())
b = int(input())
cnt = 0
for i in range(1, a + 1):
    for j in range(1, b + 1):
        if i + j == 10:
            cnt += 1
print(f"There are {cnt} ways to get the sum 10." if cnt != 1 else "There is 1 way to get the sum 10.")