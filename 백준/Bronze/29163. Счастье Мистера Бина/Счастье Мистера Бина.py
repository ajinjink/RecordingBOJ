n = int(input())
even, odd = 0, 0
l = list(map(int, input().split()))
for i in l:
    if i % 2 == 0:
        even +=1
    else:
        odd +=1
if even > odd:
    print("Happy")
else:
    print("Sad")