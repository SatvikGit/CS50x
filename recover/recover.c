#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checks for correct number of cmd arguements
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char* iname = argv[1];

    // Opens file pointer for reading
    FILE *inptr = fopen(iname, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", iname);
        return 1;
    }

    BYTE buffer[512];
    int counter = 0;
    FILE *outptr = NULL;
    char name[8];

    // Checks that file read correctly
    while (fread(&buffer, 512, 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                // Checks if writing pointer is null or not
                if (fclose(outptr) != 0)
                {
                    fclose(inptr);
                    return 1;
                }
            }

            sprintf(name, "%03d.jpg", counter);
            counter++;

            // Opens file pointer for writing
            outptr = fopen(name, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                return 1;
            }
        }

        if (counter > 0)
        {
            fwrite(&buffer, 512, 1, outptr);
        }
    }

    // Closes file pointers
    fclose(inptr);
    fclose(outptr);

    return 0;
}