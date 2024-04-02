import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    num = 0
    score = 0
    for _ in range(n):
        a, b = map(float, input().split())
        num += a
        score += a * b
    print(int(num), f"{(score / num):.1f}")