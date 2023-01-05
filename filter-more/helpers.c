#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE newpixel_g = (RGBTRIPLE.rgbtBlue + RGBTRIPLE.rgbtGreen + RGBTRIPLE.rgbtRed) / 3;
            
            RGBTRIPLE.rgbtBlue = newpixel_g;
            RGBTRIPLE.rgbtGreen = newpixel_g;
            RGBTRIPLE.rgbtRed = newpixel_g;

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
