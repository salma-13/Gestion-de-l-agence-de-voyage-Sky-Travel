#include <gtk/gtk.h> 


typedef struct { 
 char jour[5];
 char mois[5];
 char annee[5];
}
date;

typedef struct 
{ char nom[50];
  char prenom [50];
  date naissance;
  char cin[100];
   char telephone[100];
  char adress[100];
  char nationalite [50];
 char motdepasse[50];
 char identifiant[50];
}
infoclient;

void Ajouter( infoclient client);
void supprimer(char identi[20]);
void afficher_personne(GtkWidget *liste);
int test_inscrit( infoclient client);
int tab_clients( infoclient t[200]);
int controle_identifiant( infoclient tab[200],char identifiant[20]);
void afficher_par_nomclient(GtkWidget * liste ,char nomclient[50]);
int test_inscrit_supprime(char id[20]);
