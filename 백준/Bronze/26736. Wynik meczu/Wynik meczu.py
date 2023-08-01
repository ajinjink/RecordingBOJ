import sys
input = sys.stdin.readline

s = input().strip()
alpha = [0]*2
for c in s:
    alpha[ord(c) - ord('A')] += 1
print(alpha[0], ':', alpha[1])