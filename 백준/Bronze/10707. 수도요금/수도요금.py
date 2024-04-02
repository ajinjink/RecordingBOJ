import sys
input = sys.stdin.readline

l = [int(input()) for _ in range(5)]
print(min(l[4] * l[0], l[1] + l[3] * max(0, l[4]-l[2])))