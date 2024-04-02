import sys
input = sys.stdin.readline

arr = list(map(int, input().split()))
arr.sort()
if arr[-1] == 9:
    print('F')
else:
    print('S')
