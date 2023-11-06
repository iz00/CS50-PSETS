#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    int j;

    for (int i = 1; i <= height; i++)
    {
        int num_empty_spaces = height - i;
        for (j = 0; j < num_empty_spaces; j++)
        {
            printf(" ");
        }

        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
