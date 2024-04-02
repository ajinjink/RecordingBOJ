import sys
input = sys.stdin.readline

l = []
for i in range(int(input())):
    temp = list(map(int, input().split()))
    temp.append(i + 1)
    l.append(temp)
l.sort(key=lambda x: (-x[0], x[1], x[2]))
print(l[0][-1])