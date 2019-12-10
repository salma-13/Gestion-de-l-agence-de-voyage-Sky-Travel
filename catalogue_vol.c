#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "catalogue_vol.h"
#include <gtk/gtk.h>
enum
{
        NOM,   
	DEPART,
	ARRIVE,
	DATE,
	PRIX,
        CODE,
	COLUMNS
};

void affiche_vol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char nom[20];
char depart[20];
char arrive[20];
char date[20];
char prix[20];
char code[20];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" depart",renderer,"text",DEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  arrive",renderer,"text",ARRIVE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/alaa/Projects/project9/src/vol.txt","r");

if(f==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s %s\n",nom,depart,arrive,date,prix,code)!=EOF)
{
GtkTreeIter iter; /*TANSEHECH HEDI LI t5alli tab fera8 */
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,DEPART,depart,ARRIVE,arrive,DATE,date,PRIX,prix,CODE,code,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}






void recherche_code_vol(GtkWidget *liste ,char rcode[20] )

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char nom[20];
char depart[20];
char arrive[20];
char date[20];
char prix[20];
char code[20];
store=NULL;

FILE *f;

  char tnom[20],tdepart[20],tarrive[20],tdate[20],tprix[20],tcode[20];
 
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" depart",renderer,"text",DEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  arrive",renderer,"text",ARRIVE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



  f = fopen("/home/alaa/Projects/project9/src/vol.txt","r");

 
  if(f==NULL)
{
return;
}
else { f = fopen("/home/alaa/Projects/project9/src/vol.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s",tnom,tdepart,tarrive,tdate,tprix,tcode) != EOF)
    {
if(!(strcmp(rcode,tcode)))
{GtkTreeIter iter; 
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,tnom,DEPART,tdepart,ARRIVE,tarrive,DATE,tdate,PRIX,tprix,CODE,tcode,-1);
      
    }}


  fclose(f);
 
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

}
