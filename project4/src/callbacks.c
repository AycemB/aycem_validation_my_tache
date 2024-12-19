#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include <string.h>
#include <gtk/gtk.h>
#include "aycem.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
int camion = 0;
int moto = 0;
int voiture = 0;
int acces = 0;
parking p1;
parking p;

void
on_treeviewparking_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

    GtkTreeIter iter;
    gchar *nom;
    gchar *adresse;
    gchar *id;
    gchar *etat;
    gchar *capacite;
    gchar *bloc;
    gchar *tarif;
    gchar *abonnement;
    gchar *vehicule;
    gchar *acces;
    gint *jd;
    gint *md;
    gint *ad;
    gint *jf;
    gint *mf;
    gint *af;


   parking p;

    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        gtk_tree_model_get(GTK_TREE_MODEL(model), &iter, 0, &nom, 1, &adresse, 2, &id, 3, &etat, 4, &capacite, 5, &bloc, 6, &tarif, 7, &abonnement,8,&vehicule,  9, &acces, 10, &jd,11, &md, 12, &ad,13, &jf, 14, &mf, 15, &af, -1);

        strcpy(p.nom, nom);
        strcpy(p.adresse, adresse);

        strcpy(p.id,id);
        strcpy(p.etat, etat);
        strcpy(p.capacite,capacite);
        strcpy(p.bloc,bloc);
        strcpy(p.tarif,tarif);
strcpy(p.abonnement,abonnement);
        strcpy(p.vehicule,vehicule);
        strcpy(p.acces,acces);
        jd=p.jd;
        md=p.md;
        ad=p.ad;
        jf=p.jf;
        mf=p.mf;
        af=p.af;
        p1=p;
    }
}


void
on_ajotaff_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_Chercher_Parking_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{ parking p;
    char text[100];
    GtkWidget *treeviewparking;
    GtkWidget *input;

 
    input = lookup_widget(button, "trouverparkingp");
    strcpy(text, gtk_entry_get_text(GTK_ENTRY(input)));

 
    if (strlen(text) == 0) {
        printf("Erreur : Aucun texte saisi pour la recherche.\n");
        return;
    }

 
    treeviewparking = lookup_widget(button, "treeviewparking");
    chercher_Parking(p, text);

 
    afficher_Parking(treeviewparking, "rechparking.txt");
}



void
on_actualiseraff_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewparking;
    treeviewparking = lookup_widget(button, "treeviewparking");

 
    afficher_Parking(treeviewparking, "parking.txt");
}


void
on_affecteraff_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
/*gtk_entry_set_text(GTK_ENTRY(lookup_widget(button, "idpagentry20")), p.id);*/
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_suppaff_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
/*gtk_entry_set_text(GTK_ENTRY(lookup_widget(button, "idsuppentry12")), p1.id);*/
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_modifaff_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
/*gtk_entry_set_text(GTK_ENTRY(lookup_widget(button, "entry4")), p1.id);*/
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        camion = 2;
    }
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        moto = 3;
    }
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{parking p;
if (gtk_toggle_button_get_active(togglebutton)) {
        strcpy(p.acces, "oui");
    }
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton)) {
        voiture = 1;
    }
}


