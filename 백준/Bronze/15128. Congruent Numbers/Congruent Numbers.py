import sys
input = sys.stdin.readline

p1, q1, p2, q2 = map(int, input().split())

if p1/q1 * p2/q2 * 0.5 == (p1/q1 * p2/q2 * 0.5).__floor__():
    print(1)
else:
    print(0)