 #include <gtk/gtk.h>


void
on_button_acceuil_ajouter_clicked      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_acceuil_modifier_clicked     (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_acceuil_chercher_clicked     (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_acceuil_afficher_clicked     (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_radiobutton_ajouter_basse_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ajouter_ambiante_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_button_ajouter_ajouter_clicked      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_ajouter_clicked       (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_voir_ajout_clicked           (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_retour_afficher_clicked      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_afficher_afficher_clicked    (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_rupture_clicked              (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_modifier_consulter_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_modifier_basse_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modifier_ambiante_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_voir_modif_clicked           (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_modifier_modifier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_modifier_clicked      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_chercher_chercher_clicked    (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_chercher_clicked      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_supprimer_supprimer_clicked  (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_voir_supprimer_clicked       (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_supprimer_clicked     (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_acceuil_supprimer_clicked    (GtkWidget        *objet,
                                        gpointer         user_data);
