

while True:
    try:
        name = input().strip()
        for c in name:
            if c == 'i':
                print('e', end='')
            elif c == 'e':
                print('i', end='')
            elif c == 'I':
                print('E', end='')
            elif c == 'E':
                print('I', end='')
            else:
                print(c, end='')
        print()
    except EOFError:
        break