import sys
input = sys.stdin.readline

name = ['Poblano', 'Mirasol', 'Serrano', 'Cayenne', 'Thai', 'Habanero']
p = [1500, 6000, 15500, 40000, 75000, 125000]
n = int(input())
res = 0
for _ in range(n):
    res += p[name.index(input().strip())]
print(res)