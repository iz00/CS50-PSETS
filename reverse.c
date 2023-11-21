#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER input_header;
    fread(&input_header, sizeof(WAVHEADER), 1, input);
    //long input_position = ftell(input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(input_header))
    {
        printf("Input is not a WAV file.\n");
        fclose(input);
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        fclose(input);
        return 1;
    }

    // Write header to output file
    // TODO #6
    fwrite(&input_header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(input_header);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];

    while (fread(buffer, sizeof(BYTE), block_size, input))
    {
        continue;
    }

    fseek(input, block_size * (-1), ftell(input));

    while (ftell(input) != input_position)
    {
        fread(buffer, sizeof(BYTE), block_size, input);
        fseek(input, block_size * (-2), ftell(input));
        fwrite(buffer, sizeof(BYTE), block_size, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}

int check_format(WAVHEADER header)
{
    char signature_format[] = {'W', 'A', 'V', 'E'};

    for (int i = 0; i < 4; i++)
    {
        if (signature_format[i] != header.format[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}
