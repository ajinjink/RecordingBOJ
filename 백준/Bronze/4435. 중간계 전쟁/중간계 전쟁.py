import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    A = a[0] + a[1]*2 + a[2]*3 + a[3]*3 + a[4]*4 + a[5]*10
    B = b[0] + b[1]*2 + b[2]*2 + b[3]*2 + b[4]*3 + b[5]*5 + b[6]*10
    if A > B:
      print(f"Battle {i + 1}: Good triumphs over Evil")
    elif A < B:
      print(f"Battle {i + 1}: Evil eradicates all trace of Good")
    else:
      print(f"Battle {i + 1}: No victor on this battle field")