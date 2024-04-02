import sys
input = sys.stdin.readline

s = input().strip()
org = ['a', 'e', 'i', 'o', 's']
chg = ['4', '3', '1', '0', '5']
for c in s:
    if c in org:
        print(chg[org.index(c)], end='')
    else:
        print(c, end='')