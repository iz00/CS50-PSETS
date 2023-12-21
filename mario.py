LOW_HEIGHT, HIGH_HEIGHT = 0, 9


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
            if n > LOW_HEIGHT and n < HIGH_HEIGHT:
                return n


def print_pyramid(n):
    for i in range(1, n + 1):

        empty_spaces = " " * (n - i)
        bricks = "#" * i

        print(f"{empty_spaces}{bricks}")


main()
