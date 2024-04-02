import sys
input = sys.stdin.readline

i = 1
while True:
    sl = int(input())
    if sl == 0:
        break
    n =int(input())
    l = [int(input()) for _ in range(n)]
    print("User", i)
    for w in l:
        print(f"{(w * sl / 100000):.5f}")
    i += 1