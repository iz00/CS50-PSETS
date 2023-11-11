#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LENGTH 26

bool validate_argc(int c);
bool validate_argument(string v);

int main(int argc, string argv[])
{

    bool command_argument_valid = validate_argc(argc);

    if (command_argument_valid)
    {
        command_argument_valid = validate_argument(argv[1]);
    }

    if (! command_argument_valid)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("Plaintext:  ");

    printf("Ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'A' + key) % ALPHABET_LENGTH + 'A');
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'a' + key) % ALPHABET_LENGTH + 'a');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

bool validate_argc(int c)
{
    if (c != 2)
    {
        return false;
    }
    return true;
}


bool validate_argument(string v)
{
    for (int i = 0, len = strlen(v); i < len; i++)
    {
        if (isdigit(v[i]) == 0)
        {
            return false;
        }
    }

    if (atoi(v) < 0)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }

    return true;
}
