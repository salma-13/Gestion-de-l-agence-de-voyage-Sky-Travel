#include <gtk/gtk.h>


typedef struct
{

char nom[20];
char localisation[20];
char rate[20];
char prix[20];
char code[20];

}hotel;

void affiche_hotel(GtkWidget *liste);
void recherche_code_hotel(GtkWidget *liste ,char rcode[20] );
