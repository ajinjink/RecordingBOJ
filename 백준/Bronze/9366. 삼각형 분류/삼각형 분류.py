import sys
input = sys.stdin.readline

for i in range(int(input())):
    l = sorted(list(map(int, input().split())))
    print(f"Case #{i + 1}: ", end='')
    if l[0] + l[1] <= l[2]:
        print("invalid!")
    elif l[0] == l[2]:
        print("equilateral")
    elif l[0] == l[1] or l[1] == l[2]:
        print("isosceles")
    else:
        print("scalene")