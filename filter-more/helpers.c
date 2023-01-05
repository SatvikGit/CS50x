#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE newpixel_g[i][j] = round((RGBTRIPLE[i][j].rgbtBlue + RGBTRIPLE[i][j].rgbtGreen + RGBTRIPLE[i][j].rgbtRed) / 3);

            RGBTRIPLE[i][j].rgbtBlue = newpixel_g[i][j];
            RGBTRIPLE[i][j].rgbtGreen = newpixel_g[i][j];
            RGBTRIPLE[i][j].rgbtRed = newpixel_g[i][j];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
