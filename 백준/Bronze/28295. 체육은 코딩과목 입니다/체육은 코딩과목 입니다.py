import sys
input = sys.stdin.readline

l = ['N','E','S','W']
index = 0
for _ in range(10):
    index += int(input()) % 4
print(l[index % 4])