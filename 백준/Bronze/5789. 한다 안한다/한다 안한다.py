import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().strip()
    print("Do-it" if s[len(s) // 2 - 1] == s[len(s) // 2] else "Do-it-Not")