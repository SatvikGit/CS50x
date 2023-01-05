#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE newpixel_g[i][j] = round((RGBTRIPLE.rgbtBlue[i][j] + RGBTRIPLE.rgbtGreen[i][j] + RGBTRIPLE.rgbtRed[i][j]) / 3);

            RGBTRIPLE.rgbtBlue[i][j] = newpixel_g[i][j];
            RGBTRIPLE.rgbtGreen[i][j] = newpixel_g[i][j];
            RGBTRIPLE.rgbtRed[i][j] = newpixel_g[i][j];
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
