#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "vol.h"


void Ajouter_v( infovol vol )
{
datev date_v;
FILE *f;
f=fopen("/home/salma/Projects/project20/src/vol.txt","a+");
if(f!=NULL)
{ fprintf(f,"%s %s %s %s %s\n",vol.num,vol.destination,vol.date_v.jour,vol.date_v.mois,vol.date_v.annee
);

fclose(f);
}
}
 
void supprimer_v(char codee[20])
{ infovol vol;
  FILE *f,*g;
 f=fopen("/home/salma/Projects/project20/src/vol.txt","r");
 g=fopen("/home/salma/Projects/project20/src/new_vol.txt","w");
 
while (fscanf(f,"%s %s %s %s %s %s\n",vol.num, vol.destination,vol.date_v.jour,vol.date_v.mois,vol.date_v.annee)!=EOF)
   {
   if (!strcmp(codee,vol.num))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s %s %s\n",vol.num, vol.destination,vol.date_v.jour,vol.date_v.mois,vol.date_v.annee); }}
        
       
fclose(f);
fclose(g);
remove("/home/salma/Projects/project20/src/vol.txt");
rename("/home/salma/Projects/project20/src/new_vol.txt","/home/salma/Projects/project20/src/vol.txt");
}




enum
{
  NUM,
  DESTINATION,
  JOUR,
  MOIS,
  ANNEE,
  COLUMNS
};



void afficher_v (GtkWidget *liste)
{

   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   infovol vol;
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("num", renderer, "text",NUM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("destination", renderer, "text",DESTINATION, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JOUR,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MOIS,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",ANNEE,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);




store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/salma/Projects/project20/src/vol.txt", "r"); 

  if(f==NULL)
  
   {
  return;
   }
  
  else
  {

  { f = fopen("/home/salma/Projects/project20/src/vol.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s\n",vol.num,vol.destination,vol.date_v.jour,vol.date_v.mois,vol.date_v.annee)!= EOF))
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,NUM,vol.num,DESTINATION,vol.destination,JOUR,vol.date_v.jour,MOIS,vol.date_v.mois,ANNEE,vol.date_v.annee,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);

  }
}
}


