#include "image.h"
#include<stdio.h>


void negatif(Image *img) {
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            Pixel *p = &img->pixels[i][j];
            p->r = img->max_val - p->r;
            p->g = img->max_val - p->g;
            p->b = img->max_val - p->b;
        }
    }
    printf("votre image a bien été crée!!!\n");
}