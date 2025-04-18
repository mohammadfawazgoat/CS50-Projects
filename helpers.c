#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < width; x++)
        {
            int red = image[i][x].rgbtRed;
            int blue = image[i][x].rgbtBlue;
            int green = image[i][x].rgbtGreen;

            int avg = round((red + blue + green) / 3.0);

            image[i][x].rgbtRed = avg;
            image[i][x].rgbtBlue = avg;
            image[i][x].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < width; x++)
        {
            int ored = image[i][x].rgbtRed;
            int ogreen = image[i][x].rgbtGreen;
            int oblue = image[i][x].rgbtBlue;
            // calculate sepia value of rgb
            int sepiared = round(0.393 * ored + 0.769 * ogreen + 0.189 * oblue);
            int sepiagreen = round(0.349 * ored + 0.686 * ogreen + 0.168 * oblue);
            int sepiablue = round(0.272 * ored + 0.534 * ogreen + 0.131 * oblue);
            if (sepiared > 255)
            {
                sepiared = 255;
            }
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }
            image[i][x].rgbtRed = sepiared;
            image[i][x].rgbtGreen = sepiagreen;
            image[i][x].rgbtBlue = sepiablue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < width/2; x++)
        {
            RGBTRIPLE temp = image[i][x];
            image[i][x] = image[i][width - x - 1];
            image[i][width - x - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i =0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            int sumred = 0;
            int sumgreen =0;
            int sumblue = 0;
            int count =0;
            for(int di = -1; di<=1;di++)
            {
                for(int dj =-1;dj<=1;dj++)
                {
                    int ni = i + di;
                    int nj =j + dj;
                    if(ni>=0 && ni< height && nj>=0 && nj <width)
                    {
                        sumred += image[ni][nj].rgbtRed;
                        sumgreen += image[ni][nj].rgbtGreen;
                        sumblue += image[ni][nj].rgbtBlue;
                        count ++;
                    }
                }
            }
            temp[i][j].rgbtRed = round((float)sumred/count);
            temp[i][j].rgbtGreen = round((float)sumgreen/count);
            temp[i][j].rgbtBlue = round((float)sumblue/count);

        }

    }
    for(int i=0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            image[i][j]=temp[i][j];
        }
    }
    return;
}
