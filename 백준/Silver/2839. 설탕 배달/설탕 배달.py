inputnum = input()
num = int(inputnum)
flag = 0
cnt5 = 0
cnt3 = 0
if num < 3:
    print(-1)
else:
    cnt5 = num // 5
    for i in reversed(range(cnt5+1)):
        if num % 5 == 0:
            print(cnt5)
            flag = 1
            break
        else:
            if (num - 5*i) % 3 == 0:
                cnt3 = (num - 5*i) // 3
                print(i + cnt3)
                flag = 1
                break

if flag == 0:
    print(-1)