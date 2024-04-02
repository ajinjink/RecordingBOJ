import sys
input = sys.stdin.readline

s = input().strip()
l = ['M','O','B','I','S']
flag = 1
for c in s:
    if c in l:
        del(l[l.index(c)])
print("YES" if len(l) == 0 else "NO")