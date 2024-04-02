import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
print(s[:-1] if s[-1] == 'G' else s + 'G')