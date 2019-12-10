#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "voiture.h"

void Ajouter_vo( infovoiture voiture )
{
datevo date_vo;
FILE *f;
f=fopen("/home/salma/Projects/projects20/src/voiture.txt","a+");
if(f!=NULL)
{ fprintf(f,"%s %s %s %s %s %s\n",voiture.code,voiture.marque,voiture.date_vo.jour,voiture.date_vo.mois,voiture.date_vo.annee,voiture.nbre);

fclose(f);
}
}
 
void supprimer_vo(char codee[20])
{ infovoiture voiture;
  FILE *f,*g;
 f=fopen("/home/salma/Projects/projects20/src/voiture.txt","r");
 g=fopen("/home/salma/Projects/projects20/src/new_voiture.txt","w");
 
while (fscanf(f,"%s %s %s %s %s %s\n",voiture.code, voiture.marque,voiture.date_vo.jour,voiture.date_vo.mois,voiture.date_vo.annee,voiture.nbre)!=EOF)
   {
   if (!strcmp(codee,voiture.code))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s \n",voiture.code, voiture.marque,voiture.date_vo.jour,voiture.date_vo.mois,voiture.date_vo.annee,voiture.nbre); }}
        
       
fclose(f);
fclose(g);
remove("/home/salma/Projects/projects20/src/voiture.txt");
rename("/home/salma/Projects/projects20/src/new_voiture.txt","/home/salma/Projects/projects20/src/voiture.txt");
}




enum
{
  CODE,
  MARQUE,
  JOUR,
  MOIS,
  ANNEE,
  NBRE,
  COLUMNS
};



void afficher_vo (GtkWidget *liste)
{

   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   infovoiture voiture;
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("code", renderer, "text",CODE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("marque", renderer, "text",MARQUE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JOUR,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",MOIS,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",ANNEE,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" nombre de jour", renderer, "text",NBRE,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/salma/Projects/projects20/src/voiture.txt", "r"); 

  if(f==NULL)
  
   {
  return;
   }
  
  else
  {

  { f = fopen("/home/salma/Projects/projects20/src/voiture.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s %s\n",voiture.code,voiture.marque,voiture.date_vo.jour,voiture.date_vo.mois,voiture.date_vo.annee,voiture.nbre)!= EOF))
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,CODE,voiture.code,MARQUE,voiture.marque,JOUR,voiture.date_vo.jour,MOIS,voiture.date_vo.mois,ANNEE,voiture.date_vo.annee,voiture.nbre,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}
}
