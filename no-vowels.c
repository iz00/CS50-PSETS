// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string sentence);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    string sentence_converted = replace(argv[1]);

    printf("%s\n", sentence_converted);
}

string replace(string sentence)
{
    for (int i = 0, len = strlen(sentence); i < len; i++)
    {
        switch (sentence[i])
        {
            case 'a':
                sentence[i] = '6';
                break;
            case 'e':
                sentence[i] = '3';
                break;
            case 'i':
                sentence[i] = '1';
                break;
            case 'o':
                sentence[i] = '0';
                break;
        }
    }
    return sentence;
}
