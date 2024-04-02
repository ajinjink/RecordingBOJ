a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
Max = 3 * a + 20 * b + 120 * c
Mel = 3 * d + 20 * e + 120 * f
if Max > Mel:
    print('Max')
elif Max < Mel:
    print('Mel')
else:
    print('Draw')