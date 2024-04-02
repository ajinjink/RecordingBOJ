import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = sorted(i**2 for i in list(map(int, input().split())))
    if l[2] == l[1] + l[0]:
        print(f"Case #{i + 1}: YES")
    else:
        print(f"Case #{i + 1}: NO")