void
on_annulerajoutp_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nompentry2, *adrpentry3, *entry4, *capacitepaentry5, *tarifpaentry6;
    GtkWidget *etatpcomboboxentry1, *blocpacomboboxentry2, *abonpacomboboxentry3;
    GtkWidget *spin1, *spin2, *spin3, *spin4, *spin5, *spin6;


    nompentry2 = lookup_widget(GTK_WIDGET(button), "nompentry2");
    adrpentry3 = lookup_widget(GTK_WIDGET(button), "adrpentry3");
    entry4 = lookup_widget(GTK_WIDGET(button), "entry4");
    capacitepaentry5 = lookup_widget(GTK_WIDGET(button), "capacitepaentry5");
    tarifpaentry6 = lookup_widget(GTK_WIDGET(button), "tarifpaentry6");

    spin1 = lookup_widget(GTK_WIDGET(button), "spin1");
    spin2 = lookup_widget(GTK_WIDGET(button), "spin2");
    spin3 = lookup_widget(GTK_WIDGET(button), "spin3");
    spin4 = lookup_widget(GTK_WIDGET(button), "spin4");
    spin5 = lookup_widget(GTK_WIDGET(button), "spin5");
    spin6 = lookup_widget(GTK_WIDGET(button), "spin6");

    etatpcomboboxentry1 = lookup_widget(GTK_WIDGET(button), "etatpcomboboxentry1");
    blocpacomboboxentry2 = lookup_widget(GTK_WIDGET(button), "blocpacomboboxentry2");
    abonpacomboboxentry3 = lookup_widget(GTK_WIDGET(button), "abonpacomboboxentry3");


    gtk_entry_set_text(GTK_ENTRY(nompentry2), "");
    gtk_entry_set_text(GTK_ENTRY(adrpentry3), "");
    gtk_entry_set_text(GTK_ENTRY(entry4), "");
    gtk_entry_set_text(GTK_ENTRY(capacitepaentry5), "");
    gtk_entry_set_text(GTK_ENTRY(tarifpaentry6), "");

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin1), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin2), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin3), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin4), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin5), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6), 0);

    gtk_combo_box_set_active(GTK_COMBO_BOX(etatpcomboboxentry1), -1);
    gtk_combo_box_set_active(GTK_COMBO_BOX(blocpacomboboxentry2), -1);
    gtk_combo_box_set_active(GTK_COMBO_BOX(abonpacomboboxentry3), -1);

    g_print("Ajout annulé et formulaire réinitialisé.\n");
}


void
on_ajouterp_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  parking p;
    GtkWidget *nompentry2, *adrpentry3, *entry4, *capacitepaentry5, *tarifpaentry6;
    GtkWidget *etatpcomboboxentry1, *blocpacomboboxentry2, *abonpacomboboxentry3;
    GtkWidget *spin1, *spin2, *spin3, *spin4, *spin5, *spin6;
    GtkWidget *radiobutton1, *radiobutton2, *radiobutton3;
    GtkWidget *checkbutton1;

 
    nompentry2 = lookup_widget(GTK_WIDGET(button), "nompentry2");
    adrpentry3 = lookup_widget(GTK_WIDGET(button), "adrpentry3");
    entry4 = lookup_widget(GTK_WIDGET(button), "entry4");
    capacitepaentry5 = lookup_widget(GTK_WIDGET(button), "capacitepaentry5");
    tarifpaentry6 = lookup_widget(GTK_WIDGET(button), "tarifpaentry6");

    spin1 = lookup_widget(GTK_WIDGET(button), "spin1");
    spin2 = lookup_widget(GTK_WIDGET(button), "spin2");
    spin3 = lookup_widget(GTK_WIDGET(button), "spin3");
    spin4 = lookup_widget(GTK_WIDGET(button), "spin4");
    spin5 = lookup_widget(GTK_WIDGET(button), "spin5");
    spin6 = lookup_widget(GTK_WIDGET(button), "spin6");

    etatpcomboboxentry1 = lookup_widget(GTK_WIDGET(button), "etatpcomboboxentry1");
    blocpacomboboxentry2 = lookup_widget(GTK_WIDGET(button), "blocpacomboboxentry2");
    abonpacomboboxentry3 = lookup_widget(GTK_WIDGET(button), "abonpacomboboxentry3");

    radiobutton1 = lookup_widget(GTK_WIDGET(button), "radiobutton1");
    radiobutton2 = lookup_widget(GTK_WIDGET(button), "radiobutton2");
    radiobutton3 = lookup_widget(GTK_WIDGET(button), "radiobutton3");

    checkbutton1 = lookup_widget(GTK_WIDGET(button), "checkbutton1");

 
    if (strlen(gtk_entry_get_text(GTK_ENTRY(nompentry2))) == 0 ||
        strlen(gtk_entry_get_text(GTK_ENTRY(adrpentry3))) == 0 ||
        strlen(gtk_entry_get_text(GTK_ENTRY(entry4))) == 0 ||
        strlen(gtk_entry_get_text(GTK_ENTRY(capacitepaentry5))) == 0 ||
        strlen(gtk_entry_get_text(GTK_ENTRY(tarifpaentry6))) == 0 ||
        gtk_combo_box_get_active(GTK_COMBO_BOX(etatpcomboboxentry1)) == -1 ||
        gtk_combo_box_get_active(GTK_COMBO_BOX(blocpacomboboxentry2)) == -1 ||
        gtk_combo_box_get_active(GTK_COMBO_BOX(abonpacomboboxentry3)) == -1) {
       
 
        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                         GTK_DIALOG_MODAL,
                                                         GTK_MESSAGE_ERROR,
                                                         GTK_BUTTONS_OK,
                                                         "Veuillez remplir tous les champs !");
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
        return; 
    }

 
    strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nompentry2)));
    strcpy(p.adresse, gtk_entry_get_text(GTK_ENTRY(adrpentry3)));
    strcpy(p.id, gtk_entry_get_text(GTK_ENTRY(entry4)));
    strcpy(p.capacite, gtk_entry_get_text(GTK_ENTRY(capacitepaentry5)));
    strcpy(p.tarif, gtk_entry_get_text(GTK_ENTRY(tarifpaentry6)));

    strcpy(p.etat, gtk_combo_box_get_active_text(GTK_COMBO_BOX(etatpcomboboxentry1)));
    strcpy(p.bloc, gtk_combo_box_get_active_text(GTK_COMBO_BOX(blocpacomboboxentry2)));
    strcpy(p.abonnement, gtk_combo_box_get_active_text(GTK_COMBO_BOX(abonpacomboboxentry3)));

    p.jd = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
    p.md = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
    p.ad = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3));
    p.jf = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin4));
    p.mf = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin5));
    p.af = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin6));

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))) {
        strcpy(p.vehicule, "voiture");
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))) {
        strcpy(p.vehicule, "camion");
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))) {
        strcpy(p.vehicule, "moto");
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbutton1))) {
        strcpy(p.acces, "oui");
    } else {
        strcpy(p.acces, "non");
    }

 
    if (ajouter("parking.txt", p)) {
        GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          "Parking ajouté avec succès !");
        gtk_dialog_run(GTK_DIALOG(success_dialog));
        gtk_widget_destroy(success_dialog);
    } else {
        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                        GTK_DIALOG_MODAL,
                                                        GTK_MESSAGE_ERROR,
                                                        GTK_BUTTONS_OK,
                                                        "Erreur lors de l'ajout du parking !");
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
    }
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        voiture = 1;
    }
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        camion = 2;
    }
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
        moto = 3;
    }
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
parking p;
 if (gtk_toggle_button_get_active(togglebutton)) {
        strcpy(p.acces, "oui");
    }
}


