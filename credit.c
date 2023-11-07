#include <cs50.h>
#include <stdio.h>

int card_digits_amount(long n);
long power_base_ten(int times);
int calculate_luhn_sum(long n, int digits);
bool initial_validate_card(int s, int digits);
string check_card_type(int first, int second, int digits);

int main(void)
{
    long number = get_long("Number: ");

    int digits_amount = card_digits_amount(number);

    int sum = calculate_luhn_sum(number, digits_amount);

    bool valid = initial_validate_card(sum, digits_amount);

    if (valid)
    {
        int first_digit = number / power_base_ten(digits_amount - 1);
        int second_digit = number / power_base_ten(digits_amount - 2) % 10;

        string card_type = check_card_type(first_digit, second_digit, digits_amount);

        printf("%s", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
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

bool initial_validate_card(int s, int digits)
{
    if (s % 10 != 0)
    {
        return false;
    }
    if (digits < 13 || digits > 16 || digits == 14)
    {
        return false;
    }
    return true;
}

string check_card_type(int first, int second, int digits)
{
    if (first == 3)
    {
        if (second == 4 || second == 7)
        {
            if (digits == 15)
            {
                return "AMEX\n";
            }
        }
    }
    if (first == 5)
    {
        if (second == 1 || second == 2 || second == 3 || second == 4 || second == 5)
        {
            if (digits == 16)
            {
                return "MASTERCARD\n";
            }
        }
    }
    if (first == 4)
    {
        if (digits == 13 || digits == 16)
        {
            return "VISA\n";
        }
    }
    return "INVALID\n";
}
