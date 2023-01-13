#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE newpixel_g;
            newpixel_g = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = newpixel_g;
            image[i][j].rgbtGreen = newpixel_g;
            image[i][j].rgbtRed = newpixel_g;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/ 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (image[k][l] != 0)
                    {
                        BYTE arr_blue[] = [image[k][l]];
                        int len_blue = sizeof(arr_blue) / sizeof(arr_blue[0]);
                        for (int a = 0; a < len_blue; a++)
                        {
                            BYTE blur_blue = round(arr_blue[a] / len_blue);
                            image[i][j].rgbtBlue = blur_blue;
                        }

                        BYTE arr_green[] = [image[k][l]];
                        int len_green = sizeof(arr_green) / sizeof(arr_green[0]);
                        for (int a = 0; ; a++)
                        {
                            BYTE blur_green = round(arr_green[a] / len_green);
                            image[i][j].rgbtGreen = blur_green;
                        }

                        BYTE arr_red[] = [image[k][l]];
                        int len_red = sizeof(arr_red) / sizeof(arr_red[0]);
                        for (int a = 0; ; a++)
                        {
                            BYTE blur_red = round(arr_red[a] / len_red);
                            image[i][j].rgbtRed = blur_red;
                        }
                    }
                }
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
