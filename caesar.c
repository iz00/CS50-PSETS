#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    string text = get_string("plaintext:  ");

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        if (islower(text[i]))
        {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }

    printf("ciphertext: %s\n", text);

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
