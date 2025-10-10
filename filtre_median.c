#include <stdio.h>
#include <stdlib.h>
#include "image.h"


int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


void filtre_median(Image *img) {
    Image *copie = malloc(sizeof(Image));
    copie->largeur = img->largeur;
    copie->hauteur = img->hauteur;
    copie->max_val = img->max_val;

   
    copie->pixels = malloc(img->hauteur * sizeof(Pixel *));
    for (int i = 0; i < img->hauteur; i++) {
        copie->pixels[i] = malloc(img->largeur * sizeof(Pixel));
        for (int j = 0; j < img->largeur; j++) {
            copie->pixels[i][j] = img->pixels[i][j];
        }
    }

    int voisins_r[9], voisins_g[9], voisins_b[9];
    for (int i = 1; i < img->hauteur - 1; i++) {
        for (int j = 1; j < img->largeur - 1; j++) {
            int k = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    Pixel p = copie->pixels[i + di][j + dj];
                    voisins_r[k] = p.r;
                    voisins_g[k] = p.g;
                    voisins_b[k] = p.b;
                    k++;
                }
            }
     qsort(voisins_r, 9, sizeof(int), cmp_int);
            qsort(voisins_g, 9, sizeof(int), cmp_int);
            qsort(voisins_b, 9, sizeof(int), cmp_int);
            img->pixels[i][j].r = voisins_r[4];
            img->pixels[i][j].g = voisins_g[4];
            img->pixels[i][j].b = voisins_b[4];
        }
    }
    for (int i = 0; i < copie->hauteur; i++) {
        free(copie->pixels[i]);
    }
    free(copie->pixels);
    free(copie);
    printf("image filtrée crée!!!\n");
}
