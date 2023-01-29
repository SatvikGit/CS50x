#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char* iname = argv[1];

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

    while (fread(&buffer, 512, 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                if (fclose(outptr) != 0)
                {
                    fclose(inptr);
                    return 1;
                }
            }

            sprintf(name, "%03d.jpg", counter);
            counter++;
        }

        outptr = fopen(name, "w");

        if (counter > 0)
        {
            fwrite(&buffer, 512, 1, outptr);
        }
    }

    fclose(inptr);
    fclose(outptr);

    return 0;
}