#include <stdio.h>
#include "image.h"
void afficher_taille(Image *img) {
    printf("Taille : %d × %d = %d pixels\n",
        img->largeur, img->hauteur,
        img->largeur * img->hauteur);
}
