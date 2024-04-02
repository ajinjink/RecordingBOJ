while (1):
    try:
        str = input()
        print(str)
    except EOFError:
        break