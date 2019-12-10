#include <gtk/gtk.h>
typedef struct
{
char nom [20];
char prenom[20];
char identifiant[20];
char typedepaiment[20];
char montanttotale[20];
} facture ;
void afficher_factures(GtkWidget *treeview5);
void supprimer_factures(char id1[10]);
void afficher_factures_a(GtkWidget *liste);
void ajouter_facture(facture d);
void ajouter_facture_a(facture d);
