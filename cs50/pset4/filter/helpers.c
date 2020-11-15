#include "helpers.h"
#include <math.h>

void cap(int x);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]){
    int average;

    for(int i = 0;i < height;i++){

        for(int j = 0;j < width;j++){
            average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]){
    int rgbred, rgbgreen, rgbblue;

    for(int i = 0;i < height;i++){

        for(int j = 0;j < width / 2;j++){

            rgbred = image[i][j].rgbtRed;
            rgbgreen = image[i][j].rgbtGreen;
            rgbblue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = rgbred;
            image[i][width - j - 1].rgbtGreen = rgbgreen;
            image[i][width - j - 1].rgbtBlue = rgbblue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]){
    int sumred;
    int sumgreen;
    int sumblue;
    float neighbours;

    RGBTRIPLE temp[height][width];
    for(int i = 0;i < width;i++){

        for(int j = 0;j < height;j++){
            sumred = 0;
            sumgreen = 0;
            sumblue = 0;
            neighbours = 0.00;

            for(int y = -1;y < 2;y++){

                if(j + y < 0 || j + y == height){
                    continue;
                }

                for(int x = -1;x < 2;x++){

                    if(i + x < 0 || i + x == width){
                        continue;
                    }

                    sumred += image[j + y][i + x].rgbtRed;
                    sumgreen += image[j + y][i + x].rgbtGreen;
                    sumblue += image[j + y][i + x].rgbtBlue;

                    neighbours++;
                }
            }

            temp[j][i].rgbtRed = round(sumred / neighbours);
            temp[j][i].rgbtGreen = round(sumgreen / neighbours);
            temp[j][i].rgbtBlue = round(sumblue / neighbours);
        }
    }

    for(int i = 0;i < width;i++){

        for(int j = 0;j < height;j++){
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]){
    int GxRed, GxGreen, GxBlue;
    int GyRed, GyGreen, GyBlue;

    long red, green, blue;

    int GxMatrix[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    int GyMatrix[3][3] = {{-1,-2,-1}, {0,0,0}, {1,2,1}};

    RGBTRIPLE temp[height][width];

    for(int i = 0;i < height;i++){

        for(int j = 0;j < width;j++){
            GxRed = 0;
            GxGreen = 0;
            GxBlue = 0;
            GyRed = 0;
            GyGreen = 0;
            GyBlue = 0;

            for(int y = -1;y < 2;y++){

                if(i + y < 0 || i + y == height){
                    continue;
                }

                for(int x = -1;x < 2;x++){

                    if(j + x < 0 || j + x == width){
                        continue;
                    }

                    GxRed += image[i + y][j + x].rgbtRed * GxMatrix[y + 1][x + 1];
                    GxGreen += image[i + y][j + x].rgbtGreen * GxMatrix[y + 1][x + 1];
                    GxBlue += image[i + y][j + x].rgbtBlue * GxMatrix[y + 1][x + 1];

                    GyRed += image[i + y][j + x].rgbtRed * GyMatrix[y + 1][x + 1];
                    GyGreen += image[i + y][j + x].rgbtGreen * GyMatrix[y + 1][x + 1];
                    GyBlue += image[i + y][j + x].rgbtBlue * GyMatrix[y + 1][x + 1];
                }
            }

            red = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));
            green = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            blue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));

            if(red > 255){
                red = 255;
            }

            if(green > 255){
                green = 255;
            }

            if(blue > 255){
                blue = 255;
            }

            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }

    for(int i = 0;i < height;i++){

        for(int j = 0;j < width;j++){
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
}