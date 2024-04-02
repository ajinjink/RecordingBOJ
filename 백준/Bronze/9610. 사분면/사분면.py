n = ["Q1", "Q2", "Q3", "Q4", "AXIS"]
l = [0] * 5
for _ in range(int(input())):
    x, y = map(int, input().split())
    if x == 0 or y == 0:
        l[4] += 1
    elif x > 0 and y > 0:
        l[0] += 1
    elif x < 0 and y > 0:
        l[1] += 1
    elif x < 0 and y < 0:
        l[2] += 1
    elif x > 0 and y < 0:
        l[3] += 1

for i in range(5):
    print(f"{n[i]}: {l[i]}")