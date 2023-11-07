#include <cs50.h>
#include <stdio.h>

int card_digits_amount(long n);
long power_base_ten(int times);
int calculate_luhn_sum(long n, int digits);
bool validate_card(int s, int digits);

int main(void)
{
    long number = get_long("Number: ");

    int digits_amount = card_digits_amount(number);

    int sum = calculate_luhn_sum(number, digits_amount);

    bool valid = validate_card(sum, digits_amount);

    if (valid)
    {
        printf("VALID\n");
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

bool validate_card(int s, int digits)
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
