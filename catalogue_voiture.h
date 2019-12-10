#include <gtk/gtk.h>


typedef struct
{

char marque[20];
char info[20];
char prix[20];
char code[20];

}voiture;

void affiche_voiture(GtkWidget *liste);
void recherche_code_voiture(GtkWidget *liste ,char rlocalisation[20] );
