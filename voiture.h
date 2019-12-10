#include <gtk/gtk.h> 

typedef struct
{ char jour[50];
  char mois[50];
  char annee[50];
}datevo;



typedef struct 
{ char code[50];
  char marque[50];
  char nbre[50];
  datevo date_vo
}
infovoiture;




void Ajouter_vo( infovoiture voiture);
void supprimer_vo(char codee[20]);
void afficher_vo(GtkWidget *liste);

