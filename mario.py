try:
    n = int(input("Enter an integer between 1 and 8:"))
    if n > 0 and n < 9:
        pass
    else:
        raise ValueError("Not an integer between 1 and 8")
except ValueError:
    print("Not an integer between 1 and 8")
    n = int(input("Enter an integer between 1 and 8:"))

for i in range(n):
    for printspace in range(n-i-1):
        print(" ", end="")
    for printhash in range(i+1):
        print("#", end="")
    print()