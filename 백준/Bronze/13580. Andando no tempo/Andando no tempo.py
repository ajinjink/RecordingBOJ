import sys
input = sys.stdin.readline


l = list(map(int, input().split()))
l.sort()
if l[0] == l[1] or l[1] == l[2]:
    print("S")
elif l[0] + l[1] == l[2]:
    print("S")
else:
    print("N")