import sys
input = sys.stdin.readline

city = 'null'
temp = 201
while True:
    c, t = map(str, input().split())
    if c == "Waterloo":
        break
    if int(t) < temp:
        city = c
        temp = int(t)
print(city)