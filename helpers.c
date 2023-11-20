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
        for (int j = 0; j < width / 2; j++)
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
    RGBTRIPLE image_copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average_red = 0.0, average_green = 0.0, average_blue = 0.0;
            int pixels_formula = 0;

            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    int pixel_height = i + h, pixel_width = j + w;

                    if (pixel_height >= 0 && pixel_height < height - 1 && pixel_width >= 0 && pixel_width < width - 1)
                    {
                        average_red += image[i][j].rgbtRed;
                        average_green += image[i][j].rgbtGreen;
                        average_blue += image[i][j].rgbtBlue;
                        pixels_formula++;
                    }
                }
            }


            /*
            average_red += image[i][j].rgbtRed;
            average_green += image[i][j].rgbtGreen;
            average_blue += image[i][j].rgbtBlue;
            pixels_formula++;

            if (i > 0)
            {
                // pegar pixel em cima (diminuir i)
                average_red += image[i - 1][j].rgbtRed;
                average_green += image[i - 1][j].rgbtGreen;
                average_blue += image[i - 1][j].rgbtBlue;
                pixels_formula++;

                if (j > 0)
                {
                    // pegar pixel à esquerda (diminuir j)
                    average_red += image[i - 1][j - 1].rgbtRed;
                    average_green += image[i - 1][j - 1].rgbtGreen;
                    average_blue += image[i - 1][j - 1].rgbtBlue;
                    pixels_formula++;
                }

                if (j < width - 1)
                {
                    // pegar pixel à direita (aumentar j)
                    average_red += image[i - 1][j + 1].rgbtRed;
                    average_green += image[i - 1][j + 1].rgbtGreen;
                    average_blue += image[i - 1][j + 1].rgbtBlue;
                    pixels_formula++;
                }
            }

            if (i < height - 1)
            {
                // pegar pixel embaixo (aumentar i)
                average_red += image[i + 1][j].rgbtRed;
                average_green += image[i + 1][j].rgbtGreen;
                average_blue += image[i + 1][j].rgbtBlue;
                pixels_formula++;

                if (j > 0)
                {
                    // pegar pixel à esquerda (diminuir j)
                    average_red += image[i + 1][j - 1].rgbtRed;
                    average_green += image[i + 1][j - 1].rgbtGreen;
                    average_blue += image[i + 1][j - 1].rgbtBlue;
                    pixels_formula++;
                }

                if (j < width - 1)
                {
                    // pegar pixel à direita (aumentar j)
                    average_red += image[i + 1][j + 1].rgbtRed;
                    average_green += image[i + 1][j + 1].rgbtGreen;
                    average_blue += image[i + 1][j + 1].rgbtBlue;
                    pixels_formula++;
                }
            }

            if (j > 0)
            {
                // pegar pixel à esquerda (diminuir j)
                average_red += image[i][j - 1].rgbtRed;
                average_green += image[i][j - 1].rgbtGreen;
                average_blue += image[i][j - 1].rgbtBlue;
                pixels_formula++;
            }

            if (j < width - 1)
            {
                // pegar pixel à direita (aumentar j)
                average_red += image[i][j + 1].rgbtRed;
                average_green += image[i][j + 1].rgbtGreen;
                average_blue += image[i][j + 1].rgbtBlue;
                pixels_formula++;
            }
            */

            // Put average colors in copy's pixels
            copy[i][j].rgbtRed = round(average_red / pixels_formula);
            copy[i][j].rgbtGreen = round(average_green / pixels_formula);
            copy[i][j].rgbtBlue = round(average_blue / pixels_formula);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}
