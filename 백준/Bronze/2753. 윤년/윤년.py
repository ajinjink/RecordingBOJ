a = int(input())

if a % 4 == 0:
    if a % 100 != 0:         # 4의 배수이면서 100의 배수가 아닐 때
        print(1)
    else:                    # 4의 배수이면서 100의 배수일 때
        if a % 400 == 0:     # 400의 배수일 때
            print(1)
        else:                # 400의 배수가 아니고 100의 배수일 때
            print(0)
else:                        # 4의 배수가 아닐 때
    print(0)
    
    
    