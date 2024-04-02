import sys
input = sys.stdin.readline

a = int(input())
cal = input().strip()
b = int(input())
print(a * b if cal == '*' else a + b)