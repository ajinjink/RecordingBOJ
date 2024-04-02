import sys
input = sys.stdin.readline

m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
w = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
x, y = map(int, input().split())
d = 0
for i in range(x - 1):
    d += m[i]
print(w[(d + y) % 7])
