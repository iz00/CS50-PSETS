// Validate a card number with luhn's algorithm and check card brand

#include <cs50.h>
#include <stdio.h>

int card_digits_amount(long n);
long power_base_ten(int times);
int calculate_luhn_sum(long n, int digits);
bool validate_checksum(int s);
string validate_card_check_type(long n, int s, int digits);

int main(void)
{
    // Prompt user for card number, long because can't fit in int
    long number = get_long("Number: ");

    int digits_amount = card_digits_amount(number);

    int sum = calculate_luhn_sum(number, digits_amount);

    string card_type = validate_card_check_type(number, sum, digits_amount);

    printf("%s\n", card_type);
}

// Calcute amount of digits in card number, because it's used in other functions
int card_digits_amount(long n)
{
    int digits = 0;

    while (n > 0)
    {
        digits++;
        n /= 10;
    }
    return digits;
}

long power_base_ten(int times)
{
    long n = 1;
    for (int i = 0; i < times; i++)
    {
        n *= 10;
    }
    return n;
}

int calculate_luhn_sum(long n, int digits)
{
    int s = 0;
    int digit;

    for (int i = 0; i < digits; i++)
    {
        digit = n % power_base_ten(i + 1) / power_base_ten(i);

        if (i % 2 == 0)
        {
            s += digit;
        }
        else
        {
            digit *= 2;
            s += digit / 10 + digit % 10;
        }
    }
    return s;
}

string validate_card_check_type(long n, int s, int digits)
{
    if (s % 10 != 0)
    {
        return "INVALID";
    }

    int first_digit = n / power_base_ten(digits - 1);
    int second_digit = n / power_base_ten(digits - 2) % 10;

    switch (first_digit)
    {
        case 3:
            if (second_digit == 4 || second_digit == 7)
            {
                if (digits == 15)
                {
                    return "AMEX";
                }
            }
            break;

        case 5:
            if (second_digit > 0 && second_digit < 6)
            {
                if (digits == 16)
                {
                    return "MASTERCARD";
                }
            }
            break;

        case 4:
            if (digits == 13 || digits == 16)
            {
                return "VISA";
            }
            break;
    }
    return "INVALID";
}
