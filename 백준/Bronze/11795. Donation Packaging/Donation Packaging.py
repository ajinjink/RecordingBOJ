import sys
input = sys.stdin.readline

setA, setB, setC = 0, 0, 0
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    setA += a
    setB += b
    setC += c
    p = min(setA, setB, setC)
    if p < 30:
        print("NO")
    else:
        print(p)
        setA -= p
        setB -= p
        setC -= p