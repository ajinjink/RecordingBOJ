import sys
input = sys.stdin.readline

name = ['S', 'N', 'U']
gsb = 0
res = 3
for i in range(3):
    p, w = map(float, input().split())
    p, w = p * 10, w * 10
    if p >= 5000:
        p -= 500
    gsb = max(gsb, w / p)
    if gsb == w / p:
        res = i
print(name[res])