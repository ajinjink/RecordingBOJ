import sys
input = sys.stdin.readline

n = int(input())
l = [input().strip() for _ in range(n)]
print("뭐야;"if 'anj' in l else "뭐야?")