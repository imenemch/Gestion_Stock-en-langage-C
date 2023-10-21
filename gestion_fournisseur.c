#include "gestion_fournisseur.h"


void affiche_fournisseur(FOURNI frn)
{

//TO DO

}
void affiche_liste_fournisseurs(FOURNI* listeFourni, int nb)
{
//TO DO

}

FOURNI saisir_fournisseur()
{
//TO DO

}

ADR saisir_adresse()
{
//TO DO
}
void saisir_liste_fournisseurs(FOURNI* listeFourni,int nb)
{

//TO DO
}
void tri_liste_fournisseurs_code(int nb, FOURNI* listeFourni)
{
//TO DO

}
void tri_liste_fournisseurs_tel(int nb, FOURNI* listeFourni)
{

//TO DO

}
void inserer_un_fournisseur(int nb,FOURNI* listeFourni, FOURNI new_fourni)
{
//TO DO

}
int menu_fournisseur()
{
    int choix;
    do
    {
        printf("******* Menu 1 : Gestion des fournisseurs *********\n");
        printf("Introduire votre choix :\n");
        printf("-%d Saisie Liste Fournisseurs\n",SAISIE_LST_FOURNI);
        printf("-%d Chargement Fournisseurs from File\n",CHARGE_FOURNI_FICHIER_EXTER);
        printf("-%d Chargement Fournisseurs from DB\n",CHARG_FOURNI_DB);
        printf("-%d ***Menu gérer un fournisseur *** \n",MENU_GERER_FOUNISSEUR);

        //TO FINISH

        printf("-%d QUITTER\n",QUITTER);
        scanf("%d",&choix);
    }
    while(choix!=SAISIE_LST_FOURNI
            && choix !=CHARGE_FOURNI_FICHIER_EXTER
            && choix != CHARG_FOURNI_DB
            && choix != QUITTER
            && choix !=MENU_GERER_FOUNISSEUR
            /**TO FINICH*/
         );
    return choix;
}

int menu_gerer_un_fournisseur(int code_fournisseur){
/*
Plan du menu
Modifier un fournisseur
• Ajouter une liste de produit à un fournisse
• Ajouter un produit à la liste produit du fournisseur
• Mettre à jour le détail de produit d’un produit d’un fournisseur
• Supprimer un produit dans la liste de produit du fournisseur
• Afficher la liste de produit du fournisseur
• Revenir au menu 1
*/
 int choix;
    do
    {
        printf("******* Menu 2 : Gerere founisseur < %d >*********\n",code_fournisseur);
        printf("Introduire votre choix :\n");
        printf("-%d Modifier un fournisseur\n",MODIF_FOURNI);
        printf("-%d Ajouter produit à la liste du Fournisseur\n",AJOUT_PROD_FOURNI);

        //TO FINISH

        printf("-%d Rervenir au menu principal\n",REVENIR_MENU_PRINCPAL);
        scanf("%d",&choix);
    }
    while(choix!=MODIF_FOURNI
            && choix !=AJOUT_PROD_FOURNI
            && choix != REVENIR_MENU_PRINCPAL
            /**TO FINICH*/
         );
    return choix;
}

/**
Rechercher un produit dans le tableau des produit d'un fournisseur
et de retourner true s'il est retrouvé
et de retourner false s'il n'est pas retrouvé
*/
bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche)
{

//les variables
    int i;
    bool retrouve = false;
    for(i=0; retrouve == false && i<fournisseur.nbProd; i++)
    {
        if(strcmp(fournisseur.tabListProduit[i].designation,prod_recherche.designation) == 0
                &&
                strcmp(fournisseur.tabListProduit[i].nom, prod_recherche.nom) == 0
                &&
                fournisseur.tabListProduit[i].prix==prod_recherche.prix)
        {
            retrouve = true;
        }
    }
    return retrouve;
}
/**
Insérer un nouveau produit dans un founisseur
Le produit doit etre déja non existant dans le tableau des produits du fournisseurs
Cette fonction doit être appelée une fois la recherche du nouveau produit a retourné flase (0)
*/
FOURNI inserer_nouveau_produit_a_fournisseur(FOURNI fournisseur, PROD new_prod)
{


}
