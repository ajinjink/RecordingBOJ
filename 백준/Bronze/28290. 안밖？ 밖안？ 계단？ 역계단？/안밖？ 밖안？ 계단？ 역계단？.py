import sys
input = sys.stdin.readline

l = ['fdsajkl;', 'asdf;lkj', 'asdfjkl;', ';lkjfdsa', 'jkl;fdsa',';lkjasdf']
l2 = ['in-out', 'out-in', 'stairs', 'reverse','in-out','out-in']
s = input().strip()
print(l2[l.index(s)] if s in l else "molu")