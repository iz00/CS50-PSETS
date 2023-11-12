#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string validate_argc(int c);
string validate_argument(string v);
void print_ciphertext(string text, string key);

int main(int argc, string argv[])
{
    string command_argument_validation = validate_argc(argc);

    if (!strcmp(command_argument_validation, "valid"))
    {
        command_argument_validation = validate_argument(argv[1]);
    }

    if (strcmp(command_argument_validation, "valid"))
    {
        printf("%s\n", command_argument_validation);
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext:  ");

    // Encode plaintext with the key, converted from string to int, and print ciphertext
    print_ciphertext(plaintext, argv[1]);

    return 0;
}

string validate_argc(int c)
{
    if (c != 2)
    {
        return "Usage: ./substitution key";
    }
    return "valid";
}

string validate_argument(string v)
{
    int len = strlen(v);
    if (len != 26)
    {
        return "Key must contain 26 characters.";
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(v[i]))
        {
            return "Key must only contain alphabetic characters.";
        }

        for (int j = i + 1; j < len; j++)
        {
            if (tolower(v[i]) == tolower(v[j]))
            {
                return "Key must not contain repeated characters.";
            }
        }
    }
    return "valid";
}

void print_ciphertext(string text, string key)
{
    printf("Ciphertext: ");

    // Loop through text to get each character through i, len is calculated first for efficiency
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", toupper(key[text[i] - 'A']));
        }
        else if (islower(text[i]))
        {
            printf("%c", tolower(key[text[i] - 'a']));
        }
        // If character not a letter, just print it
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
