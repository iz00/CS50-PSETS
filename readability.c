#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Define three variables, letters count, words count, and sentences count
    int letters_count = 0, words_count = 1, sentences_count = 0;

    // Loop through the entire text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Use isalpha in every character, if is increment letters count
        if(isalpha(text[i]))
        {
            letters_count++;
        }

        switch (text[i])
        {
            case ' ':
                words_count++;
                break;

            case '.':
            case '!':
            case '?':
                sentences_count++;
                break;
        }
    }

float L = letters_count / (float) words_count * 100.0;
float S = sentences_count / (float) words_count * 100.0;

int index = round(0.0588 * L - 0.296 * S - 15.8);

printf("Grade %i\n", index);
}
