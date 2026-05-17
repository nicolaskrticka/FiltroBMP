#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0 ; i <= height ; i++)
    {
        for (int j = 0 ; j <= width ; j++)
        {
            int GrayValue = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/ 3.0) ;
            image[i][j].rgbtRed = GrayValue;
            image[i][j].rgbtGreen = GrayValue;
            image[i][j].rgbtBlue = GrayValue;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int newred = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int newgreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int newblue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (newred > 255)
            {
                newred = 255;
            }
            if (newblue > 255)
            {
                newblue = 255;
            }
            if (newgreen > 255)
            {
                newgreen = 255;
            }

            image[i][j].rgbtRed = newred;
            image[i][j].rgbtGreen = newgreen;
            image[i][j].rgbtBlue = newblue;

        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width / 2; j++)
        {
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp[i][j];

        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int red,green,blue,size;
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            copy[i][j] = image[i][j];
        }
    }



    for (int i = 0; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            size = 0;
            for (int xi = i - 1 ; xi <= i + 1 ; xi++)
            {
                for (int xj = j - 1 ; xj <= j + 1; xj++)
                {

                    if ((xi >= 0 && xi <= (height - 1) && (xj >= 0 && xj <= (width - 1))))
                    {
                        size++;
                        red += round(copy[xi][xj].rgbtRed);
                        green += round(copy[xi][xj].rgbtGreen);
                        blue += round(copy[xi][xj].rgbtBlue);
                    }
                }
            }
            image[i][j].rgbtRed = round(red / (float)size);
            image[i][j].rgbtBlue = round(blue / (float)size);
            image[i][j].rgbtGreen = round(green / (float)size);
        }
    }
return;
}
