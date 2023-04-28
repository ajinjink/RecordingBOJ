N = int(input())

if N != 1:
    # 소인수 2부터 시작
    # div = 2 라고 선언
    div = 2
    while True:
        if N == 1:
            break
        # N이 div로 나누어떨어진다면
        if N % div == 0:
            print(div)
            N = N / div
            # print("N:", N, "div:", div)
            # 소인수 출력
            # ??
        else:
            div += 1