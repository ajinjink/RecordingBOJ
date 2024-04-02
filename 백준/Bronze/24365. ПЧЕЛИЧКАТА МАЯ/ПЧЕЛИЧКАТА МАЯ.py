import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
each = sum(l) // 3
move = each - l[0]
l[1] -= move
move += l[2] - each
print(move)