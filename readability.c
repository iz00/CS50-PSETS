#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Define three variables, letters count, words count, and sentences count
    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int sentences_count = count_sentences(text);

    float L = letters_count / (float) words_count * 100.0;
    float S = sentences_count / (float) words_count * 100.0;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    printf("Grade %i\n", index);
}

int count_letters(string s)
{
    int n = 0;
    // Use isalpha in every character, if is increment letters count
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if(isalpha(s[i]))
        {
            n++;
        }
    }
    return n;
}

int count_words(string s)
{
    int n = 1;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if ((s[i] == ' ') && (i != 0) && (i != len - 1) && (s[i - 1] != ' '))
        {
            n++;
        }
    }
    return n;
}

int count_sentences(string s)
{
    int n = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            n++;
        }
    }
    return n;
}
