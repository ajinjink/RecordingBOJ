for _ in range(int(input())):
    n, c = map(str, input().split())
    for i in range(int(n)):
        print(chr(ord(c) + i - 26) * (i + 1) if ord(c) + i > ord('Z') else chr(ord(c) + i) * (i + 1))
    print()