void
on_modifiermp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    parking p;
    GtkWidget *nompdentry7, *adressempentry8, *idmpdentry9, *capacitempdentry10, *tarifmpdentry11;
    GtkWidget *etatmpdcomboboxentry4, *blocmpdcomboboxentry5, *abonmpdcomboboxentry6;
    GtkWidget *spin7, *spin8, *spin9, *spin10, *spin11, *spin12;
    GtkWidget *radiobutton4, *radiobutton5, *radiobutton6, *checkbutton2;

 
    nompdentry7 = lookup_widget(GTK_WIDGET(button), "nompdentry7");
    adressempentry8 = lookup_widget(GTK_WIDGET(button), "adressempentry8");
    idmpdentry9 = lookup_widget(GTK_WIDGET(button), "idmpdentry9");
    capacitempdentry10 = lookup_widget(GTK_WIDGET(button), "capacitempdentry10");
    tarifmpdentry11 = lookup_widget(GTK_WIDGET(button), "tarifmpdentry11");

    spin7 = lookup_widget(GTK_WIDGET(button), "spin7");
    spin8 = lookup_widget(GTK_WIDGET(button), "spin8");
    spin9 = lookup_widget(GTK_WIDGET(button), "spin9");
    spin10 = lookup_widget(GTK_WIDGET(button), "spin10");
    spin11 = lookup_widget(GTK_WIDGET(button), "spin11");
    spin12 = lookup_widget(GTK_WIDGET(button), "spin12");

    etatmpdcomboboxentry4 = lookup_widget(GTK_WIDGET(button), "etatmpdcomboboxentry4");
    blocmpdcomboboxentry5 = lookup_widget(GTK_WIDGET(button), "blocmpdcomboboxentry5");
    abonmpdcomboboxentry6 = lookup_widget(GTK_WIDGET(button), "abonmpdcomboboxentry6");

    radiobutton4 = lookup_widget(GTK_WIDGET(button), "radiobutton4");
    radiobutton5 = lookup_widget(GTK_WIDGET(button), "radiobutton5");
    radiobutton6 = lookup_widget(GTK_WIDGET(button), "radiobutton6");
    checkbutton2 = lookup_widget(GTK_WIDGET(button), "checkbutton2");

 
    strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nompdentry7)));
    strcpy(p.adresse, gtk_entry_get_text(GTK_ENTRY(adressempentry8)));
    strcpy(p.id, gtk_entry_get_text(GTK_ENTRY(idmpdentry9)));
    strcpy(p.capacite, gtk_entry_get_text(GTK_ENTRY(capacitempdentry10)));
    strcpy(p.tarif, gtk_entry_get_text(GTK_ENTRY(tarifmpdentry11)));

    strcpy(p.etat, gtk_combo_box_get_active_text(GTK_COMBO_BOX(etatmpdcomboboxentry4)));
    strcpy(p.bloc, gtk_combo_box_get_active_text(GTK_COMBO_BOX(blocmpdcomboboxentry5)));
    strcpy(p.abonnement, gtk_combo_box_get_active_text(GTK_COMBO_BOX(abonmpdcomboboxentry6)));

    p.jd = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin7));
    p.md = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin8));
    p.ad = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin9));
    p.jf = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin10));
    p.mf = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin11));
    p.af = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin12));

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))) {
        strcpy(p.vehicule, "voiture");
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton5))) {
        strcpy(p.vehicule, "camion");
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton6))) {
        strcpy(p.vehicule, "moto");
    } else {
        strcpy(p.vehicule, "inconnu");
    }

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbutton2))) {
        strcpy(p.acces, "oui");
    } else {
        strcpy(p.acces, "non");
    }

 
    if (modifier("parking.txt", p.id, p)) {
        GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          "Parking modifié avec succès !");
        gtk_dialog_run(GTK_DIALOG(success_dialog));
        gtk_widget_destroy(success_dialog);
    } else {
        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                        GTK_DIALOG_MODAL,
                                                        GTK_MESSAGE_ERROR,
                                                        GTK_BUTTONS_OK,
                                                        "Erreur lors de la modification du parking ou ID non trouvé !");
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
    }
}



