#include <gtk/gtk.h> 

typedef struct
{ char jour[50];
  char mois[50];
  char annee[50];
}date;

typedef struct 
{ char code[50];
  char nom[50];
  char ville[100];
  char nuitee[100];
  char chambre[100];
  date date_h;
}
infohotel;


void Ajouter_h( infohotel hotel);
void supprimer_h(char codee[20]);
void afficher_h(GtkWidget *liste);

