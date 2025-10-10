
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

void traiter_dominante(Image *, char, int);
void convertir_en_gris(Image *);
void afficher_taille(Image *);
Image *decouper(Image *, int, int, int, int);
void negatif(Image *);
void filtre_median(Image *);

int main() {
    char cmd[100];
    while (1) {
        printf("ppmviewer> ");
        fflush(stdout);
        if (!fgets(cmd, sizeof(cmd), stdin)) break;

        char *args[10];
        int n = 0;
        args[n++] = strtok(cmd, " \n");
        while (n < 10 && (args[n] = strtok(NULL, " \n"))) {
            n++;
        }
        if (args[0] == NULL) continue;

        if (strcmp(args[0], "quit") == 0) {
            break;
        } else if (strcmp(args[0], "dom") == 0 && n == 4) {
            char couleur = args[1][0];
            int val = atoi(args[2]);
            Image *img = lire_image(args[3]);
            if (!img) {
                printf("Erreur lecture image.\n");
                continue;
            }
            traiter_dominante(img, couleur, val);
            ecrire_image(args[3], img);
            liberer_image(img);
        } else if (strcmp(args[0], "gris") == 0 && n == 2) {
            Image *img = lire_image(args[1]);
            if (!img) continue;
            convertir_en_gris(img);
            ecrire_image(args[1], img);
            liberer_image(img);
        } else if (strcmp(args[0], "size") == 0 && n == 2) {
			Image *img = lire_image(args[1]);
            if (!img) continue;
            afficher_taille(img);
            liberer_image(img);
        } else if (strcmp(args[0], "cut") == 0 && n == 7) {
            Image *img = lire_image(args[1]);
            if (!img) continue;
            int l1 = atoi(args[2]), l2 = atoi(args[3]);
            int c1 = atoi(args[4]), c2 = atoi(args[5]);
            Image *sub = decouper(img, l1, l2, c1, c2);
            if (sub) {
                ecrire_image(args[6], sub);
                liberer_image(sub);
            } else {
                 printf("Découpage impossible.\n");
            }
            liberer_image(img);
        } else if (strcmp(args[0], "neg") == 0 && n == 3) {
            Image *img = lire_image(args[1]);
            if (!img) continue;
            negatif(img);
            ecrire_image(args[2], img);
            liberer_image(img);
        } else if (strcmp(args[0], "fil") == 0 && n == 3) {
            Image *img = lire_image(args[1]);
            if (!img) continue;
            filtre_median(img);
            ecrire_image(args[2], img);
            liberer_image(img);
        } else {
            printf("Commande inconnue ou arguments incorrects.\n");
        }
    }
    printf("Au revoir !\n");
    return 0;
}