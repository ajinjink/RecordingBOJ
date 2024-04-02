import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = sorted(list(map(int, input().split())))
    print(f"Scenario #{i + 1}:")
    print("yes" if l[0]**2 + l[1]**2 == l[2]**2 else "no")
    print()