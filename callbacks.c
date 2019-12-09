#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "authenti.h"
#include "gestionclient.h"
#include "reclamation.h"
#include <string.h>

//mayssa
void
on_buttonDeconnexion_admin_clicked     (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *windowAuthentification;
GtkWidget *windowBienvenueadmin;

windowBienvenueadmin=lookup_widget(objet_graphique,"windowBienvenueadmin");
windowAuthentification=lookup_widget(objet_graphique,"windowAuthentification");

gtk_widget_hide(windowBienvenueadmin);
windowAuthentification = create_windowAuthentification ();
gtk_widget_show(windowAuthentification);
}
//fin mayssa

void
on_button_ajouter_agent_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_afficher_agent_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_supprimer_agent_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_agent_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mayssa 
void
on_button_filtrer_clients_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonModifierclient_clicked        (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *window1; 
GtkWidget *fenetremodifierclients;
GtkWidget *input1; 
char iden[50];
window1=lookup_widget(objet_graphique,"windowBienvenueadmin");
fenetremodifierclients=lookup_widget(objet_graphique,"fenetremodifierclients");
input1=lookup_widget(objet_graphique,"entryRechercheclient");
strcpy(iden,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer(iden);
gtk_widget_hide(window1);
fenetremodifierclients = create_fenetremodifierclients ();
gtk_widget_show(fenetremodifierclients);

}


void
on_buttonSupprimerclient_clicked       (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *window1;  
GtkWidget *input1;
GtkWidget *output1;

char msg[100];
char id[50];
window1=lookup_widget(objet_graphique,"windowBienvenueadmin");
input1=lookup_widget(objet_graphique,"entryRechercheclient");
output1=lookup_widget(objet_graphique,"labelmessageclient");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer(id);
strcpy(msg,"supprime reussit");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);

}


void
on_buttonAfficherclient_clicked        (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *windowBienvenueadmin;
GtkWidget *fenetreaffichageclients;
GtkWidget *treeviewdesclients;

windowBienvenueadmin=lookup_widget(objet_graphique,"windowBienvenueadmin");
gtk_widget_destroy(windowBienvenueadmin);
fenetreaffichageclients=create_fenetreaffichageclients();
gtk_widget_show(fenetreaffichageclients);

treeviewdesclients=lookup_widget(fenetreaffichageclients,"treeviewdesclients");

afficher_personne(treeviewdesclients);

}


