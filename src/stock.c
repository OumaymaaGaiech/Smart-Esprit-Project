#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stock.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	REF,
	NOM,
	QUANTITE,
	PRIX,
        TYPE,
	TEMP,
        DATE,
	COLUMNS
};


void ajouter(produit u, char *fname){
GtkWidget *pQuestion, *pInfo;
FILE *f;
int b=0;
gpointer user_data;
produit p;
f=fopen(fname,"a+");
if(f!=NULL)
{	while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{	
		if(strcmp(u.ref,p.ref)==0)
		b++;
	}
	if(b==0){
	fprintf(f,"%s %s %.2f %.2f %s %d %d %d %d\n",u.ref,u.nom,u.quantite,u.prix,u.type,u.temp,u.d.j,u.d.m,u.d.a);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Produit ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"ID doit etre unique !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

void modifier(produit u, char *fname){
produit p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.ref,u.ref)!=0)
			fprintf(g,"%s %s %.2f %.2f %s %d %d %d %d\n",p.ref,p.nom,p.quantite,p.prix,p.type,p.temp,p.d.j,p.d.m,p.d.a);
		else
			fprintf(g,"%s %s %.2f %.2f %s %d %d %d %d\n",p.ref,u.nom,u.quantite,u.prix,p.type,u.temp,u.d.j,u.d.m,u.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Produit modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficher(GtkWidget *liste, char *fname)
{
produit p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar qte[10], prix[10], temp[10], date[15];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Référence", renderer,"text",REF, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Nom", renderer,"text",NOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Quantité", renderer,"text",QUANTITE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Prix", renderer,"text",PRIX, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Conservation", renderer,"text",TEMP, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date", renderer,"text",DATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
sprintf(temp,p.temp==0?"Basse":"Ambiante");
sprintf(qte,"%.2f",p.quantite);
sprintf(prix,"%.2f",p.prix);
sprintf(date,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,REF,p.ref,NOM,p.nom,QUANTITE,qte,PRIX,prix,TYPE,p.type,TEMP,temp,DATE,date,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

void supprimer(produit u, char *fname)
{
produit p;
int a=0;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.ref,u.ref)!=0)
			fprintf(g,"%s %s %.2f %.2f %s %d %d %d %d\n",p.ref,p.nom,p.quantite,p.prix,p.type,p.temp,p.d.j,p.d.m,p.d.a);
		else
			a=1;
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,a==1?"Produit supprimé avec succès":"Produit introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

char* stock(char *fname){
produit p;
char* ch = (char*) malloc(1000);
strcpy(ch,"");
char str[1000];
FILE *f = fopen(fname,"r");
if(f!=NULL){
while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF){
if(p.quantite==0){
sprintf(str,"%s\n",p.nom);
strcat(ch,str);
}
else
continue;
}
fclose(f);
}
return ch;
}

produit chercher(char *ref, char *fname){
produit p, e;
FILE *f;
f=fopen(fname,"r");
if(f!=NULL){
	while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.ref,ref)==0)
			return p;
	}
	fclose(f);
}
strcpy(e.ref,"");
return e;
}
