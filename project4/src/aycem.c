#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include "aycem.h"
#include <gtk/gtk.h>

#include <stdlib.h>
#include <string.h>
# define COLUMNS 16
#define FILE_PATH "administrateur.txt"

parking p;

enum
{
  ENOMP,
  EADRESSEP,
  EIDP,
  ECAPACITE,
  EETAT,
  EBLOC,
  ETARIF,
  EABONNEMENT,
  EVEHICULE,
  EACCES,
  EJD,
  EMD,
  EAD,
  EJF,
  EMF,
  EAF,
  
};

int ajouter(char *filename, parking p) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }
    fprintf(file, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%d;%d;%d;%d;%d;%d;\n",
            p.nom, p.adresse, p.id, p.capacite, p.tarif,
            p.etat, p.bloc, p.abonnement, p.vehicule, p.acces,
            p.jd, p.md, p.ad, p.jf, p.mf, p.af);
    fclose(file);
    return 1;
}
int modifier(const char *filename, const char *id, parking nouveau_parking) {
    int tr = 0; // Indicateur de modification
    parking temp_p;
    FILE *file = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        perror("Erreur d'ouverture du fichier");
        return 0; // Échec
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Lecture des champs
        if (sscanf(buffer, "%49[^;];%49[^;];%19[^;];%9[^;];%9[^;];%19[^;];%19[^;];%19[^;];%19[^;];%9[^;];%d;%d;%d;%d;%d;%d",
                   temp_p.nom, temp_p.adresse, temp_p.id, temp_p.capacite, temp_p.tarif,
                   temp_p.etat, temp_p.bloc, temp_p.abonnement, temp_p.vehicule, temp_p.acces,
                   &temp_p.jd, &temp_p.md, &temp_p.ad, &temp_p.jf, &temp_p.mf, &temp_p.af) == 16) {

            // Comparaison des IDs
            if (strcmp(temp_p.id, id) == 0) {
                fprintf(temp, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%d;%d;%d;%d;%d;%d\n",
                        nouveau_parking.nom, nouveau_parking.adresse, nouveau_parking.id,
                        nouveau_parking.capacite, nouveau_parking.tarif, nouveau_parking.etat,
                        nouveau_parking.bloc, nouveau_parking.abonnement, nouveau_parking.vehicule,
                        nouveau_parking.acces, nouveau_parking.jd, nouveau_parking.md, nouveau_parking.ad,
                        nouveau_parking.jf, nouveau_parking.mf, nouveau_parking.af);
                tr = 1; // Modification trouvée
            } else {
                fputs(buffer, temp); // Recopie de la ligne existante
            }
        }
    }

    fclose(file);
    fclose(temp);

    if (tr) {
        // Remplacement du fichier original
        if (remove(filename) != 0 || rename("temp.txt", filename) != 0) {
            perror("Erreur lors du remplacement du fichier");
            return 0;
        }
    } else {
        remove("temp.txt"); // Suppression du fichier temporaire
    }

    return tr;
}


int supprimer_parking(const char *filename, const char *id) {
    FILE *file = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return 0;
    }

    parking p;
    int found = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%d;%d;%d;%d;",
               p.nom, p.adresse, p.id, p.capacite, p.tarif,
               p.etat, p.bloc, p.abonnement, p.vehicule, &p.acces,
               &p.jd, &p.md, &p.ad, &p.jf, &p.mf, &p.af);

        // Comparer l'ID
        if (strcmp(p.id, id) != 0) {
            fputs(buffer, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        if (remove(filename) != 0 || rename("temp.txt", filename) != 0) {
            perror("Erreur lors de la mise à jour du fichier");
            return 0;
        }
        printf("Parking supprimé avec succès.\n");
        return 1;
    } else {
        remove("temp.txt");
        printf("Parking non trouvé.\n");
        return 0;
    }
}
void afficher_Parking(GtkWidget *liste, char *nomp) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    // Variables for storing data
    char nom[100], adresse[100], id[100], capacite[100], tarif[100], etat[100], bloc[100], abonnement[100], vehicule[100];
    char acces[100];
    int jd, md, ad, jf, mf, af;
    char buffer[512];

    // Get the existing model
    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));

    if (store == NULL) {
        // Create a new model if none exists
        store = gtk_list_store_new(COLUMNS,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,
                                   G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

        // Add columns only once
        renderer = gtk_cell_renderer_text_new();

        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOMP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", EADRESSEP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EIDP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Capacité", renderer, "text", ECAPACITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Tarif", renderer, "text", ETARIF, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("État", renderer, "text", EETAT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Bloc", renderer, "text", EBLOC, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Abonnement", renderer, "text", EABONNEMENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Véhicule", renderer, "text", EVEHICULE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Accès", renderer, "text", EACCES, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Jour Début", renderer, "text", EJD, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Mois Début", renderer, "text", EMD, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Année Début", renderer, "text", EAD, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Jour Fin", renderer, "text", EJF, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Mois Fin", renderer, "text", EMF, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        column = gtk_tree_view_column_new_with_attributes("Année Fin", renderer, "text", EAF, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    } else {
 
        gtk_list_store_clear(store);
    }

 
    FILE *f = fopen(nomp, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier : %s\n", nomp);
        return;
    }

 
    while (fgets(buffer, sizeof(buffer), f)) {
        if (sscanf(buffer, "%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%d;%d;%d;%d;%d;%d\n",
                   nom, adresse, id, capacite, tarif, etat, bloc, abonnement, vehicule, acces,
                   &jd, &md, &ad, &jf, &mf, &af) == 16) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,
                               ENOMP, nom,
                               EADRESSEP, adresse,
                               EIDP, id,
                               ECAPACITE, capacite,
                               ETARIF, tarif,
                               EETAT, etat,
                               EBLOC, bloc,
                               EABONNEMENT, abonnement,
                               EVEHICULE, vehicule,
                               EACCES, acces,
                               EJD, jd,
                               EMD, md,
                               EAD, ad,
                               EJF, jf,
                               EMF, mf,
                               EAF, af,
                               -1);
        }
    }

    fclose(f);

 
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

    
}