void
on_buttonAjouterclient_clicked        (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infoclient client;
date naissance;
infoclient tab[200];
char identifiant[20];
char msg[50];
int j,m,a,p,u;
char x[5],y[5],z[5];
window1=lookup_widget(objet_graphique,"windowBienvenueadmin");
input1=lookup_widget(objet_graphique,"entrynomclient");
input2=lookup_widget(objet_graphique,"entryprenomclient");
jour=lookup_widget(objet_graphique,"spinbuttonjourclient");
mois=lookup_widget(objet_graphique,"spinbuttonmoisclient");
annee=lookup_widget(objet_graphique,"spinbuttonanneeclient");
input4=lookup_widget(objet_graphique,"entrytelephoneclient");
input3=lookup_widget(objet_graphique,"entrycinclient");
input5=lookup_widget(objet_graphique,"entryadressclient");
input6=lookup_widget(objet_graphique,"entrynationnaliteclient");
input7=lookup_widget(objet_graphique,"entryidentifiantclient");
input8=lookup_widget(objet_graphique,"entrymotdepasseclient");
output1=lookup_widget(objet_graphique,"labelmessageclient");
strcpy(client.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(client.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(client.naissance.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(client.naissance.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(client.naissance.annee,z);
strcpy(client.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(client.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(client.adress,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(client.nationalite,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(client.identifiant,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(client.motdepasse,gtk_entry_get_text(GTK_ENTRY(input8)));
p=test_inscrit(client);
u=controle_identifiant(tab,client.identifiant);
if ((p==1)&&(u==-1))
{Ajouter(client);
strcpy(msg ,"Ajout réussit");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);}
else 
{strcpy(msg ,"verifier votre information");
GdkColor color;
gdk_color_parse ("red",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);
}
}



void
on_ani_button_recherche_localisation_hotel_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ani_button_recherche_destination_vol_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_a_button_recherche_marque_voiture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mayssa
void
on_button_connexion_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *window1;
GtkWidget *window2;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output1;

char username[50];
char password[50];
int r;
char erreure[100];
window1=lookup_widget(objet_graphique,"windowAuthentification");
input1=lookup_widget(objet_graphique,"entry_username");
input2=lookup_widget(objet_graphique,"entry_password");
output1=lookup_widget(objet_graphique,"labelerreur");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
r=verifier(username,password);
switch(r)
	{
	case -1:
	{
	strcpy(erreure,"Username or Password ERROR !!");
	GdkColor color;
	gdk_color_parse ("red",&color);
	gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(output1), erreure);
	break;
	}
	case 1:
	{
	window2=create_windowBienvenueadmin();
	gtk_widget_hide (window1);
	gtk_widget_show (window2);
	break;
	}
	case 2:
	{
	window2=create_windowBienvenueagent();
	gtk_widget_hide (window1);
	gtk_widget_show (window2);
	break;
	}
	case 3:
	{
	window2=create_windowBienvenueclient();
	gtk_widget_hide (window1);
	gtk_widget_show (window2);
	break;
	}
}


}

// fin mayssa
void
on_button_inscri_enregistrer_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ac_button_recherche_localisation_hotel_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_affich_h_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_reserver_h_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ac_button_recherche_destination_vol_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_reserver_v_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_affich_v_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ac_button_recherche_marque_voiture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_reserver_vo_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_affich_vo_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}

//ahmed
void
on_ah_ajouter_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char ch[20];
reclamation r;
GtkWidget *num_rec, *type_rec, *code_rec, *rec, *output;
GtkWidget *windowBienvenueclient;
int x,u;reclamation tab[200];
            
windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient"); 
num_rec=lookup_widget(objet_graphique,"num_rec");
type_rec=lookup_widget(objet_graphique,"type_rec");
code_rec=lookup_widget(objet_graphique,"code_rec");
rec=lookup_widget(objet_graphique,"rec");
output=lookup_widget(objet_graphique,"ah_label1");

strcpy(ch,gtk_entry_get_text(GTK_ENTRY(num_rec)));
printf("test 1\n");
sscanf(ch,"%d",&(r.num_rec));

printf("test 2 %d\n",r.num_rec);
strcpy(r.type_rec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_rec)));

printf("test 3 %s\n",r.type_rec);
strcpy(r.code_rec,gtk_entry_get_text(GTK_ENTRY(code_rec)));
printf("test 4 %s\n",r.code_rec);
strcpy(r.rec,gtk_entry_get_text(GTK_ENTRY(rec)));
printf("test 5 %s\n",r.rec);

x=ah_test_reclamation(r,ch);
u=ah_Recherche_par_code (tab,r.code_rec);
if((x==1)&&(u==-1))
{ah_ajouter(r);
gtk_label_set_text(GTK_LABEL(output),"succes");}
else 
gtk_label_set_text(GTK_LABEL(output),"verifier votre information");

}


void
on_ah_afficher_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueclient,*ah_window1,*ah_treeview1;
windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient");
gtk_widget_destroy(windowBienvenueclient);
ah_window1=lookup_widget(objet_graphique,"ah_window1");
ah_window1=create_ah_window1();
gtk_widget_show(ah_window1);
ah_treeview1=lookup_widget(ah_window1,"ah_treeview1");
ah_afficher (ah_treeview1);

}


void
on_ah_modifier_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char ch[20];
reclamation r;
GtkWidget *num_rec, *type_rec, *code_rec, *rec, *output;
GtkWidget *windowBienvenueclient;
reclamation tab[200];int i,h,x,u;

            
windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient"); 
num_rec=lookup_widget(objet_graphique,"num_rec");
type_rec=lookup_widget(objet_graphique,"type_rec");
code_rec=lookup_widget(objet_graphique,"code_rec");
rec=lookup_widget(objet_graphique,"rec");
output=lookup_widget(objet_graphique,"ah_label1");

strcpy(ch,gtk_entry_get_text(GTK_ENTRY(num_rec)));
printf("test 1\n");
sscanf(ch,"%d",&(r.num_rec));
printf("test 2 %d\n",r.num_rec);
strcpy(r.type_rec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_rec)));

