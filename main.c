#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdio.h>

const char DENSITY_CHARS[] = "@#W$98763210?!abc;:+=-,._";

int main(void) {
    int width, height, channels; //declare width, height, and channel ints for the image
    char imageName[] = "64x64_Gradient.jpg"; //declare and set imageName string to the name of the image file
    unsigned char *image = stbi_load(imageName, &width, &height, &channels, 0); //load the image using stb_image
    if (image == NULL) { //if image is NULL, loading failed
        printf("Error in loading image\n"); //return an error message
        exit(1); //close with an error status
    }

    stbi_image_free(image);

    printf("Width: %d\nHeight: %d\n", width, height);
    return 0;
}