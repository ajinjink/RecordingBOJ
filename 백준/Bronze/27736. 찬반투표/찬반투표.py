import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
res = [0, 0, 0] # rejected, invalid, approved
for i in l:
    res[i + 1] += 1
if res[1] >= n / 2:
    print("INVALID")
elif res[2] > res[0]:
    print("APPROVED")
else:
    print("REJECTED")