printf("test 3 %s\n",r.type_rec);
strcpy(r.code_rec,gtk_entry_get_text(GTK_ENTRY(code_rec)));
printf("test 4 %s\n",r.code_rec);
strcpy(r.rec,gtk_entry_get_text(GTK_ENTRY(rec)));
printf("test 5 %s\n",r.rec);

u=ah_Recherche_par_code (tab,r.code_rec);

x=ah_test_reclamation(r,ch);

if((x==1)&&(u!=-1))
{ah_modifier(tab,r);
gtk_label_set_text(GTK_LABEL(output),"succes");}
else 
gtk_label_set_text(GTK_LABEL(output),("verifier votre information"));

}


void
on_ah_supprimer_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget   *code_rec, *output;
GtkWidget *windowBienvenueclient;
reclamation tab[200];int u;
reclamation r;
windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient"); 
code_rec=lookup_widget(objet_graphique,"code_rec");
output=lookup_widget(objet_graphique,"ah_label1");


strcpy(r.code_rec,gtk_entry_get_text(GTK_ENTRY(code_rec)));
printf("test 1 %s\n",r.code_rec);

u=ah_Recherche_par_code(tab,r.code_rec);
if(u!=-1)
{supprimerah(tab,r);
gtk_label_set_text(GTK_LABEL(output),"succes");}
else 
gtk_label_set_text(GTK_LABEL(output),("verifier votre information"));

}


void
on_ah_afficher3_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueclient,*ah_affich_reponse_client,*ah_treeview3;
windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient");
gtk_widget_destroy(windowBienvenueclient);
ah_affich_reponse_client=lookup_widget(objet_graphique,"ah_affich_reponse_client");
ah_affich_reponse_client=create_ah_affich_reponse_client();
gtk_widget_show(ah_affich_reponse_client);
ah_treeview3=lookup_widget(ah_affich_reponse_client,"ah_treeview3");
affich_reponse_client(ah_treeview3);

}
//fin ahmed
//mayssa
void
on_buttonDeconnexion_client_clicked    (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *windowAuthentification;
GtkWidget *windowBienvenueclient;

windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient");
windowAuthentification=lookup_widget(objet_graphique,"windowAuthentification");

gtk_widget_hide(windowBienvenueclient);
windowAuthentification = create_windowAuthentification ();
gtk_widget_show(windowAuthentification);

}


void
on_buttonDeconnexion_agent_clicked    (GtkWidget *objet_graphique, gpointer user_data)
{


GtkWidget *windowAuthentification;
GtkWidget *windowBienvenueagent;

windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent");
windowAuthentification=lookup_widget(objet_graphique,"windowAuthentification");

gtk_widget_hide(windowBienvenueagent);
windowAuthentification = create_windowAuthentification ();
gtk_widget_show(windowAuthentification);

}
//fin mayssa

void
on_ag_button_recherche_code_hotel_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_modifier_hotel_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_supprimer_hotel_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_ajouter_hotel_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_ajouter_vol_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_modifier_vol_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_supprimer_vo_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_recherche_code_vol_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_supprimer_voiture_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_modifier_voiture_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_ajout_voiture_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ag_button_recherche_voiture_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}

