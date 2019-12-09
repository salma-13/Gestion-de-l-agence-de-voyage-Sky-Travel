#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "reclamation.h"
#include <gtk/gtk.h>
enum
{
	NUM_REC,
	TYPE_REC,
	CODE_REC,
	REC,
	COLUMNS
};
/////////////////////////////////////////////////////////////////////////////////////////
int ah_test_reclamation(reclamation r, char ch[20])
{int x,y,z,h,i;
h=strlen(ch);
if(h==0)
return -1;

for(i=0;i<h;i++)
if((ch[i]<'0')||(ch[i]>'9')){
return -1;}



x=strcmp(r.type_rec,"");
y=strcmp(r.code_rec,"");
z=strcmp(r.rec,"");


{if ((x==0)||(y==0)||(z==0))
return -1;}
return 1;}
////////////////////////////////////////////////////////////////////////////////////////////////////
int ah_tab_rec(reclamation tab[200])
{int n=0;
FILE *g;
g=fopen("/home/ahmed/Downloads/finprojet/src/reclamation.txt","r");
if (g!=NULL)
{while(fscanf(g,"%d %s %s %s\n",&tab[n].num_rec,tab[n].type_rec,tab[n].code_rec,tab[n].rec)!=EOF)
{n++;}
fclose(g);}
return n;
}
///////////////////////////////////////////////////////////////////////////////
int ah_Recherche_par_code (reclamation tab[200],char code_rec[20])
{int n=ah_tab_rec(tab); int i;
for(i=0;i<n;i++)
if (strcmp(tab[i].code_rec,code_rec)==0)
return i;
return -1;}
//modifier
void ah_modifier (reclamation tab[200],reclamation r)
{int x;
x=ah_Recherche_par_code (tab,r.code_rec);
int n=ah_tab_rec(tab);
if (x!=-1){
tab[x].num_rec=r.num_rec;
strcpy(tab[x].type_rec,r.type_rec);
strcpy(tab[x].rec,r.rec);}
ah_Reecrire_fichier(tab,n);
}
/////////////////////////////////////////////////////////////////////
void ah_Reecrire_fichier(reclamation tab[200],int n)
{
int i;
FILE *f;
f=fopen("/home/ahmed/Downloads/finprojet/src/reclamation.txt","w");
for(i=0;i<n;i++)
{fprintf(f,"%d %s %s %s\n",tab[i].num_rec,tab[i].type_rec,tab[i].code_rec,tab[i].rec);}
fclose(f);}
//supprime
void supprimerah (reclamation tab[200],reclamation r)//char code_rec[20]
{int x;reclamation h;
int n=ah_tab_rec(tab);
x=ah_Recherche_par_code (tab,r.code_rec);
if (x!=-1){
h=tab[x];
tab[x]=tab[n-1];
tab[n-1]=h;
ah_Reecrire_fichier(tab,n-1);}
}

//ajouter
void ah_ajouter (reclamation r)
{

FILE *f;
f=fopen("/home/ahmed/Downloads/finprojet/src/reclamation.txt","a+");
if (f!=NULL)
{
fprintf(f,"%d %s %s %s\n",r.num_rec,r.type_rec,r.code_rec,r.rec );
fclose(f);
}
}

////afficher
void ah_afficher (GtkWidget * liste)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
char num_rec[20];
char type_rec[20];
char code_rec[20];
char rec[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  num_rec",renderer,"text",NUM_REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  type_rec",renderer,"text",TYPE_REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code_rec",renderer,"text",CODE_REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  rec",renderer,"text",REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/ahmed/Downloads/finprojet/src/reclamation.txt","r+");

if(f==NULL)
return;
else
{
while(fscanf(f,"%s %s %s %s\n",num_rec,type_rec,code_rec,rec)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NUM_REC, num_rec, TYPE_REC, type_rec, CODE_REC, code_rec,REC,rec,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void affich_reponse_client (GtkWidget * liste)
{
enum
{
	CODE_REP,
	REP,
	COLUMNES
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 

char code_rep[20];
char rep[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code_rep",renderer,"text",CODE_REP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  rep",renderer,"text",REP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNES,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/ahmed/Downloads/finprojet/src/reponse.txt","r+");

if(f==NULL)
return;
else
{
while(fscanf(f,"%s %s\n",code_rep,rep)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter, CODE_REP, code_rep,REP,rep,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

/////////////////////////////////////////////////////////////////////////////////////////
void ah_ajouter1 (reponse r)
{
//format(r.rep);
FILE *f;
f=fopen("/home/ahmed/Downloads/finprojet/src/reponse.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s\n",r.code_rep,r.rep );
fclose(f);
}
}
////////////////////////////////////////////////////////////////////////////////////

void ah_afficher_par_type(GtkWidget * liste ,char type_recl[20])
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
char num_rec[20];
char type_rec[20];
char code_rec[20];
char rec[100];
store=NULL;
FILE *f;
char anum_rec[20],atype_rec[20],acode_rec[20],arec[20];
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  num_rec",renderer,"text",NUM_REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  type_rec",renderer,"text",TYPE_REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  code_rec",renderer,"text",CODE_REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  rec",renderer,"text",REC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/ahmed/Downloads/finprojet/src/reclamation.txt","r+");

if(f==NULL)
{return;}
else
{f= fopen("/home/ahmed/Downloads/finprojet/src/reclamation.txt","a+");
while(fscanf(f,"%s %s %s %s\n",anum_rec,atype_rec,acode_rec,arec)!=EOF)
{
if(!(strcmp(type_recl,atype_rec)))
{GtkTreeIter iter;
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NUM_REC, anum_rec, TYPE_REC, atype_rec, CODE_REC, acode_rec,REC,arec,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ah_Recherche_par_code1 (reclamation tab[200],char code_rep[20])
{int n=ah_tab_rec(tab); int i;
for(i=0;i<n;i++)
if (strcmp(tab[i].code_rec,code_rep)==0)
return i;
return -1;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ah_test_reclamation1(reponse r)
{int y,z;

y=strcmp(r.code_rep,"");
z=strcmp(r.rep,"");


{if ((y==0)||(z==0))
return -1;}
return 1;}
