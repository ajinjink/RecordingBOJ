import sys
input = sys.stdin.readline

p1, s1 = map(int, input().split())
s2, p2 = map(int, input().split())

if p1 + p2 == s1 + s2:
    if p1 == s2:
        print("Penalty")
    elif p1 > s2:
        print("Esteghlal")
    else:
        print("Persepolis")
elif p1 + p2 > s1 + s2:
    print("Persepolis")
else:
    print("Esteghlal")