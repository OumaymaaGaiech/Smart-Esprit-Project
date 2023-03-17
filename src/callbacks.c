#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "stock.h"



void
on_button_acceuil_ajouter_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_oumayma, *Ajouter_oumayma;
Acceuil_oumayma=lookup_widget(objet,"Acceuil_oumayma");
gtk_widget_destroy(Acceuil_oumayma);
Ajouter_oumayma=create_Ajouter_oumayma();
gtk_widget_show(Ajouter_oumayma);
}


void
on_button_acceuil_modifier_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_oumayma, *Modifier_oumayma;
Acceuil_oumayma=lookup_widget(objet,"Acceuil_oumayma");
gtk_widget_destroy(Acceuil_oumayma);
Modifier_oumayma=create_Modifier_oumayma();
gtk_widget_show(Modifier_oumayma);
}


void
on_button_acceuil_chercher_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_oumayma, *Chercher_oumayma;
Acceuil_oumayma=lookup_widget(objet,"Acceuil_oumayma");
gtk_widget_destroy(Acceuil_oumayma);
Chercher_oumayma=create_Chercher_oumayma();
gtk_widget_show(Chercher_oumayma);
}


void
on_button_acceuil_afficher_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_oumayma, *Afficher_oumayma;
Acceuil_oumayma=lookup_widget(objet,"Acceuil_oumayma");
gtk_widget_destroy(Acceuil_oumayma);
Afficher_oumayma=create_Afficher_oumayma();
gtk_widget_show(Afficher_oumayma);
}


void
on_radiobutton_ajouter_basse_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_ajouter_ambiante_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}





void
on_button_ajouter_ajouter_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{

GtkWidget *entry_ajouter_ref, *entry_ajouter_nom, *spinbutton_ajouter, *entry_ajouter_prix, *combobox_ajouter, *radiobutton_ajouter_basse, *radiobutton_ajouter_ambiante, *checkbutton_ajouter, *pInfo;
GtkCalendar *calendar_ajouter;
produit u;
guint day, month, year;
entry_ajouter_ref=lookup_widget(objet,"entry_ajouter_ref");
entry_ajouter_nom=lookup_widget(objet,"entry_ajouter_nom");
spinbutton_ajouter=lookup_widget(objet,"spinbutton_ajouter");
entry_ajouter_prix=lookup_widget(objet,"entry_ajouter_prix");
combobox_ajouter=lookup_widget(objet,"combobox_ajouter");
radiobutton_ajouter_basse=lookup_widget(objet,"radiobutton_ajouter_basse");
radiobutton_ajouter_ambiante=lookup_widget(objet,"radiobutton_ajouter_ambiante");
calendar_ajouter=lookup_widget(objet,"calendar_ajouter");
checkbutton_ajouter=lookup_widget(objet,"checkbutton_ajouter");
strcpy(u.ref,gtk_entry_get_text(GTK_ENTRY(entry_ajouter_ref)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_ajouter_nom)));
u.quantite = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_ajouter));;
u.prix=atof(gtk_entry_get_text(GTK_ENTRY(entry_ajouter_prix)));
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajouter)));
u.temp=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_ajouter_basse))?0:1;
gtk_calendar_get_date(GTK_CALENDAR(calendar_ajouter),&year,&month,&day);
u.d.j=day;
u.d.m=month+1;
u.d.a=year;
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON(checkbutton_ajouter)))
ajouter(u,"stock.txt");
else
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation requise");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}



void
on_button_retour_ajouter_clicked       (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_oumayma, *Ajouter_oumayma;
Ajouter_oumayma=lookup_widget(objet,"Ajouter_oumayma");
gtk_widget_destroy(Ajouter_oumayma);
Acceuil_oumayma=create_Acceuil_oumayma();
gtk_widget_show(Acceuil_oumayma);
}


