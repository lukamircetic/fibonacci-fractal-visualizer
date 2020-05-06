#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

void saveBMP(char* filename, int width, int height, RGB* rgb)
{
    FILE* f;
    unsigned char* img = NULL;
    int filesize = 54 + 3 * width * height;

    unsigned char bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0,
        0, 0, 0, 54, 0, 0, 0 };
    unsigned char bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 24, 0 };
    unsigned char bmppad[3] = { 0, 0, 0 };

    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    bmpinfoheader[4] = (unsigned char)(width);
    bmpinfoheader[5] = (unsigned char)(width >> 8);
    bmpinfoheader[6] = (unsigned char)(width >> 16);
    bmpinfoheader[7] = (unsigned char)(width >> 24);
    bmpinfoheader[8] = (unsigned char)(height);
    bmpinfoheader[9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);

    f = fopen(filename, "wb");

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    img = (unsigned char*)malloc(3 * width);

    int i, j;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            int index = j * width + i;
            img[i * 3 + 2] = rgb[index].r;
            img[i * 3 + 1] = rgb[index].g;
            img[i * 3 + 0] = rgb[index].b;
        }
        fwrite(img, 3, width, f);
        fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
    }
    fclose(f);
}
