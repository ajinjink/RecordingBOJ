import sys
input = sys.stdin.readline

l1 = ["", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"]
l2 = ["", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"]
for i in range(int(input())):
    a, b = map(int, input().split())
    print(f"Case {i + 1}: ", end="")
    n1 = min(a, b)
    n2 = max(a, b)
    if n1 == n2:
        print(l2[n1])
        continue
    if n1 == 5 and n2 == 6:
        print("Sheesh Beesh")
        continue
    print(f"{l1[n2]} {l1[n1]}")