void
on_annulermp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *nompdentry7, *adressempentry8, *idmpdentry9, *capacitempdentry10, *tarifmpdentry11;
    GtkWidget *etatmpdcomboboxentry4, *blocmpdcomboboxentry5, *abonmpdcomboboxentry6;
    GtkWidget *spin7, *spin8, *spin9, *spin10, *spin11, *spin12;


    nompdentry7 = lookup_widget(GTK_WIDGET(button), "nompdentry7");
    adressempentry8 = lookup_widget(GTK_WIDGET(button), "adressempentry8");  
    idmpdentry9 = lookup_widget(GTK_WIDGET(button), "idmpdentry9");
    capacitempdentry10 = lookup_widget(GTK_WIDGET(button), "capacitempdentry10");
    tarifmpdentry11 = lookup_widget(GTK_WIDGET(button), "tarifmpdentry11");

    spin7 = lookup_widget(GTK_WIDGET(button), "spin7");
    spin8 = lookup_widget(GTK_WIDGET(button), "spin8");
    spin9 = lookup_widget(GTK_WIDGET(button), "spin9");
    spin10 = lookup_widget(GTK_WIDGET(button), "spin10");
    spin11 = lookup_widget(GTK_WIDGET(button), "spin11");
    spin12 = lookup_widget(GTK_WIDGET(button), "spin12");

    etatmpdcomboboxentry4 = lookup_widget(GTK_WIDGET(button), "etatmpdcomboboxentry4");
    blocmpdcomboboxentry5 = lookup_widget(GTK_WIDGET(button), "blocmpdcomboboxentry5");
    abonmpdcomboboxentry6 = lookup_widget(GTK_WIDGET(button), "abonmpdcomboboxentry6");


    gtk_entry_set_text(GTK_ENTRY(nompdentry7), "");
    gtk_entry_set_text(GTK_ENTRY(adressempentry8), "");
    gtk_entry_set_text(GTK_ENTRY(idmpdentry9), "");
    gtk_entry_set_text(GTK_ENTRY(capacitempdentry10), "");
    gtk_entry_set_text(GTK_ENTRY(tarifmpdentry11), "");

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin7), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin8), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin9), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin10), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin11), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin12), 0);

    gtk_combo_box_set_active(GTK_COMBO_BOX(etatmpdcomboboxentry4), -1);
    gtk_combo_box_set_active(GTK_COMBO_BOX(blocmpdcomboboxentry5), -1);
    gtk_combo_box_set_active(GTK_COMBO_BOX(abonmpdcomboboxentry6), -1);

    g_print("Modification annulée et formulaire réinitialisé.\n");
}

