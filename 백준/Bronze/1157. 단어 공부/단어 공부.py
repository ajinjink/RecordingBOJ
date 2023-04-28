words = input().upper()
alpha = list(set(words))  

cntlist = []
for x in alpha :
    cnt = words.count(x)
    cntlist.append(cnt) 

if cntlist.count(max(cntlist)) > 1 : 
    print('?')
else :
    max_index = cntlist.index(max(cntlist)) 
    print(alpha[max_index])