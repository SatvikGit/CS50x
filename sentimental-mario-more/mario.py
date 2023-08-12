from cs50 import get_int

while True:
    # Asks for height from user at least one time
    height = get_int("What's the height: ")
    # If user provides valid input break out of loop and print, if not loop again
    if height >= 1 and height <= 8:
        break
for i in range(1, height + 1, 1):
    print(" " * (height - i) + "#" * i + "  " + "#" * i)
