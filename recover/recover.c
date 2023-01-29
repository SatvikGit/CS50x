#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t = BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    iname = argv[1];

    FILE *inptr = fopen(iname, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", iname);
        return 1;
    }

    
}