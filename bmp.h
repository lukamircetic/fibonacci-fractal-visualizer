
#ifndef BMP_H_
#define BMP_H_

typedef struct {
    /* red, green, and blue values */
    unsigned char r, g, b;
} RGB;

void saveBMP(char* file, int width, int height, RGB* image);

#endif
