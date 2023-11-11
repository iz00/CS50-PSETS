#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");

    int character_binary[BITS_IN_BYTE];
    int message_character;

    for (int i = 0, len = strlen(message); i < len; i++)
    {
        message_character = message[i];
        for (int j = 1; j <= BITS_IN_BYTE; j++)
        {
            character_binary[BITS_IN_BYTE - j] = message_character % 2;
            message_character /= 2;
        }
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(character_binary[j]);
        }
        printf("\n");
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
