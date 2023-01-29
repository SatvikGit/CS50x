#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Checks for correct number of cmd line arguements
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *image_name = argv[1];

    // Opens file for reading
    FILE *r_ptr = fopen(image_name, "r");
    if (r_ptr == NULL)
    {
        printf("Could not open %s\n", image_name);
        return 1;
    }

    unsigned char buffer[512];
    int counter = 0;
    FILE *w_ptr = NULL;
    char *filename = malloc(8 * sizeof(char));

    // Iterates till fread returns 1
    while (fread(buffer, 512, 1, r_ptr))
    {
        // Checks if file opened is indeed a jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Closes reading pointer even if one image is detected
            if (w_ptr != NULL)
            {
                fclose(w_ptr);
            }
            
            sprintf(filename, "%03i.jpeg", counter);

            // Opens file for reading
            w_ptr = fopen(filename, "w");
            counter++;
        }

        // Writes to file if writing pointer has been opened correctly
        if (w_ptr != NULL)
        {
            fwrite(buffer, 512, 1, w_ptr);
        }
    }

    // Frees the allocated memory and closes filepointers
    free(filename);
    fclose(r_ptr);
    fclose(w_ptr);

    return 0;
}