import sys
input = sys.stdin.readline

i = 1
while 1:
    p, s = map(int, input().split())
    if p == s == 0:
        break
    print(f"Hole #{i}")
    if s == 1:
        print("Hole-in-one.")
    elif p - s == 3:
        print("Double eagle.")
    elif p - s == 2:
        print("Eagle.")
    elif p - s == 1:
        print("Birdie.")
    elif p - s == 0:
        print("Par.")
    elif p - s == -1:
        print("Bogey.")
    else:
        print("Double Bogey.")
    print()
    i += 1