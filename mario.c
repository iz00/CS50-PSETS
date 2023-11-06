// Build a left alligned pyramid from mario with the height as user input

#include <cs50.h>
#include <stdio.h>

#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

int get_height(void);
void print_char_times(char c, int n);
void print_pyramid(int n);

int main(void)
{
    int height = get_height();

    print_pyramid(height);
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while ((n < MIN_HEIGHT) || (n > MAX_HEIGHT));

    return n;
}

void print_char_times(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}

void print_pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int num_empty_spaces = n - i;

        print_char_times(' ', num_empty_spaces);

        print_char_times('#', i);

        printf("\n");
    }
}