void
on_button_voir_ajout_clicked           (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Afficher_oumayma, *Ajouter_oumayma;
Ajouter_oumayma=lookup_widget(objet,"Ajouter_oumayma");
gtk_widget_destroy(Ajouter_oumayma);
Afficher_oumayma=create_Afficher_oumayma();
gtk_widget_show(Afficher_oumayma);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_retour_afficher_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Afficher_oumayma, *Acceuil_oumayma;
Afficher_oumayma=lookup_widget(objet,"Afficher_oumayma");
gtk_widget_destroy(Afficher_oumayma);
Acceuil_oumayma=create_Acceuil_oumayma();
gtk_widget_show(Acceuil_oumayma);
}


void
     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1, *Afficher_oumayma;
Afficher_oumayma=lookup_widget(objet,"Afficher_oumayma");
gtk_widget_destroy(Afficher_oumayma);
Afficher_oumayma=lookup_widget(objet,"Afficher_oumayma");
Afficher_oumayma=create_Afficher_oumayma();
gtk_widget_show(Afficher_oumayma);
treeview1=lookup_widget(Afficher_oumayma,"treeview1");
afficher(treeview1,"stock.txt");
}


void
on_button_rupture_clicked              (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *b, *pInfo;
char str[1000], ch[1000]="";
strcpy(ch,stock("stock.txt"));
sprintf(str,"%s",ch);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button_modifier_consulter_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *entry_modifier_ref, *entry_modifier_nom, *spinbutton_modifier, *entry_modifier_prix, *radiobutton_modifier_basse, *radiobutton_modifier_ambiante, *pInfo;
GtkCalendar *calendar_modifier;
produit p;
guint day, month, year;
int a=0;
char ch1[20], ch2[20], ref[20];
FILE *f;
entry_modifier_ref=lookup_widget(objet,"entry_modifier_ref");
entry_modifier_nom=lookup_widget(objet,"entry_modifier_nom");
spinbutton_modifier=lookup_widget(objet,"spinbutton_modifier");
entry_modifier_prix=lookup_widget(objet,"entry_modifier_prix");
radiobutton_modifier_basse=lookup_widget(objet,"radiobutton_modifier_basse");
radiobutton_modifier_ambiante=lookup_widget(objet,"radiobutton_modifier_ambiante");
calendar_modifier=lookup_widget(objet,"calendar_modifier");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(entry_modifier_ref)));
f = fopen("stock.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s %f %f %s %d %d %d %d\n",p.ref,p.nom,&(p.quantite),&(p.prix),p.type,&(p.temp),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.ref,ref)==0){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(entry_modifier_nom),p.nom);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_modifier),p.quantite);
sprintf(ch2,"%.2f",p.prix);
gtk_entry_set_text(GTK_ENTRY(entry_modifier_prix),ch2);
p.temp==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_modifier_basse),TRUE):gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton_modifier_ambiante),TRUE);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Produit introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}



void
on_radiobutton_modifier_basse_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_modifier_ambiante_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_voir_modif_clicked           (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Afficher_oumayma, *Modifier_oumayma;
Modifier_oumayma=lookup_widget(objet,"Modifier_oumayma");
gtk_widget_destroy(Modifier_oumayma);
Afficher_oumayma=create_Afficher_oumayma();
gtk_widget_show(Afficher_oumayma);
}


void
on_button_modifier_modifier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_modifier_ref, *entry_modifier_nom, *spinbutton_modifier, *entry_modifier_prix, *radiobutton_modifier_basse, *radiobutton_modifier_ambiante, *pInfo;
GtkCalendar *calendar_modifier;
produit u;
guint day, month, year;
entry_modifier_ref=lookup_widget(objet,"entry_modifier_ref");
entry_modifier_nom=lookup_widget(objet,"entry_modifier_nom");
spinbutton_modifier=lookup_widget(objet,"spinbutton_modifier");
entry_modifier_prix=lookup_widget(objet,"entry_modifier_prix");
radiobutton_modifier_basse=lookup_widget(objet,"radiobutton_modifier_basse");
radiobutton_modifier_ambiante=lookup_widget(objet,"radiobutton_modifier_ambiante");
calendar_modifier=lookup_widget(objet,"calendar_modifier");
strcpy(u.ref,gtk_entry_get_text(GTK_ENTRY(entry_modifier_ref)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_modifier_nom)));
u.quantite = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_modifier));;
u.prix = atof(gtk_entry_get_text(GTK_ENTRY(entry_modifier_prix)));
u.temp=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_modifier_basse))?0:1;
gtk_calendar_get_date(GTK_CALENDAR(calendar_modifier),&year,&month,&day);
u.d.j=day;
u.d.m=month+1;
u.d.a=year;
modifier(u,"stock.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Produit modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button_retour_modifier_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Modifier_oumayma, *Acceuil_oumayma;
Modifier_oumayma=lookup_widget(objet,"Modifier_oumayma");
gtk_widget_destroy(Modifier_oumayma);
Acceuil_oumayma=create_Acceuil_oumayma();
gtk_widget_show(Acceuil_oumayma);
}


