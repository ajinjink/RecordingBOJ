import sys
input = sys.stdin.readline

l1 = list(map(int, input().split(':')))
l2 = list(map(int, input().split(':')))
t = (l2[0] - l1[0])*3600 + (l2[1] - l1[1])*60 + l2[2] - l1[2]
if t <= 0:
    t += 24 * 60 * 60
h = t // 3600
m = t // 60 % 60
s = t % 60
print(f"{str(h).zfill(2)}:{str(m).zfill(2)}:{str(s).zfill(2)}")