
cnt = 0

while True:
    try:
        str = input()
        cnt += 1
    except EOFError:
        break

print(cnt)