#ifndef GESTION_FOURNISSEUR_H_INCLUDED
#define GESTION_FOURNISSEUR_H_INCLUDED

#define MAX_SIZE_TAB_PROD_FOURNI 10
#define MAX_SIZE_TAB_FOURNI 100
#include "gestion_produit.h"

#define SAISIE_LST_FOURNI 5
#define CHARGE_FOURNI_FICHIER_EXTER 6
#define CHARG_FOURNI_DB 7
//to finich menu_1

#define MENU_GERER_FOUNISSEUR 10
#define MODIF_FOURNI 15
#define AJOUT_PROD_FOURNI 16


#define REVENIR_MENU_PRINCPAL 20
//#define TO FINISH 8
#define QUITTER 21


struct Adresse
{
    int numero;
    char nomRue[30];
    char nomVille[30];
    int codePostal;
    char pays[30];
};
typedef struct Adresse ADR;
struct Date
{
    int jour;
    int mois;
    int annee;
};
typedef struct Date DATE;

struct Detail_Produit
{
    int code;
    float prix;
    float qteStock;
    DATE dateLimite;
};
typedef struct Detail_Produit DETPROD;


struct Fournisseur
{
    int code;
    ADR adresse;
    long tel;
    PROD tabListProduit[MAX_SIZE_TAB_PROD_FOURNI];
    DETPROD tabListDetailProd[MAX_SIZE_TAB_PROD_FOURNI];
    int nbProd;
};
typedef struct Fournisseur FOURNI;


void affiche_fournisseur(FOURNI frn); //fonction d'affichage de fournisseur
void affiche_liste_fournisseurs(FOURNI* listeFourni, int nb); //fonction d'affichage de fournisseur
FOURNI saisir_fournisseur(); // fonction de saisie de founisseur
ADR saisir_adresse(); // fonction de saisie d'adresse
void saisir_liste_fournisseurs(FOURNI* listeFourni,int nb); //fonction saisie de liste fournisseur
void tri_liste_fournisseurs_code(int nb, FOURNI* listeFourni);
void tri_liste_fournisseurs_tel(int nb, FOURNI* listeFourni);
void inserer_un_fournisseur(int nb,FOURNI* listeFourni, FOURNI new_fourni);
int menu_fournisseur();
int menu_gerer_un_fournisseur();

bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche);
FOURNI inserer_nouveau_produit_a_fournisseur(FOURNI fournisseur, PROD new_prod);



#endif // GESTION_FOURNISSEUR_H_INCLUDED
