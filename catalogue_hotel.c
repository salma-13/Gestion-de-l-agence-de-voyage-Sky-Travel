#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "catalogue_hotel.h"
#include <gtk/gtk.h>
enum
{
	NOM,
	LOCALISATION,
	RATE,
	PRIX,
	CODE,
	COLUMNS
};

void affiche_hotel(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char nom[20];
char localisation[20];
char rate[20];
char prix[20];
char code[20];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" localisation",renderer,"text",LOCALISATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  rate",renderer,"text",RATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/alaa/Projects/project9/src/hotel.txt","r");

if(f==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s\n",nom,localisation,rate,prix,code)!=EOF)
{
GtkTreeIter iter; /*TANSEHECH HEDI LI t5alli tab fera8 */
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,LOCALISATION,localisation,RATE,rate,PRIX,prix,CODE,code,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}


void recherche_code_hotel(GtkWidget *liste ,char rcode[20] )

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char nom[20];
char localisation[20];
char rate[20];
char prix[20];
char code[20];
store=NULL;

FILE *f;

  char tnom[20],tlocalisation[20],trate[20],tprix[20],tcode[20];
 
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" localisation",renderer,"text",LOCALISATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  rate",renderer,"text",RATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

/* el recherche */



  f = fopen("/home/alaa/Projects/project9/src/hotel.txt","r");

 
  if(f==NULL)
{
return;
}
else { f = fopen("/home/alaa/Projects/project9/src/hotel.txt","a+");
    while(fscanf(f,"%s %s %s %s %s",tnom,tlocalisation,trate,tprix,tcode) != EOF)
    {
if(!(strcmp(rcode,tcode)))
{GtkTreeIter iter; 
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,tnom,LOCALISATION,tlocalisation,RATE,trate,PRIX,tprix,CODE,tcode,-1);
      
    }}


  fclose(f);
 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}}

