import sys
input = sys.stdin.readline

l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
for i in range(5):
    if l1[i] == l2[i]:
        print("N")
        exit(0)
print("Y")