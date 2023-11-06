// Calculates number of years to get from start to end size of population

#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int s);
int calculate_years(int s, int e);

int main(void)
{
    // Prompt for start size
    int start = get_start_size();

    // Prompt for end size
    int end = get_end_size(start);

    // Calculate number of years until we reach threshold
    int years = calculate_years(start, end);

    // Print number of years
    printf("Years: %i\n", years);
}

// Prompts user for start size, checks if greater than or equal to 9
// Because if less than 9, the population will stagnate
int get_start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

// Prompts user for end size, checks if greater than or equal to start size
int get_end_size(int s)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < s);
    return n;
}

// Calculates number of years from start size to end size in a loop
int calculate_years(int s, int e)
{
    int y = 0;
    while (e > s)
    {
        // In a year, n / 3 llamas are born and n / 4 llamas pass away
        s += s / 3 - s / 4;
        y++;
    }
    return y;
}
