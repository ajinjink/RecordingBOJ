import sys
input = sys.stdin.readline

l = []
for _ in range(3):
    s = input().strip()
    l.append(len(s))
print(f"Latitude {l[0]}:{l[1]}:{l[2]}")
l = []
for _ in range(3):
    s = input().strip()
    l.append(len(s))
print(f"Longitude {l[0]}:{l[1]}:{l[2]}")