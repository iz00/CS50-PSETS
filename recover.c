#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME_LENGTH 8

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

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

    BYTE buffer[BLOCK_SIZE];
    int files_counter = 0;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        FILE *output = NULL;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (files_counter > 0)
            {
                fclose(output);
            }

            char filename[FILENAME_LENGTH];
            sprintf(filename, "%03i.jpg", files_counter);

            output = fopen(filename, "a");
            if (output == NULL)
            {
                return 1;
            }

            files_counter++;
        }
        fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
        fclose(output);
    }

    fclose(input);
    return 0;
}
