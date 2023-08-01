import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    asc = list(range(65, 91))
    s = input().strip()
    for c in s:
        asc[ord(c) - ord('A')] = 0
    print(sum(asc))