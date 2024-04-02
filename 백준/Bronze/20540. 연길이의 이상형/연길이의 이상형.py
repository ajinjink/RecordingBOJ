import sys
input = sys.stdin.readline

s = input().strip()
l = ['E', 'I', 'S', 'N', 'T', 'F', 'J', 'P']
res = [c for c in l if c not in s]
print(''.join(res))