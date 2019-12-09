#include <gtk/gtk.h>
typedef struct {
int num_rec;
char type_rec[20];
char code_rec[20];
char rec[100];
}reclamation;
typedef struct{
char code_rep[20];
char rep[100];}reponse;
int ah_test_reclamation(reclamation r,char ch[20]);
int ah_tab_rec(reclamation tab[200]);
int ah_Recherche_par_code (reclamation tab[200],char code_rec[20]);
void ah_modifier (reclamation tab[200],reclamation r);
void ah_Reecrire_fichier(reclamation tab[200],int n);
void ah_ajouter (reclamation r);
void ah_afficher (GtkWidget * liste);
void supprimerah (reclamation tab[200],reclamation r);//char code_rec[20]
void affich_reponse_client (GtkWidget * liste);
void ah_ajouter1 (reponse r);
int ah_test_reclamation1(reponse r);
int ah_Recherche_par_code1 (reclamation tab[200],char code_rep[20]);
void ah_afficher_par_type(GtkWidget * liste ,char type_recl[20]);
void ah_ajouter1 (reponse r);
