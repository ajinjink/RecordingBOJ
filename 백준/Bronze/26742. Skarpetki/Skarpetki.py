import sys
input = sys.stdin.readline


s = input().strip()
alpha = [0]*2
for c in s:
    alpha[ord(c) - ord('B')] += 1
print(alpha[0]//2 + alpha[1]//2)