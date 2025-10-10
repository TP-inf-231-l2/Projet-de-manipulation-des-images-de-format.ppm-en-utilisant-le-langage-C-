#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

Image *lire_image(const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return NULL;
    }
    char format[3];
    fscanf(f, "%2s", format);
    if (strcmp(format, "P3") != 0) {
        printf("Format non supporté : %s\n", format);
        fclose(f);
        return NULL;
    }
    Image *img = malloc(sizeof(Image));
    fscanf(f, "%d %d", &img->largeur, &img->hauteur);
      fscanf(f, "%d", &img->max_val);

    img->pixels = malloc(img->hauteur * sizeof(Pixel *));
    for (int i = 0; i < img->hauteur; i++) {
        img->pixels[i] = malloc(img->largeur * sizeof(Pixel));
        for (int j = 0; j < img->largeur; j++) {
            fscanf(f, "%d %d %d", &img->pixels[i][j].r,
                                   &img->pixels[i][j].g,
                                   &img->pixels[i][j].b);
        }
    }

    fclose(f);
    return img;
}

void ecrire_image(const char *nom_fichier, Image *img) {
    FILE *f = fopen(nom_fichier, "w");
    if (!f) {
        perror("Erreur écriture fichier");
        return;
    }
    fprintf(f, "P3\n%d %d\n%d\n", img->largeur, img->hauteur, img->max_val);
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            Pixel p = img->pixels[i][j];
            fprintf(f, "%d %d %d\n", p.r, p.g, p.b);
        }
    }
    fclose(f);
}

void liberer_image(Image *img) {
    if (!img) return;
    for (int i = 0; i < img->hauteur; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}