//ahmed
void
on_ah_envoyer_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{reponse r;
GtkWidget  *code_rep, *rep, *output;
GtkWidget *windowBienvenueagent;
int x,u;reclamation tab[200];
            
windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent"); 
code_rep=lookup_widget(objet_graphique,"code_rep");
rep=lookup_widget(objet_graphique,"rep");
output=lookup_widget(objet_graphique,"ah_label2");


strcpy(r.code_rep,gtk_entry_get_text(GTK_ENTRY(code_rep)));
printf("test 1 %s\n",r.code_rep);
strcpy(r.rep,gtk_entry_get_text(GTK_ENTRY(rep)));
printf("test 2 %s\n",r.rep);
x=ah_test_reclamation1(r);
u=ah_Recherche_par_code1 (tab,r.code_rep);
if((x==1)&&(u!=-1))
{ah_ajouter1(r);
gtk_label_set_text(GTK_LABEL(output),"succes");}
else 
gtk_label_set_text(GTK_LABEL(output),"verifier votre information");


}


void
on_ah_afficher1_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueagent,*ah_window2,*ah_treeview2;
windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent");
gtk_widget_destroy(windowBienvenueagent);
ah_window2=lookup_widget(objet_graphique,"ah_window2");
ah_window2=create_ah_window2();
gtk_widget_show(ah_window2);
ah_treeview2=lookup_widget(ah_window2,"ah_treeview2");
ah_afficher (ah_treeview2);

}


void
on_ah_afficher2_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueagent,*ah_affich_reponse,*ah_treeview4;
windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent");
gtk_widget_destroy(windowBienvenueagent);
ah_affich_reponse=lookup_widget(objet_graphique,"ah_affich_reponse");
ah_affich_reponse=create_ah_affich_reponse();
gtk_widget_show(ah_affich_reponse);
ah_treeview4=lookup_widget(ah_affich_reponse,"ah_treeview4");
affich_reponse_client(ah_treeview4);

}


void
on_ah_afficher_par_type_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char type_rec[20]; GtkWidget *windowBienvenueagent,*ah_filtrage_par_type,*ah_treeview5;
GtkWidget *ah_combo;

ah_combo=lookup_widget(objet_graphique,"ah_combo");
strcpy(type_rec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ah_combo)));

windowBienvenueagent=lookup_widget(objet_graphique,"windowBienvenueagent");
gtk_widget_destroy(windowBienvenueagent);
ah_filtrage_par_type=lookup_widget(objet_graphique,"ah_filtrage_par_type");
ah_filtrage_par_type=create_ah_filtrage_par_type();
gtk_widget_show(ah_filtrage_par_type);
ah_treeview5=lookup_widget(ah_filtrage_par_type,"ah_treeview5");
ah_afficher_par_type(ah_treeview5,type_rec);


}
//fin ahmed
// mayssa
void
on_buttonRetournerclient_clicked       (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *fenetreaffichageclients;
GtkWidget *windowBienvenueadmin;

fenetreaffichageclients=lookup_widget(objet_graphique,"fenetreaffichageclients");
windowBienvenueadmin=lookup_widget(objet_graphique,"windowBienvenueadmin");

gtk_widget_hide(fenetreaffichageclients);
windowBienvenueadmin = create_windowBienvenueadmin ();
gtk_widget_show(windowBienvenueadmin);

}


void
on_buttonRetourmodif_client_clicked   (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *fenetremodifierclients;
GtkWidget *windowBienvenueadmin;

fenetremodifierclients=lookup_widget(objet_graphique,"fenetremodifierclients");
windowBienvenueadmin=lookup_widget(objet_graphique,"windowBienvenueadmin");

gtk_widget_hide(fenetremodifierclients);
windowBienvenueadmin = create_windowBienvenueadmin ();
gtk_widget_show(windowBienvenueadmin);
}


