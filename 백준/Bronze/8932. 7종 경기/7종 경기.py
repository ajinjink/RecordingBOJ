import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l = list(map(int, input().split()))
    res = 0
    res += int(9.23076 * ((26.7 - l[0]) ** 1.835))
    res += int(1.84523 * ((l[1] - 75) ** 1.348))
    res += int(56.0211 * ((l[2] - 1.5) ** 1.05))
    res += int(4.99087 * ((42.5 - l[3]) ** 1.81))
    res += int(0.188807 * ((l[4] - 210) ** 1.41))
    res += int(15.9803 * ((l[5] - 3.8) ** 1.04))
    res += int(0.11193 * ((254 - l[6]) ** 1.88))
    print(res)