#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "catalogue_voiture.h"
#include <gtk/gtk.h>
enum
{
	MARQUE,
	INFO,
	PRIX,
	CODE,
	COLUMNS
};

void affiche_voiture(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char marque[20];
char info[20];
char prix[20];
char code[20];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" info",renderer,"text",INFO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  PRIX",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/alaa/Projects/project9/src/voiture.txt","r");

if(f==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s \n",marque,info,prix,code)!=EOF)
{
GtkTreeIter iter; /*TANSEHECH HEDI LI t5alli tab fera8 */
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,MARQUE,marque,INFO,info,PRIX,prix,CODE,code,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}










void recherche_code_voiture(GtkWidget *liste ,char rcode[20] )

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char marque[20];
char info[20];
char prix[20];
char code[20];
store=NULL;

FILE *f;

  char tmarque[20],tinfo[20],tprix[20],tcode[20];
 
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" info",renderer,"text",INFO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

/* el recherche */



  f = fopen("/home/alaa/Projects/project9/src/voiture.txt","r");

 
  if(f==NULL)
{
return;
}
else { f = fopen("/home/alaa/Projects/project9/src/voiture.txt","a+");
    while(fscanf(f,"%s %s %s %s",tmarque,tinfo,tprix,tcode) != EOF)
    {
if(!(strcmp(rcode,tcode)))
{GtkTreeIter iter; 
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,MARQUE,tmarque,INFO,tinfo,PRIX,tprix,CODE,tcode,-1);
      
    }}


  fclose(f);
 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
