#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLATE_DIGITS 7
#define PLATES_AMOUNT 8

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[PLATE_DIGITS];

    // Create array to store plate numbers
    char *plates[PLATES_AMOUNT];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, sizeof(char), PLATE_DIGITS, infile) == PLATE_DIGITS)
    {
        // Replace '\n' with '\0'
        buffer[PLATE_DIGITS - 1] = '\0';

        plates[idx] = malloc(PLATE_DIGITS);

        // Save plate number in array
        strcpy(plates[idx], buffer);

        idx++;
    }



    for (int i = 0; i < PLATES_AMOUNT; i++)
    {
        printf("%s\n", plates[i]);
    }
}
