#include "image.h"
#include<stdio.h>

void convertir_en_gris(Image *img) {
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            Pixel *p = &img->pixels[i][j];
            int m = (p->r + p->g + p->b) / 3;
            p->r = p->g = p->b = m;
        }
    }
    printf("image mise en gris!!\n");
    
}
