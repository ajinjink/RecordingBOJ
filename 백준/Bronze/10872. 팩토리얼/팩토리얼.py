import sys

def factorial(n):
    fac = 1
    for i in range(1, n + 1):
        fac *= i
    return fac    

N = int(sys.stdin.readline())

print(factorial(N))

