import sys
input = sys.stdin.readline

w = input().strip().lower()
print(w)
if w.find('sss') != -1:
    print(w.replace('sss', 'sB'))
    print(w.replace('sss', 'Bs'))
elif w.find('ss') != -1:
    print(w.replace('ss', 'B'))