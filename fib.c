#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>
#include <math.h>
#define MAX 9999999
char* fibcatenate(int n)
{
    char* f1 = malloc(MAX);
    char* f2 = malloc(MAX);
    f1 = "1";
    f2 = "0";
    char *lower = malloc(MAX+1);
    strcpy(lower,f1);
    char *higher = malloc(MAX+1);
    strcpy(higher,f2);
    int i;
    for (i=0;i<=(n-3);i++)
    {
        
        char *temp = malloc(MAX); 
        strcpy(temp,higher);
        strcat(temp, lower);
        /*printf("f1 = %s, f2 = %s, f3 = %s\n", lower,higher,f3);*/
        lower = higher;
        higher = temp;
        /*printf("after assignment: f1 = %s, f2 = %s, f3 = %s\n", lower,higher,f3);*/
    }
    return higher;
}
typedef enum {
    up,
    down,
    left,
    right
} direction;
void draw(int x, int y, direction dir, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (dir == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (dir == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (dir == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (dir == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}
int fib(int n, int x, int y, int step, RGB b, RGB f, int w, int h, RGB* image){
    char *fibdigits = fibcatenate(n);
    int j;
    int k = strlen(fibdigits);
    direction dir = 0;
    int l;
    for(l=0;l<w*h;l++){
        image[l] = b;
    }
    for (j=0;j<k;j++){
        draw(x,y,dir,step,w,image,f);
        switch(dir){
            case(up):{
                x+=step;
                break;
            }            
            case(down):{
                x-=step;
                break;
            }
            case(right):{
                y+= step;
                break;
            }
            case(left):{
                y-=step;
                break;
            }
        }
        if (fibdigits[j] == '0')
        {
            if ((j+1) % 2 == 0){
                switch(dir){
                    case up:{
                        dir = 2;
                        break;
                    }
                    case down:{
                        dir = 3;
                        break;
                    }
                    case left:{
                        dir = 1;
                        break;
                    }
                    case right:{
                        dir = 0;
                        break;
                    }
                }
            }
            else{
                switch(dir){
                    case up:{
                        dir = 3;
                        break;
                    }
                    case down:{
                        dir = 2;
                        break;
                    }
                    case left:{
                        dir = 0;
                        break;
                    }
                    case right:{
                        dir = 1;
                        break;
                    }
                }
            }
        }
        /*printf("Direction = %d\n", dir);*/
    }
    return k;
}

