import sys
input = sys.stdin.readline

def f(t):
    res = t
    if t < 0:
        res = t + 2400
    if t >= 2400:
        res = t - 2400
    if res % 100 >= 60:
        res = 100 * (res // 100 + 1) + res % 100 - 60
    if res >= 2400:
        res -= 2400
    return res

t = int(input())
print(t, "in Ottawa")
print(f(t - 300), "in Victoria")
print(f(t - 200), "in Edmonton")
print(f(t - 100), "in Winnipeg")
print(t, "in Toronto")
print(f(t + 100), "in Halifax")
print(f(t + 130), "in St. John's")