n = int(input())

A, B = 100, 100

for _ in range(n):
    a, b = map(int, input().split())
    if a < b:
        A -= b
    elif a > b:
        B -= a

print(A)
print(B)