void chercher_Parking(parking p, const char *text) {
    FILE *f4 = NULL;
    FILE *ff = NULL;
    char line[1024]; // Buffer pour lire les lignes du fichier
    char *token;     // Pointeur pour parcourir les champs
    int field_count; // Nombre de champs dans la ligne

    // Supprimer le fichier de recherche existant
    remove("rechparking.txt");

    // Ouvrir les fichiers
    f4 = fopen("parking.txt", "r");
    if (f4 == NULL) {
        printf("Erreur : Impossible d'ouvrir parking.txt\n");
        return;
    }

    ff = fopen("rechparking.txt", "a");
    if (ff == NULL) {
        printf("Erreur : Impossible de créer rechparking.txt\n");
        fclose(f4);
        return;
    }

    // Lire chaque ligne de parking.txt
    while (fgets(line, sizeof(line), f4) != NULL) {
        // Réinitialiser les champs et le compteur
        field_count = 0;

        // Découper la ligne en champs
        token = strtok(line, ";");
        while (token != NULL) {
            field_count++;

            // Assigner les champs au bon endroit
            switch (field_count) {
                case 1: strcpy(p.nom, token); break;
                case 2: strcpy(p.adresse, token); break;
                case 3: strcpy(p.id, token); break;
                case 4: strcpy(p.capacite, token); break;
                case 5: strcpy(p.tarif, token); break;
                case 6: strcpy(p.etat, token); break;
                case 7: strcpy(p.bloc, token); break;
                case 8: strcpy(p.abonnement, token); break;
                case 9: strcpy(p.vehicule, token); break;
                case 10: strcpy(p.acces, token); break;
                case 11: p.jd = atoi(token); break;
                case 12: p.md = atoi(token); break;
                case 13: p.ad = atoi(token); break;
                case 14: p.jf = atoi(token); break;
                case 15: p.mf = atoi(token); break;
                case 16: p.af = atoi(token); break;
            }

            token = strtok(NULL, ";");
        }

        // Si la ligne contient au moins 16 champs, vérifier l'ID
        if (field_count >= 16 && strcmp(p.id, text) == 0) {
            // Écrire la ligne trouvée dans rechparking.txt
            fprintf(ff, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%d;%d;%d;%d;%d;%d;\n",
                    p.nom, p.adresse, p.id, p.capacite, p.tarif, p.etat, p.bloc,
                    p.abonnement, p.vehicule, p.acces,
                    p.jd, p.md, p.ad, p.jf, p.mf, p.af);
        }
    }

    // Fermer les fichiers
    fclose(f4);
    fclose(ff);

    printf("Recherche terminée. Vérifiez rechparking.txt pour les résultats.\n");
}



int verifier(const char *filename, const char *id, parking *result) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return 0; 
    }

    parking p;
    char line[512];

 
    while (fgets(line, sizeof(line), f)) {
 
        char *tokens[16] = {NULL};
        int i = 0;
        char *token = strtok(line, ";");
        while (token && i < 16) {
            tokens[i++] = token;
            token = strtok(NULL, ";");
        }

 
        if (i >= 16) {
            strncpy(p.nom, tokens[0], sizeof(p.nom) - 1);
            strncpy(p.adresse, tokens[1], sizeof(p.adresse) - 1);
            strncpy(p.id, tokens[2], sizeof(p.id) - 1);
            strncpy(p.capacite, tokens[3], sizeof(p.capacite) - 1);
            strncpy(p.tarif, tokens[4], sizeof(p.tarif) - 1);
            strncpy(p.etat, tokens[5], sizeof(p.etat) - 1);
            strncpy(p.bloc, tokens[6], sizeof(p.bloc) - 1);
            strncpy(p.abonnement, tokens[7], sizeof(p.abonnement) - 1);
            strncpy(p.vehicule, tokens[8], sizeof(p.vehicule) - 1);
            strncpy(p.acces, tokens[9], sizeof(p.acces) - 1);
            p.jd = atoi(tokens[10]);
            p.md = atoi(tokens[11]);
            p.ad = atoi(tokens[12]);
            p.jf = atoi(tokens[13]);
            p.mf = atoi(tokens[14]);
            p.af = atoi(tokens[15]);

 
            if (strcmp(p.id, id) == 0) {
                *result = p;
                fclose(f);
                return 1;  
            }
        }
    }

    fclose(f);
    return 0;  
}




