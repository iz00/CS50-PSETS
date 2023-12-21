TOO_LOW_HEIGHT, TOO_HIGH_HEIGHT = 0, 9


def main():
    height = get_height()

    print_pyramid(height)


def get_height():
    while True:
        try:
            n = int(input("Height: "))
        except ValueError:
            pass
        else:
            if n > TOO_LOW_HEIGHT and n < TOO_HIGH_HEIGHT:
                return n


def print_pyramid(n):
    for i in range(1, n + 1):
        empty_spaces = " " * (n - i)
        bricks = "#" * i

        print(f"{empty_spaces}{bricks}  {bricks}")


main()
