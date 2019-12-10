#include<stdio.h>
#include<string.h>
#include"facture.h"
#include<gtk/gtk.h>
#include<stdlib.h>
enum
{
	NOM,
	PRENOM,
	IDENTIFIANT,
        TYPEDEPAIMENT,
        MONTANTTOTALE,
	COLUMNS
};




void afficher_factures(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char nom [30];
 char prenom[30];
 char identifiant[30];
 char typedepaiment[30];
 char montanttotale[30];

 store=NULL;
 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         
         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("type de paiment", renderer, "text",TYPEDEPAIMENT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("montant totale", renderer, "text",MONTANTTOTALE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING ,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("/home/saif/Projects/project4/src/factures.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else
	
	{ 
	f=fopen("/home/saif/Projects/project4/src/factures.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",nom,prenom,identifiant,typedepaiment,montanttotale)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,IDENTIFIANT,identifiant,TYPEDEPAIMENT,typedepaiment,MONTANTTOTALE,montanttotale,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	
}


void supprimer_factures(char id1[10])
{ 	
	FILE*f ,*s;
    	facture d;
	int i,j;

    	f=fopen("/home/saif/Projects/project4/src/factureagent.txt","a+");
	    s=fopen("/home/saif/Projects/project4/src/factureagent.tmp.txt","a+");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %s %s %s  %s ",d.nom,d.prenom,d.identifiant,d.typedepaiment,d.montanttotale)!=EOF)
			{
    				if(strcmp(d.identifiant,id1)!=0)
    				{	
						fprintf(s,"%s %s %s %s %s  \n",d.nom,d.prenom,d.identifiant,d.typedepaiment,d.montanttotale);
						}
			}
			fclose(f);
			fclose(s);

			remove("/home/saif/Projects/project4/src/factureagent.txt");
			rename("/home/saif/Projects/project4/src/factureagent.tmp.txt","/home/saif/Projects/project4/src/factureagent.txt");
}

 
}



void afficher_factures_a(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char nom [30];
 char prenom[30];
 char identifiant[30];
 char typedepaiment[30];
 char montanttotale[30];

 store=NULL;
 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         
         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("type de paiment", renderer, "text",TYPEDEPAIMENT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("montant totale", renderer, "text",MONTANTTOTALE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING ,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("/home/saif/Projects/project4/src/factureagent.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else
	
	{ 
	f=fopen("/home/saif/Projects/project4/src/factureagent.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",nom,prenom,identifiant,typedepaiment,montanttotale)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,IDENTIFIANT,identifiant,TYPEDEPAIMENT,typedepaiment,MONTANTTOTALE,montanttotale,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	
}


void ajouter_facture_a(facture d)
{

 FILE *f;
 f=fopen("/home/saif/Projects/project4/src/factureagent.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s \n",d.nom,d.prenom,d.identifiant,d.typedepaiment,d.montanttotale);
 fclose(f);
 }

}

void ajouter_facture(facture d)
{

 FILE *f;
 f=fopen("/home/saif/Projects/project4/src/factures.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s \n",d.nom,d.prenom,d.identifiant,d.typedepaiment,d.montanttotale);
 fclose(f);
 }

}



























