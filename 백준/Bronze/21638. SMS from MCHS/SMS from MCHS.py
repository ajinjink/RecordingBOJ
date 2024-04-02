import sys
input = sys.stdin.readline

a, b = map(int, input().split())
c, d = map(int, input().split())

if c < 0 and d >= 10:
    print("A storm warning for tomorrow! Be careful and stay home if possible!")
elif a > c:
    print("MCHS warns! Low temperature is expected tomorrow.")
elif b < d:
    print("MCHS warns! Strong wind is expected tomorrow.")
else:
    print("No message")