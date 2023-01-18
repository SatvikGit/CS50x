#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates through every pixel of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int newpixel_g;
            float Blue = image[i][j].rgbtBlue;
            float Green = image[i][j].rgbtGreen;
            float Red = image[i][j].rgbtRed;

            // Calculates new value for each pixel
            newpixel_g = round((Blue + Green + Red) / 3);

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
    // Iterates through each pixel but only till half of width because we just have to reflect transfer each pixel to opposite side
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    // Stores image value in a temp array because original pixels will be blurred simunltaneously as we iterate through the image
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

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Checks if the pixel is not out of image especially for corner pixels
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
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
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Initializes Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Gx_blue;
            float Gx_green;
            float Gx_red;
            float Gy_blue;
            float Gy_green;
            float Gy_red;

            Gx_blue = Gx_green = Gx_red = Gy_blue = Gy_green = Gy_red = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }

                    // Calculate new values after applying Sobel's algorithm
                    Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    Gy_blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                    Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_red += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                }
            }

            // Stores new values for Gx and Gy in a single temporary variable
            int Blue = round(sqrt((Gx_blue * Gx_blue + Gy_blue * Gy_blue)));
            int Green = round(sqrt((Gx_green * Gx_green + Gy_green * Gy_green)));
            int Red = round(sqrt((Gx_red * Gx_red + Gy_red * Gy_red)));

            // Cap these value at 255
            if (Blue > 255)
            {
                Blue = 255;
            }

            if (Green > 255)
            {
                Green = 255;
            }

            if (Red > 255)
            {
                Red = 255;
            }

            // Update original pixels in the image
            image[i][j].rgbtBlue = Blue;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtRed = Red;
        }
    }
    return;
}
