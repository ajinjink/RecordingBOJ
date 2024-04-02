import sys
input = sys.stdin.readline

s = list(map(int, input().split('/')))
if s[0] + s[2] < s[1] or s[1] == 0:
    print("hasu")
else:
    print("gosu")