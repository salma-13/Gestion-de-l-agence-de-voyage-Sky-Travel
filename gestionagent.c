#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestionagent.h"
#include "authenti.h"


void  Ajouter_agent( infoagent agent)
{
da naissance;
FILE *f;
FILE *g;
f=fopen("/home/abdou/Projects/finprojet/src/agent.txt","a+");
g=fopen("/home/abdou/Projects/finprojet/src/users.txt","a+");
if(f!=NULL)
{ fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",agent.nom, agent.prenom,agent.naissance.jour,agent.naissance.mois,agent.naissance.annee,agent.telephone,agent.cin,agent.adress,
agent.nationalite,agent.identifiant,agent.motdepasse);
fprintf(g,"%s %s %d\n",agent.identifiant,agent.motdepasse,2);
fclose(f);
fclose(g);

}
}
 
void supprimer_agent(char identi[20])
{ infoagent agent;
  FILE *f,*g;
 f=fopen("/home/abdou/Projects/finprojet/src/agent.txt","r");
 g=fopen("/home/abdou/Projects/finprojet/src/agent1.txt","w");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",agent.nom, agent.prenom,agent.naissance.jour,agent.naissance.mois,agent.naissance.annee,agent.telephone,agent.cin,agent.adress,
agent.nationalite,agent.identifiant,agent.motdepasse)!=EOF) 
   {
   if (!strcmp(identi,agent.identifiant))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s\n",agent.nom, agent.prenom,agent.naissance.jour,agent.naissance.mois,agent.naissance.annee,agent.telephone,agent.cin,agent.adress,
agent.nationalite,agent.identifiant,agent.motdepasse);}}
fclose(f);
fclose(g);
remove("/home/abdou/Projects/finprojet/src/agent.txt");
rename("/home/abdou/Projects/finprojet/src/agent1.txt","/home/abdou/Projects/finprojet/src/agent.txt");
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

void afficher_personne_agent(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

   infoagent agent;
   da naissance;
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
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JOUR, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MOIS, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",ANNEE, NULL); 
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

  f = fopen("/home/abdou/Projects/finprojet/src/agent.txt", "r"); 

  if(f==NULL)
  {
    return;
  }
  else

  { f = fopen("/home/abdou/Projects/finprojet/src/agent.txt", "a+");
       while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",agent.nom, agent.prenom,agent.naissance.jour,agent.naissance.mois,agent.naissance.annee,agent.telephone,agent.cin,agent.adress,
agent.nationalite,agent.identifiant,agent.motdepasse)!= EOF))
    {
 GtkTreeIter iter;
 gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,NOM,agent.nom,PRENOM,agent.prenom,JOUR,agent.naissance.jour,MOIS,agent.naissance.mois,ANNEE,agent.naissance.annee,TELEPHONE,agent.telephone,CIN,agent.cin,ADRESS,agent.adress,NATIONALITE,agent.nationalite,IDENTIFIANT,agent.identifiant,MOTDEPASSE,agent.motdepasse, -1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}





int test_inscrit_agent( infoagent agent)
 { 
   int x,y,z,w,a,b,c,d,e;
   x=strcmp(agent.nom,"");
   y=strcmp(agent.prenom,"");
   z=strcmp(agent.naissance.jour,"");
   w=strcmp(agent.naissance.mois,"");
   a=strcmp(agent.naissance.annee,"");
   b=strcmp(agent.telephone,"");
   c=strcmp(agent.cin,"");
   d=strcmp(agent.identifiant,"");
   e=strcmp(agent.motdepasse,"");
  if ((x==0)||(y==0)||(z==0)||(w==0)||(a==0)||(b==0)||(c==0)||(d==0)||(e==0))
  { return (-1);}
 return (1);
} 


int tab_agent( infoagent t[200])
  { int n=0;
    FILE *g;
    g=fopen("/home/abdou/Projects/finprojet/src/agent.txt","r");
    if (g!=NULL)
  { while (fscanf(g,"%s %s %s %s %s %s %s %s %s %s %s\n",t[n].nom, t[n].prenom, t[n].naissance.jour, t[n].naissance.mois, t[n].naissance.annee, t[n].telephone, t[n].cin, t[n].adress,
t[n].nationalite, t[n].identifiant, t[n].motdepasse)!= EOF)
 {n++;}
fclose(g);}
return n ;}

int controle_identifiant_agent( infoagent tab[200],char identifiant[20])
{ int n=tab_clients(tab);
  int i;
for (i=0; i<n;i++)
if (strcmp(tab[i].identifiant,identifiant)==0)
return i;
return -1;}









