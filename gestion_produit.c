
#include "gestion_produit.h"

/**fonction d'affichage de produit
*/
void affiche_produit(PROD prd)
{
    printf("%s|%s|%f\n",prd.nom, prd.designation, prd.prix);
}
/**
Fonction d'affichage d'une liste de produit de taille nb
Cette fonction affiche à partir d'un tableau de produit "listeProd"
Passé en argument de la fonction
le type de retour est vide (void)
*/
void affiche_liste_produit(PROD* listeProd, int nb)
{
    int i;
    for(i =0; i< nb; i++ )
    {
        affiche_produit(listeProd[i]);
    }
}
/** fonction de saisie de produit
   Elle saisie un produit temporaire et le retourne à la fin de la saisie
*/
PROD saisir_produit()
{
    PROD prdtmp;
    printf("Introduire le nom : ");
    scanf("%s",prdtmp.nom);
    prdtmp.nom[39] = '\0';
    fflush(stdin);
    printf("Introduire la designation : ");
    scanf("%s",prdtmp.designation);
    prdtmp.nom[59] = '\0';
    fflush(stdin);
    printf("Introduire le prix : ");
    scanf("%f",&prdtmp.prix);

    return prdtmp;
}
/**
Fonction de saisie d'une liste de produit de taille nb
*/

void saisir_liste_produit(int nb, PROD * listeProd)
{
    int i;
    for(i=0; i< nb; i++)
    {
        listeProd[i] = saisir_produit();
    }
}

/**fonction de tri de liste produit
Cette fonction demande à l'utilisateur le choix du type du tri
1 - tri par nom
2 - tri par prix
Elle prend en argument un nombre de produit ainsi que la liste de ces produits
Le tri s'effectue sur le tableau listeProduit
*/
void tri_liste_produit(int nb, PROD* listeProduit)
{
    PROD prdTmp;
    int positionMax;
    int i;
    int j;
    int choix;

    do
    {
        printf("Introduire votre choix : \n");
        printf("-%d tri par prix\n",TRI_PRIX);
        printf("-%d tri par nom\n",TRI_NOM);
        scanf("%d",&choix);
    }
    while(choix!=TRI_PRIX&& choix!=TRI_NOM);

// Traitement
    if(choix==TRI_PRIX)
    {
        for (i = 0; i < nb-1; i++)
        {
            for (j = i+1, positionMax = i; j < nb; j++)
            {
                // Check si la valeur max courante est plus petite que la prochaine valeur
                if (listeProduit[positionMax].prix < listeProduit[j].prix)
                {
                    positionMax = j;
                }
            }
            // Permutation des valeurs
            if(positionMax != i)
            {
                copieProd(listeProduit[i],&prdTmp);
                copieProd(listeProduit[positionMax],&listeProduit[i]);
                copieProd(prdTmp,&listeProduit[positionMax]);
            }
        }

    }
    else if(choix ==TRI_NOM)
    {
        for (i = 0; i < nb-1; i++)
        {
            for (j = i+1, positionMax = i; j < nb; j++)
            {
                // Check si le nom est > sur le plan ascii au nom de position max
                if (strcmp(listeProduit[positionMax].nom, listeProduit[j].nom)<0)
                {
                    positionMax = j;
                }
            }
            // Permutation des valeurs
            if(positionMax != i)
            {
                copieProd(listeProduit[i],&prdTmp);
                copieProd(listeProduit[positionMax],&listeProduit[i]);
                copieProd(prdTmp,&listeProduit[positionMax]);
            }
        }
    }

}
void copieProd(PROD prdSource, PROD*prDdestination)
{
    strcpy(prDdestination->designation, prdSource.designation);
    strcpy(prDdestination->nom, prdSource.nom);
    prDdestination->prix = prdSource.prix;
}

/**
Inserer un produit dans un tableau trié
Cette fonction insère un produit dans une liste de produit
Si le tableau est déjà remplis ou si le produit existe déjà
 ==> La fonction retourne 0
Sinon si l'insertion a été bien effectuée
 ==> la fonction retourne 1

*/
int inserer_un_produit(int nb,PROD* listeProduit, PROD new_prod)
{
//se référer à l'exercice N°2 de la serie N°4
//TO DO

}

/**rechercher un produit dans une liste de produit
//retourne l'index du produit dans le tableau listeProduit
//sinon -1*/
int rechercher_produit(int nb, PROD*listProduit, PROD prd_recheche )
{
    //se référer à l'exercice N°3 de la serie n°4
    //utiliser la rechercher sequentielle si votre tableau n'est pas trié
    //sinon la recherche diocothomique
//to DO

}

/**
Fonction de suppression de produit à partir d'un liste de produit
Retour 1 si le produit a été supprimé
Sinon la fonction retourne 0
*/
int supprimer_produit(int nb, PROD*listProduit, PROD prd_a_supprimer )
{
//se réferer à l'exercice n°2 de la serie N°3   /**Eliminer les 0*/
//to do
}

/**
Fonction de modification de produit à partir d'un liste de produit
Retour 1 si le produit a été modifié
Sinon la fonction retourne 0
*/
int modifier_produit(int nb, int index_prod_to_modif, PROD*listProduit, PROD prd_modifie)
{

}

/**
Fonction d'enregistrement d'une liste de produit dans un fichier
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
*/
void save_tabproduit_in_file(int nb, PROD*listProduit,char*nom_file)
{
    FILE* fp_write = NULL;
    int i;
    fp_write= fopen(nom_file,"w"); /**r:read ; w: write ; a : append ; r+ : lecture et écriture*/

    if(!fp_write)
    {
        printf("Erreur de l'ouverture du fichier");
    }
    //traitement
    //CHANEL|Sac|6000
    //DELL|Ordinateur|1200
    for(i=0; i<nb; i++)
    {
        fprintf(fp_write,"%s|%s|%f\n",listProduit[i].nom, listProduit[i].designation, listProduit[i].prix);
    }
    fclose(fp_write);

}
/**
Fonction de chargement d'une liste de produit à partir d'un fichier externe
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
Cette fonction retourne :
- le nombre de ligne du fichier => le nombre de produit
- à ==> si le fichier est vide
*/
int load_tabproduit_from_file(PROD*listProduit,char*nom_file)
{
    FILE* fp_read = NULL;
    int i;
    char ligne[100];
    fp_read= fopen(nom_file,"r"); /**r:read ; w: write ; a : append ; r+ : lecture et écriture*/

    if(!fp_read)
    {
        printf("Erreur de l'ouverture du fichier");
    }
    i = 0;
    while(fgets(ligne,200,fp_read))
    {
        sscanf(ligne,"%s|%s|%f\n",listProduit[i].nom,listProduit[i].designation,&listProduit[i].prix);
        i++;
    }

    fclose(fp_read);
    return i;
}

