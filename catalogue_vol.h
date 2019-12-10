#include <gtk/gtk.h>


typedef struct
{

char nom[20];
char depart[20];
char arrive[20];
char date[20];
char prix[20];
char code[20];

}vol;

void affiche_vol(GtkWidget *liste);
void recherche_code_vol(GtkWidget *liste ,char code[20] );
