#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage : ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    char* file_name = argv[1];
    FILE* filer = fopen(file_name, "r");
    if (filer == NULL)
    {
        printf("Input is not a WAV file\n");
        return 2;
    }

    // Read header into an array
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, filer);

    // Use check_format to ensure WAV format
    check_format(header);

    // Open output file for writing
    FILE* filew = fopen(file_name, "w");
    if (filew == NULL)
    {
        return 3;
    }

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}