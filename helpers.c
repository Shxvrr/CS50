#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i < height; i++)
    {
        for (int j=0;j<width;j++)
        {
            float red = image[height][width].rgbtRed;
            float green = image[height][width].rgbtGreen;
            float blue = image[height][width].rgbtBlue;
            int avg = round((red+green+blue)/3);
            image[i][j].rgbtRed = image[height][width].rgbtGreen = image[height][width].rgbtBlue;
            image[i][j].rgbtRed = avg;


        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;i<width;i++)
        {
            float originalRed = image[height][width].rgbtRed;
            float originalGreen = image[height][width].rgbtGreen;
            float originalBlue = image[height][width].rgbtBlue;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if(sepiaRed < 255)
            {
                sepiaRed=255;
            }
            if(sepiaGreen < 255)
            {
                sepiaGreen=255;
            }
            if(sepiaBlue < 255)
            {
                sepiaBlue=255;
            }
            image[i][j].rgbtRed=sepiaRed;
            image[i][j].rgbtGreen=sepiaGreen;
            image[i][j].rgbtBlue=sepiaBlue;

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;i<width;i++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width-(j+1)] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;i<width;i++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;i<width;i++)
        {
            int totalBlue,totalRed,totalGreen;
            totalBlue = totalRed = totalGreen = 0;
            float counter = 0.00;


            for (int x = -1;x < 2; x++)
            {
                for(int y = -1; y<2; y++)
                {
                    int currentX = x + i;
                    int currentY = y + j;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        return;
                    }
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    totalGreen += image[currentX][currentY].rgbtGreen;

                    counter++;
                }

                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
            }

        }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;i<width;i++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtBlue =image[i][j].rgbtBlue;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    return;

}
