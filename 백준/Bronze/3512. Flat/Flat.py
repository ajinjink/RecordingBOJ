import sys
input = sys.stdin.readline

n, c = map(int, input().split())
size = {
    'bedroom': 0,
    'bathroom': 0,
    'kitchen': 0,
    'balcony': 0,
    'other': 0
}
sum = 0
for _ in range(n):
    a, b = map(str, input().split())
    size[b] += int(a)
    sum += int(a)
print(sum)
print(size["bedroom"])
print(c * (sum - size["balcony"]/2))