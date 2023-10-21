#ifndef GESTION_PRODUIT_H_INCLUDED
#define GESTION_PRODUIT_H_INCLUDED

#include <stdio.h>

#define MAX_SIZE_TAB_PRODUIT 100
#define TRI_PRIX 1
#define TRI_NOM 2


struct Produit{
    char nom[40];
    char designation[60];
    float prix;
};typedef struct Produit PROD;


//Mettre les différentes fonctions de gestion produit

void affiche_produit(PROD prd); //fonction d'affichage de produit
void affiche_liste_produit(PROD* listeProd, int nb); //fonction d'affichage de produit
PROD saisir_produit(); // fonction de saisie de produit
void saisir_liste_produit(int nb, PROD * listeProd); //fonction saisie de liste produit
void tri_liste_produit(int nb, PROD* listeProduit);
int inserer_un_produit(int nb,PROD* listeProduit, PROD new_prod);
int rechercher_produit(int nb, PROD*listProduit, PROD prd_recheche );//rechercher un produit dans une liste de produit
int supprimer_produit(int nb, PROD*listProduit, PROD prd_recheche );
void copieProd(PROD prdSource, PROD*prDdestination);
void save_tabproduit_in_file(int nb, PROD*listProduit,char*nomfile);
int load_tabproduit_from_file(PROD*listProduit,char*nomfile);

#endif // GESTION_PRODUIT_H_INCLUDED
