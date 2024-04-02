import sys
input = sys.stdin.readline

a, b = map(int, input().split())
if 7*a == 13*b:
    print("lika")
else:
    print("Axel" if 7*a > 13*b else "Petra")