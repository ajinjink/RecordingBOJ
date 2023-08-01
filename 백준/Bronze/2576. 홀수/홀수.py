l = []
for _ in range(7):
  n = int(input())
  if n % 2 == 1:
    l.append(n)
print(-1 if len(l) == 0 else f"{sum(l)}\n{min(l)}")