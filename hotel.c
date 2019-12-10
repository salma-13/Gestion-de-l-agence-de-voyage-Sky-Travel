#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "hotel.h"




void Ajouter_h( infohotel hotel )
{
date date_h;
FILE *f;
f=fopen("/home/salma/Projects/projects20/src/hotel.txt","a+");
if(f!=NULL)
{ fprintf(f,"%s %s %s %s %s %s %s %s\n",hotel.code,hotel.nom,hotel.ville,hotel.date_h.jour,hotel.date_h.mois,hotel.date_h.annee,hotel.nuitee,hotel.chambre
);

fclose(f);
}
}
 
void supprimer_h(char codee[20])
{ infohotel hotel;
  FILE *f,*g;
 f=fopen("/home/salma/Projects/project20/src/hotel.txt","r");
 g=fopen("/home/salma/Projects/project20/src/new_hotel.txt","w");
 
while (fscanf(f,"%s %s %s %s %s %s %s %s\n",hotel.code, hotel.nom,hotel.ville,hotel.date_h.jour,hotel.date_h.mois,hotel.date_h.annee,hotel.nuitee,hotel.chambre)!=EOF)
   {
   if (!strcmp(codee,hotel.code))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s %s %s\n",hotel.code, hotel.nom,hotel.ville,hotel.date_h.jour,hotel.date_h.mois,hotel.date_h.annee,hotel.nuitee,hotel.chambre); }}
        
       
fclose(f);
fclose(g);
remove("/home/salma/Projects/project20/src/hotel.txt");
rename("/home/salma/Projects/project20/src/new_hotel.txt","/home/salma/Projects/project20/src/hotel.txt");
}




enum
{
  CODE,
  NOM,
  VILLE,
  JOUR,
  MOIS,
  ANNEE,
  NUITEE,
  CHAMBRE,
  COLUMNS
};



void afficher_h (GtkWidget *liste)
{

   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   infohotel hotel;
//char code[20],nom[20],ville[20],jour[20],mois[20],annee[20],nuitee[20],chambre[20];
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("code", renderer, "text",CODE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",VILLE, NULL); 
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



renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" nuitee", renderer, "text",NUITEE,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" chambre", renderer, "text",CHAMBRE,NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/salma/Projects/project20/src/hotel.txt", "r"); 

  if(f==NULL)
  
   {
  return;
   }
  
  else
  {

  { f = fopen("/home/salma/Projects/project20/src/hotel.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s %s %s %s\n",hotel.code,hotel.nom,hotel.ville,hotel.date_h.jour,hotel.date_h.mois,hotel.date_h.annee,hotel.nuitee,hotel.chambre)!= EOF))
    {
 //GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,CODE,hotel.code,NOM,hotel.nom,VILLE,hotel.ville,JOUR,hotel.date_h.jour,MOIS,hotel.date_h.mois,ANNEE,hotel.date_h.annee,NUITEE,hotel.nuitee,CHAMBRE,hotel.chambre,-1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
}
  
}
}









