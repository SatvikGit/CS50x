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
    int jfound = 0;
    FILE *w_ptr = NULL;

    // Iterates till fread returns 1
    while (fread(&buffer, 512, 1, r_ptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // Closes reading pointer even if one image is detected
            if (jfound == 1)
            {
                fclose(w_ptr);
            }

            else
            {
                jfound = 1;
            }

            char filename[9];
            sprintf(filename, "%03i.jpeg", counter);

            // Opens file for reading
            w_ptr = fopen(filename, "w");
            counter++;
        }

        // Writes to the file even if one image is detected
        if (counter == 1)
        {
            fwrite(&buffer, 512, 1, w_ptr);
        }

        fclose(r_ptr);
        fclose(w_ptr);

        return 0;
    }
}