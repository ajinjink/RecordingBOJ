import sys

length = int(sys.stdin.readline())
word = sys.stdin.readline()

vowels = ['a', 'e', 'i', 'o', 'u']
count = 0

for i in range(length):
    if word[i] in vowels:
        count += 1
        
print(count)
