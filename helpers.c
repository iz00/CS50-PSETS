#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            BYTE red_amount = pixel.rgbtRed;
            BYTE green_amount = pixel.rgbtGreen;
            BYTE blue_amount = pixel.rgbtBlue;
            if (red_amount == 255 && green_amount == 255 && blue_amount == 255)
            {
                image[i][j].rgbtRed = 33;
                image[i][j].rgbtGreen = 145;
                image[i][j].rgbtBlue = 251;
            }
        }
    }
}
