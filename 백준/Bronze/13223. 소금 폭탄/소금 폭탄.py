import sys
input = sys.stdin.readline

t1 = list(map(int, input().split(':')))
t2 = list(map(int, input().split(':')))
time = (t2[0] - t1[0]) * 3600 + (t2[1] - t1[1]) * 60 + t2[2] - t1[2]
if time <= 0:
    time += 24 * 3600
print(f'{str(time // 3600).zfill(2)}:{str((time % 3600) // 60).zfill(2)}:{str(time % 60).zfill(2)}')