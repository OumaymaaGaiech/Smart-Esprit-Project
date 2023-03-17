#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct date
{
    int j;
    int m;
    int a;
    
}date;


typedef struct produit
{
    char ref[20];
    char nom[20];
    float quantite;
    float prix;
    char type[20];
    int temp;
    date d;
    
}produit;

void ajouter(produit u, char *fname);
void supprimer(produit u, char *fname);
void modifier(produit u, char *fname);
void afficher(GtkWidget *liste, char *fname);
produit chercher(char *ref, char *fname);
char* stock(char *fname);