void
on_supprimersup_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *idsuppentry12;
    char id[50];

 
    idsuppentry12 = lookup_widget(GTK_WIDGET(button), "idsuppentry12");
    strcpy(id, gtk_entry_get_text(GTK_ENTRY(idsuppentry12)));

 
    if (strlen(id) == 0) {
        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                        GTK_DIALOG_MODAL,
                                                        GTK_MESSAGE_WARNING,
                                                        GTK_BUTTONS_OK,
                                                        "Erreur : Veuillez entrer un ID valide.");
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
        return;
    }
 
    if (supprimer_parking("parking.txt", id)) {
 
        GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          "Parking supprimé avec succès !");
        gtk_dialog_run(GTK_DIALOG(success_dialog));
        gtk_widget_destroy(success_dialog);
    } else {
 
        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                        GTK_DIALOG_MODAL,
                                                        GTK_MESSAGE_ERROR,
                                                        GTK_BUTTONS_OK,
                                                        "Erreur : Parking avec l'ID %s introuvable.", id);
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
    }
}

void
on_annulersup_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *idsuppentry12;

    idsuppentry12 = lookup_widget(GTK_WIDGET(button), "idsuppentry12");

    gtk_entry_set_text(GTK_ENTRY(idsuppentry12), "");
}

void
on_affectag_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *pragentry15, *cinagentry16, *resultaffectentry9;
    const char *id_parking;
    const char *cin_agent;
    char result_message[256];

 
    pragentry15 = lookup_widget(GTK_WIDGET(button), "pragentry15");
    cinagentry16 = lookup_widget(GTK_WIDGET(button), "cinagentry16");
    resultaffectentry9 = lookup_widget(GTK_WIDGET(button), "resultaffectentry9");

 
    id_parking = gtk_entry_get_text(GTK_ENTRY(pragentry15));
    cin_agent = gtk_entry_get_text(GTK_ENTRY(cinagentry16));

 
    if (strlen(id_parking) == 0 || strlen(cin_agent) == 0) {
        gtk_entry_set_text(GTK_ENTRY(resultaffectentry9), "Erreur : Veuillez remplir tous les champs.");

        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                        GTK_DIALOG_MODAL,
                                                        GTK_MESSAGE_WARNING,
                                                        GTK_BUTTONS_OK,
                                                        "Erreur : Veuillez remplir tous les champs.");
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);

        return;
    }

 
    if (affecter_agent("parking.txt", "agent.txt", id_parking, cin_agent)) {
        snprintf(result_message, sizeof(result_message),
                 "Agent avec CIN %s affecté au parking ID %s avec succès.",
                 cin_agent, id_parking);

        gtk_entry_set_text(GTK_ENTRY(resultaffectentry9), result_message);

        GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          "Agent affecté avec succès !");
        gtk_dialog_run(GTK_DIALOG(success_dialog));
        gtk_widget_destroy(success_dialog);
    } else {
        snprintf(result_message, sizeof(result_message),
                 "Erreur : Échec de l'affectation. Vérifiez l'ID ou le CIN.");

        gtk_entry_set_text(GTK_ENTRY(resultaffectentry9), result_message);

        GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                                        GTK_DIALOG_MODAL,
                                                        GTK_MESSAGE_ERROR,
                                                        GTK_BUTTONS_OK,
                                                        "Erreur : Échec de l'affectation. Vérifiez l'ID ou le CIN.");
        gtk_dialog_run(GTK_DIALOG(error_dialog));
        gtk_widget_destroy(error_dialog);
    }
}

