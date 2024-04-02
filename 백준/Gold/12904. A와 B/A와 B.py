import sys
input = sys.stdin.readline

str1 = list(map(str, input().strip()))
str2 = list(map(str, input().strip()))

while len(str2) != len(str1):
    if str2[-1] == 'A':
        str2.pop()
    elif str2[-1] == 'B':
        str2.pop()
        str2 = str2[::-1]

print(1 if str1 == str2 else 0)