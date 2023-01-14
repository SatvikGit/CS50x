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
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_blue;
            float sum_green;
            float sum_red;
            int counter;

            sum_blue = sum_green = sum_red = counter = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k > height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l > width)
                    {
                        continue;
                    }

                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    sum_red += temp[i + k][j + l].rgbtRed;
                    counter++;
                }
            }
            image[i][j].rgbtBlue = round(sum_blue / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtRed = round(sum_red / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
