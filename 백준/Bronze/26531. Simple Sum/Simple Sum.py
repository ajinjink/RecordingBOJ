import sys
input = sys.stdin.readline

l = list(map(str, input().split()))
print("YES" if int(l[0])+int(l[2])==int(l[4]) else "NO")