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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through image's pixels, in the matrix of height(i) and width(j)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE aux = image[i][j];
            image[i][j] = image[i][width - 1 - j];
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
            image_copy[i][j] = image[i][j];
        }
    }

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

                    if (pixel_height >= 0 && pixel_height <= height - 1 && pixel_width >= 0 && pixel_width <= width - 1)
                    {
                        average_red += image_copy[pixel_height][pixel_width].rgbtRed;
                        average_green += image_copy[pixel_height][pixel_width].rgbtGreen;
                        average_blue += image_copy[pixel_height][pixel_width].rgbtBlue;
                        pixels_formula++;
                    }
                }
            }

            // Put average colors in image's pixels
            image[i][j].rgbtRed = round(average_red / pixels_formula);
            image[i][j].rgbtGreen = round(average_green / pixels_formula);
            image[i][j].rgbtBlue = round(average_blue / pixels_formula);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gx_red = 0.0, gx_green = 0.0, gx_blue = 0.0;
            float gy_red = 0.0, gy_green = 0.0, gy_blue = 0.0;

            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    int pixel_height = i + h, pixel_width = j + w;

                    if (pixel_height >= 0 && pixel_height <= height - 1 && pixel_width >= 0 && pixel_width <= width - 1)
                    {
                        int gx_multiplier = w, gy_multiplier = h;

                        if (h == 0 || w == 0)
                        {
                            gx_multiplier *= 2;
                            gy_multiplier *= 2;
                        }

                        gx_red += image_copy[pixel_height][pixel_width].rgbtRed * gx_multiplier;
                        gx_green += image_copy[pixel_height][pixel_width].rgbtGreen * gx_multiplier;
                        gx_blue += image_copy[pixel_height][pixel_width].rgbtBlue * gx_multiplier;

                        gy_red += image_copy[pixel_height][pixel_width].rgbtRed * gy_multiplier;
                        gy_green += image_copy[pixel_height][pixel_width].rgbtGreen * gy_multiplier;
                        gy_blue += image_copy[pixel_height][pixel_width].rgbtBlue * gy_multiplier;
                    }
                }
            }

            image[i][j].rgbtRed = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            image[i][j].rgbtGreen = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            image[i][j].rgbtBlue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));
        }
    }
}
