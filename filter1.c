#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>


    RGBTRIPLE arr[height][width];
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        arr[i][j] = image[i][j];
    }
}
float r, b, g;
float counter = 0;

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        for (int k = -1; k < 2; k++)
        {
            for (int l = -1; l < 2; l++)
            {
                if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1)
                {
                    r += arr[i + k][j + l].rgbtRed;
                    b += arr[i + k][j + l].rgbtBlue;
                    g += arr[i + k][j + l].rgbtGreen;
                    counter++;
                }

            }
        }
        r = r / counter;
        b = b / counter;
        g = g / counter;
        if (r > 255)
        {
            r = 255;
        }
        if (r < 0)
        {
            r = 0;
        }
        if (g > 255)
        {
            g = 255;
        }
        if (g < 0)
        {
            g = 0;
        }
        if (b > 255)
        {
            b = 255;
        }
        if (b < 0)
        {
            b = 0;
        }
        image[i][j].rgbtRed = round(r);
        image[i][j].rgbtBlue = round(b);
        image[i][j].rgbtGreen = round(g);
        counter = 0;
        r = 0;
        g = 0;
        b = 0;
    }
}
