import sys
input = sys.stdin.readline

br, bc = map(int, input().split())
dr, dc = map(int, input().split())
jr, jc = map(int, input().split())
if max(abs(jr-br), abs(jc-bc)) == abs(jr-dr) + abs(jc-dc):
    print("tie")
elif max(abs(jr-br), abs(jc-bc)) < abs(jr-dr) + abs(jc-dc):
    print("bessie")
else:
    print("daisy")