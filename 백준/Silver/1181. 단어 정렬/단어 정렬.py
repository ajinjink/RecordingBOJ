import sys

N = int(sys.stdin.readline())

words = []

for i in range(N):
    words.append(str(sys.stdin.readline().strip()))

wsort1 = sorted(words)
wsort2 = sorted(wsort1, key=len)
wsort3 = list(dict.fromkeys(wsort2))

for i in range(len(wsort3)):
    print(wsort3[i])