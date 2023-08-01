import sys
input = sys.stdin.readline

for _ in range(int(input())):
    k, n = map(int, input().split())
    s1 = n * (n+1) // 2
    s2 = (n * 2) * (n / 2)
    s3 = (n * 2 + 2) * (n / 2)
    print(k, s1, int(s2), int(s3))