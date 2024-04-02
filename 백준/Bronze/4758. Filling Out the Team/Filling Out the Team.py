

position = ['Wide Receiver', 'Lineman', 'Quarterback']
ss = [4.5, 6, 5]
mw = [150, 300, 200]
ms = [200, 500, 300]
while True:
    a, b, c = map(float, input().split())
    if a == b == c == 0:
        break
    flag = 1
    for i in range(3):
        if a <= ss[i] and b >= mw[i] and c >= ms[i]:
            print(position[i], end=' ')
            flag = 0
    if flag:
        print("No positions", end='')
    print()