int affecter_agent(const char *parking_file, const char *agent_file, const char *id_parking, const char *cin_agent) {
    FILE *f_parking = fopen(parking_file, "r");
    FILE *f_agent = fopen(agent_file, "r");
    FILE *temp_parking = fopen("temp_parking.txt", "w");
    char parking_line[512];
    char agent_line[512];
    int parking_found = 0, agent_found = 0;

 
    if (!f_parking || !f_agent || !temp_parking) {
        printf("Erreur : Impossible d'ouvrir un ou plusieurs fichiers.\n");
        if (f_parking) fclose(f_parking);
        if (f_agent) fclose(f_agent);
        if (temp_parking) fclose(temp_parking);
        return 0;
    }

 
    Agent a;
    while (fgets(agent_line, sizeof(agent_line), f_agent)) {
        sscanf(agent_line, "%s %s %s", a.nom, a.pren, a.cin);
        if (strcmp(a.cin, cin_agent) == 0) {
            agent_found = 1;
            break;
        }
    }
    fclose(f_agent);

    if (!agent_found) {
        printf("Erreur : Agent avec CIN %s introuvable.\n", cin_agent);
        fclose(f_parking);
        fclose(temp_parking);
        remove("temp_parking.txt");
        return 0;
    }

 
    while (fgets(parking_line, sizeof(parking_line), f_parking)) {
        char current_id[100];
        sscanf(parking_line, "%*[^;];%*[^;];%[^;]", current_id); 
        if (strcmp(current_id, id_parking) == 0) {
            parking_found = 1;

 
            char new_parking_line[512];
            snprintf(new_parking_line, sizeof(new_parking_line), "%s;%s;%s\n", 
                     strtok(parking_line, "\n"), a.nom, a.cin);
            fputs(new_parking_line, temp_parking);
        } else {
            fputs(parking_line, temp_parking);  
        }
    }
    fclose(f_parking);
    fclose(temp_parking);

 
    if (parking_found) {
        remove(parking_file);
        rename("temp_parking.txt", parking_file);
        printf("Agent avec CIN %s affecté au parking ID %s avec succès.\n", cin_agent, id_parking);
    } else {
        printf("Erreur : Parking avec ID %s introuvable.\n", id_parking);
        remove("temp_parking.txt");
    }

    return parking_found && agent_found;
}

void afficher_affectations(GtkWidget *ParkingTreeView) {
    FILE *f_parking;
    char line[512];
    char id_parking[50], agent_cin[50];

 
    GtkListStore *store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);  

 
    f_parking = fopen("parking.txt", "r");
    if (!f_parking) {
        printf("Erreur : Impossible d'ouvrir le fichier parking.txt\n");
        return;
    }

 
    while (fgets(line, sizeof(line), f_parking)) {
 
        memset(id_parking, 0, sizeof(id_parking));
        memset(agent_cin, 0, sizeof(agent_cin));

 
        char *tokens[20] = {NULL};
        int i = 0;
        char *token = strtok(line, ";");
        while (token && i < 20) {
            tokens[i++] = token;
            token = strtok(NULL, ";");
        }

 
        if (tokens[2]) strncpy(id_parking, tokens[2], sizeof(id_parking) - 1);  
        if (tokens[i - 1]) strncpy(agent_cin, tokens[i - 1], sizeof(agent_cin) - 1);  

 
        if (strlen(id_parking) > 0 && strlen(agent_cin) > 0) {
            GtkTreeIter iter;
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,
                               0, id_parking,  
                               1, agent_cin,    
                               -1);
        }
    }

    fclose(f_parking);

 
    gtk_tree_view_set_model(GTK_TREE_VIEW(ParkingTreeView), GTK_TREE_MODEL(store));
    g_object_unref(store);

 
    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(ParkingTreeView)) == NULL) {
        GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
        GtkTreeViewColumn *column;

        column = gtk_tree_view_column_new_with_attributes("ID Parking", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(ParkingTreeView), column);

        column = gtk_tree_view_column_new_with_attributes("CIN Agent", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(ParkingTreeView), column);
    }
}

int loginUser(int id, char *password) {
    login admin;
    FILE *file = fopen("administrateur.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open administrateur.txt\n");
        return -1;
    }

    printf("Reading from administrateur.txt...\n");

    // Loop through the administrators in the file
    while (fscanf(file, "%d %49s", &admin.id_administ, admin.password) != EOF) {
        // Debug: Print the parsed admin
        printf("Parsed admin: ID=%d, Password=%s\n", admin.id_administ, admin.password);

        // Check if the ID and password match
        if (admin.id_administ == id && strcmp(admin.password, password) == 0) {
            fclose(file);  // Close the file before returning
            printf("Login successful for user ID %d\n", admin.id_administ);
            return 1; // Successful login
        }
    }

    // No match found
    fclose(file);
    printf("Login failed. No matching administrator found.\n");
    return 0; // Failed login
}


