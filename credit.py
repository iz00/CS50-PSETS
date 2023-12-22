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
        card_digits = len(card_number)
        first_two_digits = int(card_number[:2])
        if card_digits == 15 and first_two_digits in [34, 37]:
            print("AMEX")
        elif card_digits == 16 and first_two_digits in [51, 52, 53, 54, 55]:
            print("MASTERCARD")
        elif (card_digits == 13 or card_digits == 16) and card_number[0] == "4":
            print("VISA")
        else:
            print("INVALID")


main()
