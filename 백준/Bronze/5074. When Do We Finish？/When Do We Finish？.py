import sys
input = sys.stdin.readline

while True:
    a, b = input().split()
    h1, m1 = map(int, a.split(':'))
    h2, m2 = map(int, b.split(':'))
    if h1 == m1 == h2 == m2 == 0:
        break
    t = (h1 + h2) * 60 + m1 + m2
    n = t // 60 // 24
    h = t // 60 % 24
    m = t % 60
    if n > 0:
        print(f"{str(h).zfill(2)}:{str(m).zfill(2)} +{n}")
    else:
        print(f"{str(h).zfill(2)}:{str(m).zfill(2)}")