import sys
input = sys.stdin.readline

while True:
    stu, d = map(int, input().split())
    if stu == d == 0:
        break
    l = [0] * stu
    for _ in range(d):
        temp = list(map(int, input().split()))
        for i in range(stu):
            l[i] += temp[i]
    print("yes" if d in l else "no")