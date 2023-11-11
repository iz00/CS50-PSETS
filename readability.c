#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int calculate_index(int letters, int words, int sentences);
void check_print_grade(int n);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Define three variables, letters count, words count, and sentences count
    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int sentences_count = count_sentences(text);

    int index = calculate_index(letters_count, words_count, sentences_count);

    check_print_grade(index);
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

int calculate_index(int letters, int words, int sentences)
{
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}

void check_print_grade(int n)
{
    if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (n > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", n);
    }
}