void
on_annuleraffag_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *pragentry15, *cinagentry16, *resultaffectentry9;

    pragentry15 = lookup_widget(GTK_WIDGET(button), "pragentry15");
    cinagentry16 = lookup_widget(GTK_WIDGET(button), "cinagentry16");
    resultaffectentry9 = lookup_widget(GTK_WIDGET(button), "resultaffectentry9");

    gtk_entry_set_text(GTK_ENTRY(pragentry15), "");
    gtk_entry_set_text(GTK_ENTRY(cinagentry16), "");
    gtk_entry_set_text(GTK_ENTRY(resultaffectentry9), "");
}


void
on_treeviewaffecteragent_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeModel *model;
    GtkTreeIter iter;
    gchar *parking_id;
    gchar *agent_cin;


 
    model = gtk_tree_view_get_model(treeview);

 
    if (gtk_tree_model_get_iter(model, &iter, path)) {
 
        gtk_tree_model_get(model, &iter,
                           0, &parking_id,
                           1, &agent_cin,
                           -1);
 
        printf("Parking ID: %s\n", parking_id);
        printf("CIN Agent: %s\n", agent_cin);


        g_free(parking_id);
        g_free(agent_cin);

    }
}

void
on_actualiseraffecte_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkTreeView *treeview;


    treeview = GTK_TREE_VIEW(lookup_widget(GTK_WIDGET(button), "treeviewaffecteragent"));


 
   afficher_affectations(treeview);

    printf("Affectations actualisées.\n");
}



