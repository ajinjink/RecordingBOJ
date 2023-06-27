import sys

temp = sys.stdin.readline().strip()

arr1 = ["SONGDO", "CODE", "2023", "ALGORITHM"]
arr2 = ["HIGHSCHOOL", "MASTER", "0611", "CONTEST"]

for i in range(4):
    if temp == arr1[i]:
        print(arr2[i])
        break