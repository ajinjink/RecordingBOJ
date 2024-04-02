import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    if (a + c) % 2 == 0 and a >= c:
        print("No" if a == 0 and b % 2 else "Yes")
    else:
        print("No")
    
