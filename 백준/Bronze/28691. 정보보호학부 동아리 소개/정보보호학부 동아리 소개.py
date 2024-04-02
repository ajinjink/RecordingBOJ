import sys
 
N = sys.stdin.readline().strip()
arr1 = ['M', 'W', 'C', 'A', '$']
arr2 = ['MatKor', 'WiCys', 'CyKor', 'AlKor', '$clear']


for i in range(5):
    if N == arr1[i]:
        print(arr2[i])