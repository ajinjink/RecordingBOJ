import sys
input = sys.stdin.readline

s = input().strip()
alpha = [0]*26
for c in s:
    alpha[ord(c) - ord('A')] += 1
print(chr(alpha.index(0) + ord('A')))