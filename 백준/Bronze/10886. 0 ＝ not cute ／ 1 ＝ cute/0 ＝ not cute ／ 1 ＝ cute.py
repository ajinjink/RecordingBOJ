import sys
input = sys.stdin.readline

y, n = 0, 0
for _ in range(int(input())):
    if int(input()) == 1:
        y += 1
    else:
        n += 1
print("Junhee is cute!" if y > n else "Junhee is not cute!")