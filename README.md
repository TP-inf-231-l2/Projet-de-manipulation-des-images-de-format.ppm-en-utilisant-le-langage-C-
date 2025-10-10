# Projet-de-manipulation-des-images-de-format.ppm
#ICI NOTRE README FAIT EN 3 PARTIES…

Bonjour et Bienvenue à vous!!!
.....
----Projet C INF231 Manipulation des images au format « .ppm »

Ce projet contient plusieurs fichiers C illustrant différentes opérations sur une image(dans ce cas au format ppm). Chaque fichier implémente une fonctionnalité spécifique de manipulation d’image, avec des mises en gris, découpage, filtres et formatage

CE README EST COMPOSE DE :
         -fichiers et explications
         -comment utiliser
         -organisation de travail du groupe

------Fichiers inclus

1. dominante.c
- Fonctionnalité : Foncer ou éclaircir des pixels selon la dominante
- Entrée :
	Commande : dom c val fichier.ppm
	C    est la couleur
	Val   la valeur 
	Fichier est le nom de votre fichier  au format .ppm
- Sortie :Modification de l’image+message de confirmation.

2. gris.c
- Fonctionnalité : donne aux trois nombres représentant les couleurs d'un pixel la valeur moyenne des trois valeurs d'origine.
- Entrées : 
	Commande :gris fichier .ppm
- Sortie : image mise en gris + message de confirmation

3.taille.c
- Fonctionnalité : afficher la taille d une image entrée
- Entrée : 
	Commande :size fichier.ppm
- Sortie :taille en pixels de l’image en fonction la largeur et la hauteur

4. decoupage.c
-Fonctionnalité : Coupe une partie d’une image comprise entre une ligne et une autre, une colonne et une autre, toutes entrée par l’utilisateur.
- Spécificité :la limite de taille doit être respectée.
Entrée :
	Commande : cut fichier.ppm l1 l2 c1 c2 fichier_resultat.ppm
	L1 la ligne de début…l2 la ligne de fin
	c1 la colonne de début…c2 la colonne de fin
	fichier : le nom de l’image coupée
	fichier_résultat : le nom de l’image contenant la partie coupée

5.negatif.c
- Fonctionnalité :change chaque couleur par son complémentaire.
- Entrée : 
	Commande : neg fichier.ppm fichier_resultat.ppm
               fichier : le nom de l’image coupée
	fichier_résultat : nom de l’image filtrée en négatif
-sortie :image filtrée

6.filtre_median.c
- Fonctionnalité : remplace chacune des couleurs d'un pixel par la valeur médiane de de l'ensemble des couleurs de la même nature des pixels de son voisinage (8 voisins). 
- Entrée :  
Commande : fil fichier.ppm fichier_resultat.ppm

Sortie : image filtrée
7. img.ppm
   Nous avons pris le soin d’ajouter un fichier image afin de tester efficacement ce code . Il s’agit d’une image au format 500*500 question de la rendre clairement visible sur un écran, faite de plusieurs question de bien comprendre les modifications qui y sont faites
.Mais nous avons pu constater que l’image principale une fois modifiée demandait un travail retour pour revenir à son état initial….raison pour laquelle il sera ajouté un fichier « creation.c » histoire de l’exécuter pour ramener l’image à sa forme de base.
8.cration .c   : décris dans les lignes ci-dessus. L’utilisateur entre largeur et hauteur et l’image sera générée !!!   
8. ppmview.exe qui affichera ppmviewer> une fois ouvert et vous pourrez entrer vos fonctions
9.image_resultat.ppm : c est un fichier vide que vous pourrez créer pour vos résultats
10.image.c et image.h qui contiennent la déclaration de la structure d une image

----- Compilation
      1-Regroupez tous ces fichiers dans dossier
      2-entrer « « « gcc *.c –o ppmviewer.exe » » » 
      3-entrer « « « . /ppmviewer » » » pour lancer l exécutable
-----Organisation du travail de groupe
     Chaque membre fait un choix de tache et cré proprement la fonction et le reste de taches est naturellement repartis entre les premiers à terminer la leur.
Ensuite nous avons organiser un meeting au campus au bloc pédagogique histoire que chacun présente sa fonction et explique au autres qui pourront à leur tour critiquer…
On décide enfin de la structure à adopter et on communise les variables de chacun pour qu elle interagisse normalement. P
Puisque c est un travail de groupe nous ne pouvons concrètement citer « « QUI A FAIT QUOI » »

Info :POUR OUVRIR LE FICHIER IMGAGE Créé ou modifier, aller dans visual studio code ,télécharger les extensions ppm comme fait pour le c/c++ ,vérifier leur installation et une vois le fichier ppm ouvert ,faites un clic droit ,puis sur view ppm . un nouvel onglet s ouvre et affiche l’image
Aussi, nous vous recommandons de mettre des largeurs et hauteurs assez grandes pour visualiser correctement le travail….nous avons utilisé des boucles pour les niveaus de couleurs car entrée ces valeurs avec des tailles pareilles serait d une gymnastique lourde d’esprit !!!

Merci pour votre attention !!! Espérant une bonne appréciation de votre part, nous vous souhaitons une bonne journée !!!
