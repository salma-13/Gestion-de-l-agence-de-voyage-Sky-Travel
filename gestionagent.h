#include <gtk/gtk.h> 


typedef struct { 
 char jour[5];
 char mois[5];
 char annee[5];
}
da;

typedef struct 
{ char nom[50];
  char prenom [50];
  da naissance;
  char cin[100];
   char telephone[100];
  char adress[100];
  char nationalite [50];
 char motdepasse[50];
 char identifiant[50];
}
infoagent;

void Ajouter_agent( infoagent agent);
void supprimer_agent(char identi[20]);
void afficher_personne_agent(GtkWidget *liste);
int test_inscrit_agent( infoagent client);
int tab_agent( infoagent t[200]);
int controle_identifiant_agent( infoagent tab[200],char identifiant[20]);
