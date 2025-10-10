#include <stdlib.h>
#include <stdio.h>
#include "image.h"

Image *decouper(Image *img, int l1, int l2, int c1, int c2) {
    if (l1 < 0 || l2 > img->hauteur || c1 < 0 || c2 > img->largeur || l1 >= l2 || c1 >= c2) {
        printf("Coordonnées de découpage invalides.\n");
        return NULL;
    }
    Image *res = malloc(sizeof(Image));
    res->largeur = c2 - c1;
    res->hauteur = l2 - l1;
    res->max_val = img->max_val;

    res->pixels = malloc(res->hauteur * sizeof(Pixel *));
    for (int i = 0; i < res->hauteur; i++) {
        res->pixels[i] = malloc(res->largeur * sizeof(Pixel));
        for (int j = 0; j < res->largeur; j++) {
            res->pixels[i][j] = img->pixels[l1 + i][c1 + j];
        }
    }
    printf("votre image a bien été coupée et crée!!!\n");
    return res;
}
