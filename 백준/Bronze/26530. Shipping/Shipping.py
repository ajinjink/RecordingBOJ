import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    money = 0
    for _ in range(int(input())):
        s = list(map(str, input().strip().split()))
        money += float(s[1]) * float(s[2])
    print(f"${money:.2f}")