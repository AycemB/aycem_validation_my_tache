#ifndef aycem_h
#define aycem_h
#include<stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
typedef struct {
int jour;
int mois;
int annee;
}date;
typedef struct {
    char nom[100];
    char adresse[100];
    char id[100];
    char etat[100];
    char capacite[100];
    char bloc[100];
    char tarif[100];
    char abonnement[100];
    char acces[100]; 
    char vehicule[100];
    int jd, md, ad; 
    int jf, mf, af;
} parking;

typedef struct {
    char nom[50];          
    char pren[50];        
    char cin[20];          
    date dn;
    char sexe[10];        
    char etatCiv[20];      
    char etatSan[20];    
    char tel[20];          
    char email[50];      
    char poste[50];        
    char nomAdmin[50];    
    char mdp[50];        
} Agent;
typedef struct{
 int id_administ;
 char password[100];
}login;


char *nomp ;
int ajouter( char *filename, parking p);
int modifier(const char *filename, const char *id, parking nouveau_parking) ;
int supprimer_parking(const char *filename, const char *id) ;
void chercher_Parking(parking p, const  char *text); 
int affecter_agent(const char *parking_file, const char *agent_file, const char *id_parking, const char *cin_agent);
void afficher_Parking(GtkWidget *liste, char *nomp);
void afficher_affectations(GtkWidget *treeview);
void init_treeview(GtkTreeView *treeview) ;
int verifier(const char *filename, const char *id, parking *result);
int loginUser(int id, char *password);
#endif
