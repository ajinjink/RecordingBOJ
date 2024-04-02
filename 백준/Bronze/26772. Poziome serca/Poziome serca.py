import sys
input = sys.stdin.readline

n = int(input())
s = [' @@@   @@@ ', '@   @ @   @', '@    @    @', '@         @', ' @       @ ', '  @     @  ', '   @   @   ', '    @ @    ', '     @     ']
for l in s:
    for _ in range(n):
        print(l, end=' ')
    print()