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
    FILE* filer = fopen("input.wav", "r")
    if (filer == NULL)
    {
        printf("Input is not a WAV file\n");
        return 2;
    }

    // Read header into an array
    fread(WAVHEADER.chunkID, sizeof(BYTE), 4, filer);
    fread(&WAVHEADER.chunkSize, sizeof(DWORD), 1, filer);
    fread(WAVHEADER.format, sizeof(BYTE), 4, filer);
    fread(WAVHEADER.subchunk1ID, sizeof(BYTE), 4, filer);
    fread(&WAVHEADER.subchunk1Size, sizeof(DWORD), 1, filer);
    fread(&WAVHEADER.audioformat, sizeof(WORD), 1, filer);
    fread(&WAVHEADER.numChannels, sizeof(WORD), 1, filer);
    fread(&WAVHEADER.sampleRate, sizeof(DWORD), 1, filer);
    fread(&WAVHEADER.byteRate, sizeof(DWORD), 1, filer);
    fread(&WAVHEADER.blockAlign, sizeof(WORD), 1, filer);
    fread(&WAVHEADER.bitsPerSample, sizeof(WORD), 1, filer);
    fread(WAVHEADER.subchunk2ID, sizeof(BYTE), 4, filer);
    fread(&WAVHEADER.subchunk2Size, sizeof(DWORD), 1, filer);

    // Use check_format to ensure WAV format
    

    // Open output file for writing
    // TODO #5

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
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}