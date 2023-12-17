from sys import argv, exit
from pyfiglet import Figlet
from random import choice


def main():
    figlet = Figlet()

    fonts = figlet.getFonts()

    if not validate_cla(fonts):
        print("Invalid usage")
        exit(1)

    s = input("Input: ").strip()

    if len(argv) == 1:
        figlet.setFont(font=choice(fonts))
    else:
        figlet.setFont(font=argv[2])

    print("Output:")

    print(figlet.renderText(s))


def validate_cla(fonts_list):
    if len(argv) == 1:
        return 1
    elif len(argv) == 3 and argv[1] in ["-f", "--font"] and argv[2] in fonts_list:
        return 1
    return 0


main()
