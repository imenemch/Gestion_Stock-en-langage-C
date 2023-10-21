#include "gestion_produit.h"
#include "gestion_fournisseur.h"

int main()
{
    //déclaration des variables
    PROD listeProd[MAX_SIZE_TAB_PRODUIT];
    FOURNI listeFournisseur[MAX_SIZE_TAB_FOURNI];
    int nb;
    int choix;
    int code_founisseur;
    do
    {
        choix = menu_fournisseur();
        switch(choix)
        {
        case(SAISIE_LST_FOURNI):
            saisir_liste_fournisseurs(listeFournisseur,nb);
            break;
        case(CHARGE_FOURNI_FICHIER_EXTER):
            break;
        case(CHARG_FOURNI_DB):
            break;
        case(MENU_GERER_FOUNISSEUR):
            printf("Inroduire le code du founisseur à gérer : ");
            scanf("%d",&code_founisseur);
            do
            {
                choix = menu_gerer_un_fournisseur(code_founisseur);
                switch(choix)
                {
                case(MODIF_FOURNI):
                    break;
                case (AJOUT_PROD_FOURNI):
                    break;
                case(REVENIR_MENU_PRINCPAL) :
                    printf("Retour au menu principal\n");
                    break;
                default:
                    break;
                }
            }
            while(choix!=REVENIR_MENU_PRINCPAL);
            break;
        case(QUITTER):
            printf("Au revoir \n");
            break;
        default :
            break;
        }
    }
    while(choix != QUITTER);
    /*    do
        {
            printf("Introduire nb : ");
            scanf("%d",&nb);
        }
        while(nb<=0||nb>MAX_SIZE_TAB_PRODUIT);

        //sasiie des données
        saisir_liste_produit(nb,listeProd);

        //affichage
        printf("\nAffichage liste Produits Test :\n");
        affiche_liste_produit(listeProd,nb);

        tri_liste_produit(nb,listeProd);
        //affichage
        printf("\nAffichage liste Produits Apres tri :\n");
        affiche_liste_produit(listeProd,nb);
    */
    return 0;
}
