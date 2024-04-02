import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l = list(map(int, input().split()))
    l2 = [l[i] + l[i + 4] for i in range(4)]
    res = max(l2[0], 1) + max(l2[1], 1)*5 + max(l2[2], 0)*2 + l2[3]*2
    print(res)