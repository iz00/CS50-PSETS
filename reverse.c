// Reverse the audio of a WAV file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);
void write_reversed_audio(FILE *in, FILE *out, int size);

int main(int argc, char *argv[])
{
    // Ensure proper usage (2 command-line arguments)
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file in read mode
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read header
    WAVHEADER input_header;
    fread(&input_header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    if (!check_format(input_header))
    {
        printf("Input is not a WAV file.\n");
        fclose(input);
        return 1;
    }

    // Open output file in write mode
    FILE *output = fopen(argv[2], "wb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        fclose(input);
        return 1;
    }

    // Write header to output file
    fwrite(&input_header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(input_header);

    // Write reversed audio to file
    write_reversed_audio(input, output, block_size);

    fclose(input);
    fclose(output);

    return 0;
}

// Check if file is WAV
int check_format(WAVHEADER header)
{
    // Compare the signature format header of WAV files with header from input file
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

// Get block size (in bytes) through number of channels and bits per sample in input file header
int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}

void write_reversed_audio(FILE *in, FILE *out, int size)
{
    int header_position = ftell(in);

    BYTE buffer[size];

    fseek(in, size * (-1), SEEK_END);

    while (ftell(in) >= header_position)
    {
        fread(buffer, sizeof(BYTE), size, in);
        fseek(in, size * (-2), SEEK_CUR);
        fwrite(buffer, sizeof(BYTE), size, out);
    }
}
