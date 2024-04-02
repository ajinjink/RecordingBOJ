import sys
input = sys.stdin.readline

l1 = list(map(str, input().split()))
l2 = list(map(str, input().split()))

sum = 0
sum += (int(l2[0]) - int(l1[0])) * 3600
sum += (int(l2[2]) - int(l1[2])) * 60
sum += (int(l2[4]) - int(l1[4]))

if sum < 0:
    sum += 86400

print(sum)