l = {'I', 'O', 'S', 'H', 'Z', 'X', 'N'}
s = input()
flag = 1
for c in s:
    if c not in l:
        print("NO")
        flag = 0
        break
if flag:
    print("YES")