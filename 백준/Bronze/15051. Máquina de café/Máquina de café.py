import sys

list = []

N = int(sys.stdin.readline().rstrip())
NN = int(sys.stdin.readline().rstrip())
NNN = int(sys.stdin.readline().rstrip())

list.append(N * 2 + NNN * 2)
list.append(N * 4 + NN * 2)
list.append((NNN) * 4 + NN * 2)

print(min(list))