import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input()
    cnt = 0
    for i in range(len(s) // 8):
        temp = 0
        for j in range(7):
            if s[i*8 + j] == '1':
                temp += 1
        if (temp % 2) != int(s[i*8 + 7]):
            cnt += 1
    print(cnt)