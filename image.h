#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    int largeur;
    int hauteur;
    int max_val;
    Pixel **pixels;
} Image;

Image *lire_image(const char *nom_fichier);
void ecrire_image(const char *nom_fichier, Image *img);
void liberer_image(Image *img);

#endif // IMAGE_H
