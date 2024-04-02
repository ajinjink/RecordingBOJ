import sys
input = sys.stdin.readline

a = int(input())
b = int(input())

if (a >= b):
    print("Congratulations, you are within the speed limit!")
else:
    dif = b - a
    fine = 0
    if dif <= 20:
        fine = 100
    elif dif <= 30:
        fine = 270
    else:
        fine = 500
    print(f"You are speeding and your fine is ${fine}.")


