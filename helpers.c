// Functions to apply filters to images

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through image's pixels, in the matrix of height(i) and width(j)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get average pixel value and apply it to all channels
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through image's pixels, in the matrix of height(i) and width(j)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //
            RGBTRIPLE pixel = image[i][j];

            int sepia_red = round(pixel.rgbtRed * 0.393 + pixel.rgbtGreen * 0.769 + pixel.rgbtBlue * 0.189);
            int sepia_green = round(pixel.rgbtRed * 0.349 + pixel.rgbtGreen * 0.686 + pixel.rgbtBlue * 0.168);
            int sepia_blue = round(pixel.rgbtRed * 0.272 + pixel.rgbtGreen * 0.534 + pixel.rgbtBlue * 0.131);

            image[i][j].rgbtRed = (sepia_red > 255) ? 255 : sepia_red;
            image[i][j].rgbtGreen = (sepia_green > 255) ? 255 : sepia_green;
            image[i][j].rgbtBlue = (sepia_blue > 255) ? 255 : sepia_blue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through image's pixels, in the matrix of height(i) and width(j)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE aux = image[i][j];
            image[i][j] = image[i][width - 1- j];
            image[i][width - 1 - j] = aux;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
