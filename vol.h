#include <gtk/gtk.h> 

typedef struct
{ char jour[50];
  char mois[50];
  char annee[50];
}datev;


typedef struct 
{ char num[50];
  char destination[50];
  datev date_v;
  
}
infovol;

void Ajouter_v( infovol vol);
void supprimer_v(char codee[20]);
void afficher_v(GtkWidget *liste);

