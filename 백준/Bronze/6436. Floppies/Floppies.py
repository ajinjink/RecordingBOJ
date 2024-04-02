import sys
input = sys.stdin.readline

i = 1
while 1:
    n = int(input())
    if n == 0:
        break
    n = n//2 if n % 2 == 0 else n//2+1
    n += n // 2
    print(f"File #{i}")
    print(f"John needs {(n + 1860000 - 1) // 1860000} floppies.\n")
    i += 1