import sys
input = sys.stdin.readline

flag = 1
for t in range(5):
    name = input().strip()
    if "FBI" in name:
        print(t + 1, end=' ')
        flag = 0
if flag:
    print("HE GOT AWAY!")