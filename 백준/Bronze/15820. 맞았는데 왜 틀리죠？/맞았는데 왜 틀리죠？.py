s1, s2 = map(int, input().split())
l1 = [list(map(int, input().split())) for _ in range(s1)]
l2 = [list(map(int, input().split())) for _ in range(s2)]
for s in l1:
    if s[0] != s[1]:
        print("Wrong Answer")
        exit(0)
for s in l2:
    if s[0] != s[1]:
        print("Why Wrong!!!")
        exit(0)
print("Accepted")