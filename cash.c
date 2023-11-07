// Greedy algorithm to calculate minimum amount of coins for owed cents user inputs

#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_coins(int cents, int value);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt for how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Prompt user for cents, check if 0 or positive
int get_cents(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);
    return n;
}

// Calculate amount of coins of certain value
int calculate_coins(int cents, int value)
{
    int coins = 0;
    // Loop until cents is less than value, to see if the coin value fits
    while (cents >= value)
    {
        // A new coin of value is added, so cents is decreased by value
        coins++;
        cents -= value;
    }
    return coins;
}

// Calculate the amount of quarters, of value 25
int calculate_quarters(int cents)
{
    return calculate_coins(cents, 25);
}

// Calculate the amount of quarters, of value 10
int calculate_dimes(int cents)
{
    return calculate_coins(cents, 10);
}

// Calculate the amount of quarters, of value 5
int calculate_nickels(int cents)
{
    return calculate_coins(cents, 5);
}

// Calculate the amount of quarters, of value 1
int calculate_pennies(int cents)
{
    return calculate_coins(cents, 1);
}
