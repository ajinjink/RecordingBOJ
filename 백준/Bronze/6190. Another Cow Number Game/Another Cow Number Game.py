import sys

N = int(sys.stdin.readline().rstrip())
score = 0
while (N > 1):
   if (N % 2 == 0):
      N = N // 2
      score += 1
   else:
      N = N * 3 + 1
      score += 1

print(score)