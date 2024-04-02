s = input().strip()
cnt = 0
while True:
    try:
        l = list(map(str, input().split()))
        for w in l:
            if w == s or s in w:
                cnt += 1
    except EOFError:
        break
print(cnt)