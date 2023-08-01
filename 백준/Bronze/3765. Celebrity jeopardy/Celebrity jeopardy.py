while True:
    try:
        str = input().strip()
        print(str)
    except EOFError:
        break