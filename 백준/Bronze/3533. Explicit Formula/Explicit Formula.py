import sys
input = sys.stdin.readline

x1, x2, x3, x4, x5, x6, x7, x8, x9, x10 = map(int, input().split())
res = (x1 or x2) ^ (x1 or x3) ^ (x1 or x4) ^ (x1 or x5) ^ (x1 or x6) ^ (x1 or x7) ^ (x1 or x8) ^ (x1 or x9) ^ (x1 or x10) ^ (x2 or x3) ^ (x2 or x4) ^ (x2 or x5) ^ (x2 or x6) ^ (x2 or x7) ^ (x2 or x8) ^ (x2 or x9) ^ (x2 or x10) ^ (x3 or x4) ^ (x3 or x5) ^ (x3 or x6) ^ (x3 or x7) ^ (x3 or x8) ^ (x3 or x9) ^ (x3 or x10) ^ (x4 or x5) ^ (x4 or x6) ^ (x4 or x7) ^ (x4 or x8) ^ (x4 or x9) ^ (x4 or x10) ^ (x5 or x6) ^ (x5 or x7) ^ (x5 or x8) ^ (x5 or x9) ^ (x5 or x10) ^ (x6 or x7) ^ (x6 or x8) ^ (x6 or x9) ^ (x6 or x10) ^ (x7 or x8) ^ (x7 or x9) ^ (x7 or x10) ^ (x8 or x9) ^ (x8 or x10) ^ (x9 or x10) ^ (x1 or x2 or x3) ^ (x1 or x2 or x4) ^ (x1 or x2 or x5) ^ (x1 or x2 or x6) ^ (x1 or x2 or x7) ^ (x1 or x2 or x8) ^ (x1 or x2 or x9) ^ (x1 or x2 or x10) ^ (x1 or x3 or x4) ^ (x1 or x3 or x5) ^ (x1 or x3 or x6) ^ (x1 or x3 or x7) ^ (x1 or x3 or x8) ^ (x1 or x3 or x9) ^ (x1 or x3 or x10) ^ (x1 or x4 or x5) ^ (x1 or x4 or x6) ^ (x1 or x4 or x7) ^ (x1 or x4 or x8) ^ (x1 or x4 or x9) ^ (x1 or x4 or x10) ^ (x1 or x5 or x6) ^ (x1 or x5 or x7) ^ (x1 or x5 or x8) ^ (x1 or x5 or x9) ^ (x1 or x5 or x10) ^ (x1 or x6 or x7) ^ (x1 or x6 or x8) ^ (x1 or x6 or x9) ^ (x1 or x6 or x10) ^ (x1 or x7 or x8) ^ (x1 or x7 or x9) ^ (x1 or x7 or x10) ^ (x1 or x8 or x9) ^ (x1 or x8 or x10) ^ (x1 or x9 or x10) ^ (x2 or x3 or x4) ^ (x2 or x3 or x5) ^ (x2 or x3 or x6) ^ (x2 or x3 or x7) ^ (x2 or x3 or x8) ^ (x2 or x3 or x9) ^ (x2 or x3 or x10) ^ (x2 or x4 or x5) ^ (x2 or x4 or x6) ^ (x2 or x4 or x7) ^ (x2 or x4 or x8) ^ (x2 or x4 or x9) ^ (x2 or x4 or x10) ^ (x2 or x5 or x6) ^ (x2 or x5 or x7) ^ (x2 or x5 or x8) ^ (x2 or x5 or x9) ^ (x2 or x5 or x10) ^ (x2 or x6 or x7) ^ (x2 or x6 or x8) ^ (x2 or x6 or x9) ^ (x2 or x6 or x10) ^ (x2 or x7 or x8) ^ (x2 or x7 or x9) ^ (x2 or x7 or x10) ^ (x2 or x8 or x9) ^ (x2 or x8 or x10) ^ (x2 or x9 or x10) ^ (x3 or x4 or x5) ^ (x3 or x4 or x6) ^ (x3 or x4 or x7) ^ (x3 or x4 or x8) ^ (x3 or x4 or x9) ^ (x3 or x4 or x10) ^ (x3 or x5 or x6) ^ (x3 or x5 or x7) ^ (x3 or x5 or x8) ^ (x3 or x5 or x9) ^ (x3 or x5 or x10) ^ (x3 or x6 or x7) ^ (x3 or x6 or x8) ^ (x3 or x6 or x9) ^ (x3 or x6 or x10) ^ (x3 or x7 or x8) ^ (x3 or x7 or x9) ^ (x3 or x7 or x10) ^ (x3 or x8 or x9) ^ (x3 or x8 or x10) ^ (x3 or x9 or x10) ^ (x4 or x5 or x6) ^ (x4 or x5 or x7) ^ (x4 or x5 or x8) ^ (x4 or x5 or x9) ^ (x4 or x5 or x10) ^ (x4 or x6 or x7) ^ (x4 or x6 or x8) ^ (x4 or x6 or x9) ^ (x4 or x6 or x10) ^ (x4 or x7 or x8) ^ (x4 or x7 or x9) ^ (x4 or x7 or x10) ^ (x4 or x8 or x9) ^ (x4 or x8 or x10) ^ (x4 or x9 or x10) ^ (x5 or x6 or x7) ^ (x5 or x6 or x8) ^ (x5 or x6 or x9) ^ (x5 or x6 or x10) ^ (x5 or x7 or x8) ^ (x5 or x7 or x9) ^ (x5 or x7 or x10) ^ (x5 or x8 or x9) ^ (x5 or x8 or x10) ^ (x5 or x9 or x10) ^ (x6 or x7 or x8) ^ (x6 or x7 or x9) ^ (x6 or x7 or x10) ^ (x6 or x8 or x9) ^ (x6 or x8 or x10) ^ (x6 or x9 or x10) ^ (x7 or x8 or x9) ^ (x7 or x8 or x10) ^ (x7 or x9 or x10) ^ (x8 or x9 or x10);
print(res)