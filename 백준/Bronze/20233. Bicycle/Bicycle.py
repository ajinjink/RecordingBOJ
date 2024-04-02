import sys
input = sys.stdin.readline

a = int(input())
x = int(input())
b = int(input())
y = int(input())
t = int(input())
f1 = a + (t-30)*21*x
f2 = b+(t-45)*21*y
if f1 < 0:
    f1 = a
if f2 < 0:
    f2 = b
print(f1, f2)