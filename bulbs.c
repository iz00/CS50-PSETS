#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void convert_character_binary(int character_binary[], int character_decimal);
void print_bulb(int bit);
void print_character_bulbs(int character_binary[]);

int main(void)
{
    string message = get_string("Message: ");

    int character_binary_digits[BITS_IN_BYTE];

    for (int i = 0, len = strlen(message); i < len; i++)
    {
        convert_character_binary(character_binary_digits, message[i]);

        print_character_bulbs(character_binary_digits);
    }
}

void convert_character_binary(int character_binary[], int character_decimal)
{
    for (int i = 0; i < BITS_IN_BYTE; i++)
        {
            character_binary[BITS_IN_BYTE - 1 - i] = character_decimal % 2;
            character_decimal /= 2;
        }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void print_character_bulbs(int character_binary[])
{
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        print_bulb(character_binary[i]);
    }
    printf("\n");
}
