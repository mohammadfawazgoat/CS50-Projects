from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if 0 < height < 9:
            break
    for i in range(height):
        printing(height, i+1)


def printing(height, row_number):
    for i in range(height - row_number):
        print(" ", end="")

    for j in range(row_number):
        print("#", end="")
    print("  ", end="")

    for x in range(row_number):
        print("#", end="")
    print("")


main()
