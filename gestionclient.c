#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestionclient.h"
#include "authenti.h"


void Ajouter( infoclient client )
{
date naissance;
FILE *f;
FILE *g;
f=fopen("/home/mayssa/Projects/finprojet/src/clients.txt","a+");
g=fopen("/home/mayssa/Projects/finprojet/src/users.txt","a+");
if(f!=NULL)
{ fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",client.nom, client.prenom,client.naissance.jour,client.naissance.mois,client.naissance.annee,client.telephone,client.cin,client.adress,
client.nationalite,client.identifiant,client.motdepasse);
fprintf(g,"%s %s %d\n",client.identifiant,client.motdepasse,3);
fclose(f);
fclose(g);

}
}
 
void supprimer(char identi[20])
{ infoclient client;
  FILE *f,*g;
  
 f=fopen("/home/mayssa/Projects/finprojet/src/clients.txt","r");
 g=fopen("/home/mayssa/Projects/finprojet/src/clients1.txt","w");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",client.nom, client.prenom,client.naissance.jour,client.naissance.mois,client.naissance.annee,client.telephone,client.cin,client.adress,
client.nationalite,client.identifiant,client.motdepasse)!=EOF) 
   {
   if (!strcmp(identi,client.identifiant))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s\n",client.nom, client.prenom,client.naissance.jour,client.naissance.mois,client.naissance.annee,client.telephone,client.cin,client.adress,
client.nationalite,client.identifiant,client.motdepasse);
   
        }
        }
fclose(f);
fclose(g);
remove("/home/mayssa/Projects/finprojet/src/clients.txt");
rename("/home/mayssa/Projects/finprojet/src/clients1.txt","/home/mayssa/Projects/finprojet/src/clients.txt");
}




enum
{
  NOM,
  PRENOM,
  JOUR,
  MOIS,
  ANNEE,
  TELEPHONE,
  CIN,
  ADRESS,
  NATIONALITE,
  IDENTIFIANT,
  MOTDEPASSE,
  COLUMNS
};

void afficher_personne(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   infoclient client;
   store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour de naissance", renderer, "text",JOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois de naissance", renderer, "text",MOIS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee de naissance", renderer, "text",ANNEE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text",TELEPHONE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("adress", renderer, "text",ADRESS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nationalite", renderer, "text",NATIONALITE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",IDENTIFIANT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mot de passe", renderer, "text",MOTDEPASSE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/mayssa/Projects/finprojet/src/clients.txt", "r"); 

  if(f==NULL)
  {
    return;
  }
  else

  { f = fopen("/home/mayssa/Projects/finprojet/src/clients.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",client.nom, client.prenom,client.naissance.jour,client.naissance.mois,client.naissance.annee,client.telephone,client.cin,client.adress,
client.nationalite,client.identifiant,client.motdepasse)!= EOF))
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,NOM,client.nom,PRENOM,client.prenom,JOUR,client.naissance.jour,MOIS,client.naissance.mois,ANNEE,client.naissance.annee,TELEPHONE,client.telephone,CIN,client.cin,ADRESS,client.adress,NATIONALITE,client.nationalite,IDENTIFIANT,client.identifiant,MOTDEPASSE,client.motdepasse, -1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}



////////////////////////////////////////////////////////////////////////////////////

int test_inscrit( infoclient client)
 { 
   int x,y,z,w,a,b,c,d,e;
   x=strcmp(client.nom,"");
   y=strcmp(client.prenom,"");
   z=strcmp(client.naissance.jour,"");
   w=strcmp(client.naissance.mois,"");
   a=strcmp(client.naissance.annee,"");
   b=strcmp(client.telephone,"");
   c=strcmp(client.cin,"");
   d=strcmp(client.identifiant,"");
   e=strcmp(client.motdepasse,"");
  if ((x==0)||(y==0)||(z==0)||(w==0)||(a==0)||(b==0)||(c==0)||(d==0)||(e==0))
  { return (-1);}
 return (1);
} 


int tab_clients( infoclient t[200])
  { int n=0;
    FILE *g;
    g=fopen("/home/mayssa/Projects/finprojet/src/clients.txt","r");
    if (g!=NULL)
  { while (fscanf(g,"%s %s %s %s %s %s %s %s %s %s %s\n",t[n].nom, t[n].prenom, t[n].naissance.jour, t[n].naissance.mois, t[n].naissance.annee, t[n].telephone, t[n].cin, t[n].adress,
t[n].nationalite, t[n].identifiant, t[n].motdepasse)!= EOF)
 {n++;}
fclose(g);}
return n ;}

int controle_identifiant( infoclient tab[200],char identifiant[20])
{ int n=tab_clients(tab);
  int i;
for (i=0; i<n;i++)
if (strcmp(tab[i].identifiant,identifiant)==0)
return i;
return -1;}

////////////////////////////////////////////////////////////////////////

void afficher_par_nomclient(GtkWidget * liste ,char nomclient[50])
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
infoclient client;
infoclient clientnew;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
  
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour de naissance", renderer, "text",JOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois de naissance", renderer, "text",MOIS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee de naissance", renderer, "text",ANNEE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("telephone", renderer, "text",TELEPHONE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("adress", renderer, "text",ADRESS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nationalite", renderer, "text",NATIONALITE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",IDENTIFIANT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mot de passe", renderer, "text",MOTDEPASSE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("/home/mayssa/Projects/finprojet/src/clients.txt","r+");

if(f==NULL)
{return;}
else
{f= fopen("/home/mayssa/Projects/finprojet/src/clients.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",client.nom, client.prenom,client.naissance.jour,client.naissance.mois,client.naissance.annee,client.telephone,client.cin,client.adress,
client.nationalite,client.identifiant,client.motdepasse)!=EOF)
{
if(!(strcmp(nomclient,client.nom)))
{GtkTreeIter iter;
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,client.nom,PRENOM,client.prenom,JOUR,client.naissance.jour,MOIS,client.naissance.mois,ANNEE,client.naissance.annee,TELEPHONE,client.telephone,CIN,client.cin,ADRESS,client.adress,NATIONALITE,client.nationalite,IDENTIFIANT,client.identifiant,MOTDEPASSE,client.motdepasse, -1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


/////////////////////////////////////////////////////////////////////////////


int test_inscrit_supprime(char id[20])
 { 
   int d;
   d=strcmp(id,"");
  if (d==0)
  { return (-1);}
 return (1);
} 







