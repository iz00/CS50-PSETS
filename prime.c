// Prints all prime numbers in an interval

#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Gets a number equal to or higher than 1 to be the start point
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Gets a number equal to or less than the minimum, to be the ending point
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // For each number of the interval, check if prime, print if true
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Checks for prime numbers, false if not, true otherwise
bool prime(int number)
{
    // Returns false for even numbers (excluding 2), or for 1
    if (((number != 2) && (number % 2 == 0)) || (number == 1))
    {
        return false;
    }

    // Returns false for numbers that have a divisor (excluding 1 and themselves)
    // There are no even divisors possible (since all numbers left are odd), and no divisors greather than the half of the number
    int half = number / 2;
    for (int i = 3; i < half; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