void
on_button_chercher_chercher_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_chercher_ref, *chercher_nom, *chercher_type, *chercher_quantite, *chercher_prix, *chercher_date, *chercher_temperature, *pInfo;
char date[20], qte[10], prix[10], ref[20];
entry_chercher_ref=lookup_widget(objet,"entry_chercher_ref");
chercher_nom=lookup_widget(objet,"chercher_nom");
chercher_type=lookup_widget(objet,"chercher_type");
chercher_quantite=lookup_widget(objet,"chercher_quantite");
chercher_prix=lookup_widget(objet,"chercher_prix");
chercher_date=lookup_widget(objet,"chercher_date");
chercher_temperature=lookup_widget(objet,"chercher_temperature");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(entry_chercher_ref)));
produit p = chercher(ref,"stock.txt");
if (strcmp(p.ref,"")==0){
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ID introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
else{
gtk_label_set_text(GTK_LABEL(chercher_nom),p.nom);
sprintf(qte,"%.2f",p.quantite);
gtk_label_set_text(GTK_LABEL(chercher_quantite),qte);
sprintf(date,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_label_set_text(GTK_LABEL(chercher_date),date);
sprintf(prix,"%.2f",p.prix);
gtk_label_set_text(GTK_LABEL(chercher_prix),prix);
gtk_label_set_text(GTK_LABEL(chercher_type),p.type);
gtk_label_set_text(GTK_LABEL(chercher_temperature),p.temp==0?"Basse":"Ambiante");
}
}



void
on_button_retour_chercher_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Chercher_oumayma, *Acceuil_oumayma;
Chercher_oumayma=lookup_widget(objet,"Chercher_oumayma");
gtk_widget_destroy(Chercher_oumayma);
Acceuil_oumayma=create_Acceuil_oumayma();
gtk_widget_show(Acceuil_oumayma);
}


void
on_button_supprimer_supprimer_clicked  (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_supprimer_ref;
produit u;
entry_supprimer_ref=lookup_widget(objet,"entry_supprimer_ref");
strcpy(u.ref,gtk_entry_get_text(GTK_ENTRY(entry_supprimer_ref)));
supprimer(u,"stock.txt");
}


void
on_button_voir_supprimer_clicked       (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_oumayma, *Afficher_oumayma;
Supprimer_oumayma=lookup_widget(objet,"Supprimer_oumayma");
gtk_widget_destroy(Supprimer_oumayma);
Afficher_oumayma=create_Afficher_oumayma();
gtk_widget_show(Afficher_oumayma);
}


void
on_button_retour_supprimer_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_oumayma, *Acceuil_oumayma;
Supprimer_oumayma=lookup_widget(objet,"Supprimer_oumayma");
gtk_widget_destroy(Supprimer_oumayma);
Acceuil_oumayma=create_Acceuil_oumayma();
gtk_widget_show(Acceuil_oumayma);
}


void
on_button_acceuil_supprimer_clicked    (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_oumayma, *Supprimer_oumayma;
Acceuil_oumayma=lookup_widget(objet,"Acceuil_oumayma");
gtk_widget_destroy(Acceuil_oumayma);
Supprimer_oumayma=create_Supprimer_oumayma();
gtk_widget_show(Supprimer_oumayma);
}

