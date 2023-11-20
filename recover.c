#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME_LENGTH 8

// typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    int files_counter = 0;
    FILE *output = NULL;
    char filename[FILENAME_LENGTH];

    while (fread(buffer, 1, BLOCK_SIZE, input))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (files_counter > 0)
            {
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", files_counter);

            output = fopen(filename, "w");
            if (output == NULL)
            {
                fclose(input);
                printf("Could not open file\n");
                return 1;
            }

            files_counter++;
        }

        fwrite(buffer, 1, BLOCK_SIZE, output);
    }

    fclose(output);
    fclose(input);
    return 0;
}
