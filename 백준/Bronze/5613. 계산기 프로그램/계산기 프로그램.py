n = int(input())
while True:
    calc = input()
    if calc == '=':
        print(n)
        break
    a = int(input())
    if calc == '+':
        n += a
    elif calc == '-':
        n -= a
    elif calc == '*':
        n *= a
    elif calc == '/':
        n //= a