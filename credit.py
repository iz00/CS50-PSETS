from sys import exit


def main():
    card_number = input("Number: ").replace(" ", "").replace("-", "").replace(".", "")
    if not card_number.isdecimal():
        exit("INVALID")

    card_number_sum = calculate_luhn_sum(card_number)

    print(validate_card_check_type(card_number, card_number_sum))


def calculate_luhn_sum(number):
    s = 0

    for digit in number[-2::-2]:
        digit = int(digit) * 2
        s += digit // 10 + digit % 10

    for digit in number[::-2]:
        s += int(digit)

    return s


def validate_card_check_type(number, s):
    if s % 10 != 0:
        return "INVALID"
    else:
        card_digits = len(number)
        first_two_digits = int(number[:2])

        if card_digits == 15 and first_two_digits in [34, 37]:
            return "AMEX"
        elif card_digits == 16 and first_two_digits in [51, 52, 53, 54, 55]:
            return "MASTERCARD"
        elif (card_digits == 13 or card_digits == 16) and number[0] == "4":
            return "VISA"
        else:
            return "INVALID"


main()