void on_verifier_clicked(GtkButton *button, gpointer user_data) {
    parking p;
    GtkWidget *nompdentry7, *adressempentry8, *idmpdentry9, *capacitempdentry10, *tarifmpdentry11;
    GtkWidget *etatmpdcomboboxentry4, *blocmpdcomboboxentry5, *abonmpdcomboboxentry6;
    GtkWidget *spin7, *spin8, *spin9, *spin10, *spin11, *spin12;
    GtkWidget *radiobutton4, *radiobutton5, *radiobutton6, *checkbutton2;
    GtkWidget *dialog;
    char id[50];
    int found;

 
    idmpdentry9 = lookup_widget(GTK_WIDGET(button), "idmpdentry9");
    nompdentry7 = lookup_widget(GTK_WIDGET(button), "nompdentry7");
    adressempentry8 = lookup_widget(GTK_WIDGET(button), "adressempentry8");
    capacitempdentry10 = lookup_widget(GTK_WIDGET(button), "capacitempdentry10");
    tarifmpdentry11 = lookup_widget(GTK_WIDGET(button), "tarifmpdentry11");

    spin7 = lookup_widget(GTK_WIDGET(button), "spin7");
    spin8 = lookup_widget(GTK_WIDGET(button), "spin8");
    spin9 = lookup_widget(GTK_WIDGET(button), "spin9");
    spin10 = lookup_widget(GTK_WIDGET(button), "spin10");
    spin11 = lookup_widget(GTK_WIDGET(button), "spin11");
    spin12 = lookup_widget(GTK_WIDGET(button), "spin12");
    checkbutton2 = lookup_widget(GTK_WIDGET(button), "checkbutton2");

    etatmpdcomboboxentry4 = lookup_widget(GTK_WIDGET(button), "etatmpdcomboboxentry4");
    blocmpdcomboboxentry5 = lookup_widget(GTK_WIDGET(button), "blocmpdcomboboxentry5");
    abonmpdcomboboxentry6 = lookup_widget(GTK_WIDGET(button), "abonmpdcomboboxentry6");

    radiobutton4 = lookup_widget(GTK_WIDGET(button), "radiobutton4");
    radiobutton5 = lookup_widget(GTK_WIDGET(button), "radiobutton5");
    radiobutton6 = lookup_widget(GTK_WIDGET(button), "radiobutton6");

 
    strcpy(id, gtk_entry_get_text(GTK_ENTRY(idmpdentry9)));
    g_strstrip(id);

 
    found = verifier("parking.txt", id, &p);
    if (found) {
 
        gtk_entry_set_text(GTK_ENTRY(nompdentry7), p.nom);
        gtk_entry_set_text(GTK_ENTRY(adressempentry8), p.adresse);
        gtk_entry_set_text(GTK_ENTRY(capacitempdentry10), p.capacite);
        gtk_entry_set_text(GTK_ENTRY(tarifmpdentry11), p.tarif);

        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin7), p.jd);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin8), p.md);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin9), p.ad);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin10), p.jf);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin11), p.mf);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin12), p.af);

        gtk_combo_box_set_active(GTK_COMBO_BOX(etatmpdcomboboxentry4), 
                                 (strcmp(p.etat, "vide") == 0) ? 0 : 1);
        gtk_combo_box_set_active(GTK_COMBO_BOX(blocmpdcomboboxentry5), 
                                 p.bloc[0] - 'A'); 
        gtk_combo_box_set_active(GTK_COMBO_BOX(abonmpdcomboboxentry6), 
                                 (strcmp(p.abonnement, "mensuelle") == 0) ? 0 :
                                 (strcmp(p.abonnement, "parjour") == 0) ? 1 : 2);

        if (strcmp(p.vehicule, "voiture") == 0) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton4), TRUE);
        } else if (strcmp(p.vehicule, "camion") == 0) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton5), TRUE);
        } else if (strcmp(p.vehicule, "moto") == 0) {
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton6), TRUE);
        }

        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton2), 
                                     (strcmp(p.acces, "oui") == 0));
    } else {
        // Si le parking n'existe pas, afficher une boîte de dialogue d'erreur
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Parking introuvable !");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), 
                                                 "Le parking avec l'ID \"%s\" n'existe pas.", id);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

        // Réinitialiser les champs
        gtk_entry_set_text(GTK_ENTRY(nompdentry7), "");
        gtk_entry_set_text(GTK_ENTRY(adressempentry8), "");
        gtk_entry_set_text(GTK_ENTRY(capacitempdentry10), "");
        gtk_entry_set_text(GTK_ENTRY(tarifmpdentry11), "");
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin7), 1);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin8), 1);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin9), 2023);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin10), 1);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin11), 1);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin12), 2023);
        gtk_combo_box_set_active(GTK_COMBO_BOX(etatmpdcomboboxentry4), -1);
        gtk_combo_box_set_active(GTK_COMBO_BOX(blocmpdcomboboxentry5), -1);
        gtk_combo_box_set_active(GTK_COMBO_BOX(abonmpdcomboboxentry6), -1);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton4), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton5), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton6), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton2), FALSE);
    }
}




void
on_menuajout_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_menumodif_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_menusupp_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_menuaffect_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


void
on_annulertrvp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

 
    GtkWidget *idtrvprk = lookup_widget(GTK_WIDGET(button), "idtrvprk");  
    GtkWidget *resulttrvprk = lookup_widget(GTK_WIDGET(button), "resulttrvprk");  

 
    gtk_entry_set_text(GTK_ENTRY(idtrvprk), ""); 

 
    if (GTK_IS_LABEL(resulttrvprk)) {
        gtk_label_set_text(GTK_LABEL(resulttrvprk), ""); 
    } else if (GTK_IS_ENTRY(resulttrvprk)) {
        gtk_entry_set_text(GTK_ENTRY(resulttrvprk), "");  
    }


}



