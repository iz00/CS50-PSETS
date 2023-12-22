from sys import exit


def main():
    card_number = input("Number: ").replace(" ", "").replace("-", "").replace(".", "")
    if not card_number.isdecimal():
        exit("INVALID")

    card_number_sum = 0

    for digit in card_number[-2::-2]:
        digit = int(digit) * 2
        card_number_sum += digit // 10 + digit % 10

    for digit in card_number[::-2]:
        card_number_sum += int(digit)

    if card_number_sum % 10 != 0:
        print("INVALID")
    else:
        if len(card_number) in [13, 15, 16]:
            if card_number[0] == "4":
                print("VISA")
            if card_number[:2] in ["34", "37"]:
                print("AMEX")
            if card_number[:2] in ["51", "52", "53", "54", "55"]:
                print("MASTERCARD")
        else:
            print("INVALID")


main()