void
on_buttonValiderclient_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{

GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infoclient client;
date naissance;
infoclient tab[200];
char msg[50];
int j,m,a,u,p;
char x[5],y[5],z[5];
window1=lookup_widget(objet_graphique,"fenetremodifierclients");
input1=lookup_widget(objet_graphique,"entrynomclientmodif");
input2=lookup_widget(objet_graphique,"entryprenomclientmodif");
jour=lookup_widget(objet_graphique,"spinbuttonjour_c_modif");
mois=lookup_widget(objet_graphique,"spinbuttonmois_c_modif");
annee=lookup_widget(objet_graphique,"spinbuttonannee_c_modif");
input4=lookup_widget(objet_graphique,"entrytelephoneclientmodif");
input3=lookup_widget(objet_graphique,"entrycinclientmodif");
input5=lookup_widget(objet_graphique,"entryadressclientmodif");
input6=lookup_widget(objet_graphique,"entrynationaliteclientmodif");
input7=lookup_widget(objet_graphique,"entryidentifiantclientmodif");
input8=lookup_widget(objet_graphique,"entrymotdepasseclientmodif");
output1=lookup_widget(objet_graphique,"label_fin_modifier_client");
strcpy(client.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(client.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(client.naissance.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(client.naissance.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(client.naissance.annee,z);
strcpy(client.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(client.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(client.adress,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(client.nationalite,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(client.identifiant,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(client.motdepasse,gtk_entry_get_text(GTK_ENTRY(input8)));
p=test_inscrit(client);
u=controle_identifiant(tab,client.identifiant);
if ((p==1)&&(u==-1))
{Ajouter(client);
strcpy(msg ,"Ajout réussit");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);}
else 
{strcpy(msg ,"verifier votre information");
GdkColor color;
gdk_color_parse ("red",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);
}

}
// fin mayssa

//ahmed
void
on_ah_retour_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueclient,*ah_window1;
ah_window1=lookup_widget(objet_graphique,"ah_window1");
gtk_widget_destroy(ah_window1);
windowBienvenueclient=create_windowBienvenueclient ();
gtk_widget_show(windowBienvenueclient);

}


void
on_ah_retour1_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueagent,*ah_window2;
ah_window2=lookup_widget(objet_graphique,"ah_window2");
gtk_widget_destroy(ah_window2);
windowBienvenueagent=create_windowBienvenueagent ();
gtk_widget_show(windowBienvenueagent);

}

//fin ahmed
void
on_sa_modifier_h_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_supp_h_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_supp_v_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_modifier_v_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_supp_vo_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_modifier_vo_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retour_agent_affiche_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retour_agent_modif_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_modif_agent_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}

//ahmed
void
on_ah_retour2_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueclient,*ah_affich_reponse_client;
ah_affich_reponse_client=lookup_widget(objet_graphique,"ah_affich_reponse_client");
gtk_widget_destroy(ah_affich_reponse_client);
windowBienvenueclient=create_windowBienvenueclient ();
gtk_widget_show(windowBienvenueclient);

}


void
on_ah_retour3_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueagent,*ah_affich_reponse;
ah_affich_reponse=lookup_widget(objet_graphique,"ah_affich_reponse");
gtk_widget_destroy(ah_affich_reponse);
windowBienvenueagent=create_windowBienvenueagent ();
gtk_widget_show(windowBienvenueagent);


}

//fin ahmed
void
on_ani_button_retour_cdh_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ani_button_retour_cdv_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ani_button_retour_cmv_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retourne_mayssa_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_valider_h_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_valider_v_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sa_valider_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}

//ahmed
void
on_ah_retour4_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowBienvenueagent,*ah_filtrage_par_type;
ah_filtrage_par_type=lookup_widget(objet_graphique,"ah_filtrage_par_type");
gtk_widget_destroy(ah_filtrage_par_type);
windowBienvenueagent=create_windowBienvenueagent ();
gtk_widget_show(windowBienvenueagent);

}
//fin ahmed

