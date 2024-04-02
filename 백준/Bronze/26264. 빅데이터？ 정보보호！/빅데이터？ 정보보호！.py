import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
if s.count('security') > s.count('bigdata'):
    print('security!')
elif s.count('security') < s.count('bigdata'):
    print('bigdata?')
else:
    print('bigdata? security!')