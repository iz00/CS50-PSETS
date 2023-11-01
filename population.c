#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int a);
int calculate_years(int s, int e);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_start_size();

    // TODO: Prompt for end size
    int end = get_end_size(start);

    // TODO: Calculate number of years until we reach threshold
    int years = calculate_years(start, end);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

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

int get_end_size(int a)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < a);
    return n;
}

int calculate_years(int s, int e)
{
    int i = 0;
    while (e > s)
    {
        s += s / 3 - s / 4;
        i++;
    }
    return i;
}
