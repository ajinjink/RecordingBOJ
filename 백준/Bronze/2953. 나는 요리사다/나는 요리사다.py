l = [0] * 5

for i in range(5):
  ll = map(int, input().split())
  l[i] = sum(ll)
print(l.index(max(l)) + 1, max(l))
