import sys
input = sys.stdin.readline

l = list(map(str, input().split()))


if int(l[0]) + int(l[2]) == int(l[4]):
    print("YES")
else:
    print("NO")