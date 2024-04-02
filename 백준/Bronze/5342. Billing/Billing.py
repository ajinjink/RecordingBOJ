import sys
input = sys.stdin.readline

s = ['Paper', 'Printer', 'Planners', 'Binders','Calendar', 'Notebooks', 'Ink']
p = [57.99, 120.5, 31.25, 22.5, 10.95, 11.2, 66.95]
res = 0
while True:
    ss = input().strip()
    if ss == "EOI":
        break
    res += p[s.index(ss)]
print(f"${res:.2f}")