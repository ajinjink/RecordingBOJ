n = int(input())
l = list(map(str, input().split()))
res = [l[0][0]]
plen = len(l[0])
for w in l[1:]:
    res.append(' ' if plen > len(w) else w[plen - 1])
    plen = len(w)
print(''.join(res))