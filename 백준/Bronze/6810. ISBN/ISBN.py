import sys
input = sys.stdin.readline

arr = [9,7,8,0,9,2,1,4,1,8]
arr.append(int(input()))
arr.append(int(input()))
arr.append(int(input()))

sum = 0

for i in range(len(arr)):
    if i % 2 == 0:
        sum += arr[i] * 1
    else:
        sum += arr[i] * 3

print("The 1-3-sum is", sum)



