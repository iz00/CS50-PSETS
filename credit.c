#include <cs50.h>
#include <stdio.h>

int card_digits_amount(long n);
long power_base_ten(int times);
int calculate_luhn_sum(long n, int digits);
bool validate_checksum(int s);
string validate_card_check_type(long n, int s, int digits);

int main(void)
{
    long number = get_long("Number: ");

    int digits_amount = card_digits_amount(number);

    int sum = calculate_luhn_sum(number, digits_amount);

    string card_type = validate_card_check_type(number, sum, digits_amount);

    printf("%s", card_type);

}

int card_digits_amount(long n)
{
    long update_number = n;
    int digits = 0;

    while (update_number > 0)
    {
        digits++;
        update_number /= 10;
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
        return "INVALID\n";
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
                    return "AMEX\n";
                }
            }
            break;

        case 5:
            if (second_digit > 0 && second_digit < 6)
            {
                if (digits == 16)
                {
                    return "MASTERCARD\n";
                }
            }
            break;

        case 4:
            if (digits == 13 || digits == 16)
            {
                return "VISA\n";
            }
            break;
    }
    return "INVALID\n";
}
