#include <stdio.h>
#include <stdlib.h>
#include "image.h"

// Modifier les pixels selon la dominante
 void traiter_dominante(Image *img, char couleur, int val) {
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            Pixel *p = &img->pixels[i][j];
            int maxc = p->r;
            if (p->g > maxc) maxc = p->g;
            if (p->b > maxc) maxc = p->b;
            if ((couleur == 'R' && p->r == maxc) ||
                (couleur == 'G' && p->g == maxc) ||
                (couleur == 'B' && p->b == maxc)) {
                // appliquer la valeur
                p->r = p->r + val < 0 ? 0 : (p->r + val > img->max_val ? img->max_val : p->r + val);
                p->g = p->g + val < 0 ? 0 : (p->g + val > img->max_val ? img->max_val : p->g + val);
                p->b = p->b + val < 0 ? 0 : (p->b + val > img->max_val ? img->max_val : p->b + val);
            }
        }
    }
      printf("image modifiée avec succès!!!\n");
}