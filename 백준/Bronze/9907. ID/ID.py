import sys
input = sys.stdin.readline

m = "JABCDEFGHIZ"
s = input()
l = [2, 7, 6, 5, 4, 3, 2]
res = 0
for i in range(7):
    res += int(s[i]) * l[i]
print(m[res % 11])