void
on_chercherprk_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    parking p;
    GtkWidget *idtrvprk, *resulttrvprk;
    GtkWidget *dialog;
    const char *id_parking;
    char result_message[512];  

    // Récupérer les widgets nécessaires
    idtrvprk = lookup_widget(GTK_WIDGET(button), "idtrvprk");        
    resulttrvprk = lookup_widget(GTK_WIDGET(button), "resulttrvprk");  

    // Récupérer l'ID du champ d'entrée
    id_parking = gtk_entry_get_text(GTK_ENTRY(idtrvprk));

    // Vérifier si l'ID est vide
    if (strlen(id_parking) == 0) {
        gtk_label_set_text(GTK_LABEL(resulttrvprk), "Erreur : Veuillez entrer un ID.");
        return;
    }

    // Rechercher le parking
    chercher_Parking(p, id_parking);

    // Ouvrir le fichier pour lire les résultats de la recherche
    FILE *rech_file = fopen("rechparking.txt", "r");
    if (rech_file != NULL) {
        if (fscanf(rech_file, "%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%d;%d;%d;%d;%d;%d;\n",
                   p.nom, p.adresse, p.id, p.capacite, p.tarif, p.etat, p.bloc, p.abonnement, p.vehicule, p.acces,
                   &p.jd, &p.md, &p.ad, &p.jf, &p.mf, &p.af) == 16) {

            // Construire le message de résultat
            snprintf(result_message, sizeof(result_message),
                     "Parking trouvé :\n"
                     "Nom : %s\nAdresse : %s\nID : %s\nCapacité : %s\nTarif : %s\nÉtat : %s\n"
                     "Bloc : %s\nAbonnement : %s\nVéhicule : %s\nAccès : %s\n"
                     "Date début : %d/%d/%d\nDate fin : %d/%d/%d",
                     p.nom, p.adresse, p.id, p.capacite, p.tarif, p.etat,
                     p.bloc, p.abonnement, p.vehicule, p.acces,
                     p.jd, p.md, p.ad, p.jf, p.mf, p.af);

            // Afficher un message de succès
            dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Parking trouvé avec succès !");
            gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "%s", result_message);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);

        } else {
            // Afficher un message d'erreur si le parking n'est pas trouvé
            dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_ERROR,
                                            GTK_BUTTONS_OK,
                                            "Parking introuvable !");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        fclose(rech_file);
    } else {
        // Afficher un message si le fichier ne peut pas être ouvert
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Erreur : Impossible d'ouvrir le fichier de recherche !");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }

    // Mettre à jour le widget résultat si applicable
    if (GTK_IS_LABEL(resulttrvprk)) {
        gtk_label_set_text(GTK_LABEL(resulttrvprk), result_message);
    } else if (GTK_IS_ENTRY(resulttrvprk)) {
        gtk_entry_set_text(GTK_ENTRY(resulttrvprk), result_message);
    }
}


void
on_mntrvp_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));

}




void
on_chercherchertrv_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
        gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
        gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
        gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
        gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
      
}


void on_accederlogin_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *id_entry = GTK_WIDGET(lookup_widget(GTK_WIDGET(button), "id_entry"));
    GtkWidget *password_entry = GTK_WIDGET(lookup_widget(GTK_WIDGET(button), "password_entry"));
    GtkWidget *dialog;

    if (!id_entry || !password_entry) {
        fprintf(stderr, "Error: Unable to find required widgets.\n");
        return;
    }

    // Récupérer les valeurs des champs d'entrée
    const char *id_text = gtk_entry_get_text(GTK_ENTRY(id_entry));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry));

    // Vérifier si les champs sont remplis
    if (strlen(id_text) == 0 || strlen(password) == 0) {
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "Erreur : Champs vides !");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), 
                                                 "Veuillez remplir les deux champs : ID et mot de passe.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    // Vérifier si l'ID est valide (entier numérique)
    int id = atoi(id_text);
    if (id == 0 && strcmp(id_text, "0") != 0) {
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Erreur : ID invalide !");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), 
                                                 "L'ID doit être un nombre entier.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    // Appel à la fonction de vérification des identifiants
    int login_status = loginUser(id, (char *)password);
    if (login_status > 0) {
        // Succès de la connexion
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Connexion réussie !");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), 
                                                 "Bienvenue, utilisateur avec ID : %d", id);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

        // Naviguer vers la page suivante
        gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
    } else {
        // Échec de la connexion
        dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(GTK_WIDGET(button))),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Connexion échouée !");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), 
                                                 "Identifiants invalides pour l'ID : %d. Veuillez réessayer.", id);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

void on_retauloginbutton1_clicked(GtkButton *button, gpointer user_data) {
    // Naviguer vers la page précédente
    gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button, "notebook1")));
}


//***********************************************************************************************************

