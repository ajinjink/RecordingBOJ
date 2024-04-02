import sys
input = sys.stdin.readline

l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

dif = 0
for i in range(3):
    if l1[i] < l2[i]:
        dif += l2[i] - l1[i]
print(dif)