import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s1 = n * (n + 1) // 2
    s2 = (n * 2) * (n / 2)
    s3 = (n * 2 + 2) * (n / 2)
    print(s1, int(s2), int(s3))