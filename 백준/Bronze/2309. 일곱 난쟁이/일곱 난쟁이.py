arr = []

for _ in range(9):
    temp = int(input())
    arr.append((temp))

sum = 0

for i in range(len(arr)):  # 9 난쟁이들의 키 총합
    sum += arr[i]

arr.sort()  # 키 오름차순 정렬

# 9 난쟁이 키 총합에서 난쟁이 두 명씩 빼서 키가 100이 되면 출력
for i in range(8):  # 첫 번째 난쟁이 인덱스
    for j in range(i + 1, 9):  # 두 번째 난쟁이 인덱스
        # 총합에서 난쟁이 두 명 키를 빼자
        sum -= arr[i]
        sum -= arr[j]

        if sum == 100:  # 7 난쟁이 키 총합 100
            for k in range(9):
                if k != i and k != j:  # i, j 두 명 빼고 출력
                    print(arr[k])
        else:  # 키 총합이 100이 아니면 총합 다시 원상복귀
            sum += arr[i]
            sum += arr[j]