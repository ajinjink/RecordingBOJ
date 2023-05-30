import sys

T = int(input())

for _ in range(T):
    string = list(sys.stdin.readline().split())
    
    for element in string:
        for index in range(-1, len(element) * -1 - 1, -1):
            print(element[index], end='')
        print(' ', end='')
        
    print()