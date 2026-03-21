#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"
#include <stdio.h>
#include <string.h>
#include "main.h"

const int MAX_BRIGHTNESS = 255; //the maximum value for a 8-bit color channel
const char DENSITY_CHARS[] = "_.=+:;!?c71236089$W#@"; //a list of characters based on the amount of space they take up
const double DENSITY_CHAR_RANGE = MAX_BRIGHTNESS / (float) (strlen(DENSITY_CHARS)); //the amount of values each density character accounts for

int main(void) {
    //Load the image
    int imageWidth, imageHeight, channels = 0; //declare parameters for the image and set them to 0 for now
    char imageName[] = "64x64_Gradient_Horizontal.jpg"; //declare and set imageName string to the name of the image file
    unsigned char *image = stbi_load(imageName, &imageWidth, &imageHeight, &channels, 0); //load the image using stb_image
    if (image == NULL) { //if image is NULL, loading failed
        printf("Error in loading image\n"); //print an error message
        exit(1); //close with an error status
    }

    //resize the image to what we want the output ascii art's dimensions to be
    int width = 128;               //will be changed when gui gets implemented
    int height = (int) width / 2.5;    
    unsigned char* resizedImage = stbir_resize_uint8_srgb(image,  imageWidth,  imageHeight,  0, 
                                                        NULL, width, height, 0, channels);
    if (resizedImage == NULL) {
        printf("Error in resizing image\n");
        exit(1);
    }

    
    //the original image malloc is no longer needed so free it and set the pointer to NULL
    stbi_image_free(image);
    image = NULL;
    
    //initialize and set imageSize for when we loop through pixels
    size_t imageSize = width * height * channels; 

    //initialize the output array of strings
    char outputAscii[height][width + 1]; 
    //loop through 2D array and set chars to null terminator
    for (int row = 0; row < height; row++) { 
        for (int column = 0; column < width; column++) {
            outputAscii[row][column] = '\0'; 
        }
        outputAscii[row][width] = 0;
    }

    //turn the resized image into ascii
    convertImageToAscii(resizedImage, imageSize, channels, width, outputAscii);

    //loop through each row of the outputAscii array and print it out
    for (int i = 0; i < height; i++) {
        printf("%s\n", outputAscii[i]);
    }


    return 0; //return 0 for success
}

//take an image a corrosponding 2D array of chars and turn the array into the ascii version of the image
void convertImageToAscii(unsigned char *image, size_t imageSize, int channels, int width, char outputAscii[][width + 1]) {
    //declare row and column index ints for looping through the 2D array and set them to 0
    int row = 0;
    int column = 0;

    //loop through each pixel in the picture
    for (unsigned char *currentPixel = image; currentPixel < image + imageSize; currentPixel += channels) {
        //check if column index has reached the end of the column and start on the next row
        if (column == width) { 
            column -= width;
            row++;
        }

        //get the brightness [0 - 255] of a pixel and assign a density character to that pixel
        int brightness = (int)((*currentPixel + *(currentPixel + 1) + *(currentPixel + 2))/3.0);
        char densityChar = DENSITY_CHARS[(int) (brightness / DENSITY_CHAR_RANGE)];
        //set the corrosponding char in the outputAscii array to the density char
        outputAscii[row][column] = densityChar;

        //increment column as we move on to the next pixel
        column++;
    }
}
