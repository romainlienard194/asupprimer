#pragma once


#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define TAILLE_BLOC         34 // Taille d'un bloc en pixels
#define NB_BLOCS_LARGEUR    12 // Nombres de 
#define NB_BLOCS_HAUTEUR    12 // blocs
#define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR // Taille de
#define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR // l'écran

enum { HAUT, BAS, GAUCHE, DROITE };
enum { VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK };

#endif#pragma once
