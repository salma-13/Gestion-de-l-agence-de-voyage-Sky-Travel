#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vol.h"
#include "hotel.h"
#include "voiture.h"
#include <string.h>

void
on_sa_reserver_h_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infohotel hotel;
date date_h;
char msg[50];
int j,m,a;
char x[5],y[5],z[5];
window1=lookup_widget(objet_graphique,"windowBienvenueclient");
input1=lookup_widget(objet_graphique,"entrycode");
input2=lookup_widget(objet_graphique,"entrynom");
input3=lookup_widget(objet_graphique,"entryville");
jour=lookup_widget(objet_graphique,"spinbutton_j_h");
mois=lookup_widget(objet_graphique,"spinbutton_m_h");
annee=lookup_widget(objet_graphique,"spinbutton_a_h");
input4=lookup_widget(objet_graphique,"entrynuitee");
input5=lookup_widget(objet_graphique,"entrychambre");
output1=lookup_widget(objet_graphique,"res_reussite");

strcpy(hotel.code,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(hotel.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(hotel.ville,gtk_entry_get_text(GTK_ENTRY(input3)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(hotel.date_h.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(hotel.date_h.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(hotel.date_h.annee,z);
strcpy(hotel.nuitee,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(hotel.chambre,gtk_entry_get_text(GTK_ENTRY(input5)));
Ajouter_h(hotel);
strcpy(msg ,"Reservation réussite");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);
}


void
on_sa_affich_h_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
//GtkWidget *windowBienvenueclient;
GtkWidget *affich_res_h;
GtkWidget *treeviewh;

//windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient");
//gtk_widget_destroy(windowBienvenueclient);
affich_res_h=lookup_widget(objet_graphique,"affich_res_h");
affich_res_h=create_affich_res_h();
gtk_widget_show(affich_res_h);

treeviewh=lookup_widget(affich_res_h,"treeviewh");

afficher_h(treeviewh);
}


void
on_sa_res_v_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *input11;
GtkWidget *input22;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infovol vol;
date date_v;
int j,m,a;
char x[5],y[5],z[5];
window2=lookup_widget(objet_graphique,"windowBienvenueclient");
input11=lookup_widget(objet_graphique,"entrynumv");
input22=lookup_widget(objet_graphique,"entrydestination");
jour=lookup_widget(objet_graphique,"spinbutton_j_v");
mois=lookup_widget(objet_graphique,"spinbutton_m_v");
annee=lookup_widget(objet_graphique,"spinbutton_a_v");

strcpy(vol.num,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(vol.destination,gtk_entry_get_text(GTK_ENTRY(input22)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(vol.date_v.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(vol.date_v.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(vol.date_v.annee,z);
Ajouter_v(vol);
}


void
on_sa_afficher_v_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
//GtkWidget *windowBienvenueclient;
GtkWidget *fenetreaffichagevol;
GtkWidget *treeviewvol;

//windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient");
//gtk_widget_destroy(windowBienvenueclient);
fenetreaffichagevol=lookup_widget(objet_graphique,"affich_v");
fenetreaffichagevol=create_affich_v();
gtk_widget_show(fenetreaffichagevol);

treeviewvol=lookup_widget(fenetreaffichagevol,"treeview2");

afficher_v(treeviewvol);
}


void
on_sa_res_vo_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;

GtkWidget *nbre;
//GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infovoiture voiture;
date date_vo;
//char msg[50];
int j,m,a,b;
char x[5],y[5],z[5],w[5];
window1=lookup_widget(objet_graphique,"windowBienvenueclient");
input1=lookup_widget(objet_graphique,"entrycodevo");
input2=lookup_widget(objet_graphique,"entrymarque");
jour=lookup_widget(objet_graphique,"spinbutton_j_vo");
mois=lookup_widget(objet_graphique,"spinbutton_m_vo");
annee=lookup_widget(objet_graphique,"spinbutton_a_vo");
nbre=lookup_widget(objet_graphique,"spinbutton_nbre_j");
//output1=lookup_widget(objet_graphique,"res_reussite");

strcpy(voiture.code,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(voiture.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(voiture.date_vo.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(voiture.date_vo.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(voiture.date_vo.annee,z);
b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nbre));
sprintf(x,"%d\0",b);
strcpy(voiture.nbre,w);
Ajouter_vo(voiture);
/*strcpy(msg ,"Reservation réussite");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);*/
}


void
on_sa_affich_vo_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowBienvenueclient;
GtkWidget *fenetreaffichagevoiture;
GtkWidget *treeviewvoiture;

windowBienvenueclient=lookup_widget(objet_graphique,"windowBienvenueclient");
//gtk_widget_destroy(windowBienvenueclient);
fenetreaffichagevoiture=lookup_widget(objet_graphique,"affich_res_voi");
fenetreaffichagevoiture=create_affich_res_voi();
gtk_widget_show(fenetreaffichagevoiture);

treeviewvoiture=lookup_widget(fenetreaffichagevoiture,"treeview3");

afficher_vo(treeviewvoiture);
}


void
on_sa_supp_h_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;  
GtkWidget *input1;
GtkWidget *output1;

char msg[100];
char codd[50];
window1=lookup_widget(objet_graphique,"affich_res_h");
input1=lookup_widget(objet_graphique,"entrysupph");
output1=lookup_widget(objet_graphique,"supp_reussite");
strcpy(codd,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_h(codd);
strcpy(msg,"suppression reussite");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);
}



void
on_sa_modifier_h_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affich_res_h; 
GtkWidget *fenetremodifierhotel;
GtkWidget *input1; 
char cod[50];
affich_res_h=lookup_widget(objet_graphique,"affich_res_h");
fenetremodifierhotel=lookup_widget(objet_graphique,"modif_res_h");
input1=lookup_widget(objet_graphique,"entrymodifh");
strcpy(cod,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_h(cod);
gtk_widget_hide(window1);
fenetremodifierhotel = create_modif_res_h ();
gtk_widget_show(fenetremodifierhotel);
}



void
on_sa_supp_v_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;  
GtkWidget *input1;
GtkWidget *output1;

char msg[100];
char codd[50];
window1=lookup_widget(objet_graphique,"affich_v");
input1=lookup_widget(objet_graphique,"entrysuppv");
output1=lookup_widget(objet_graphique,"label37");
strcpy(codd,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_v(codd);
strcpy(msg,"suppression reussite");
GdkColor color;
gdk_color_parse ("green",&color);
gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output1), msg);
}


void
on_sa_supp_vo_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;  
GtkWidget *input1;
//GtkWidget *output1;

//char msg[100];
char codd[50];
window1=lookup_widget(objet_graphique,"affich_res_voi");
input1=lookup_widget(objet_graphique,"entry14");
//output1=lookup_widget(objet_graphique,"label36");
strcpy(codd,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_vo(codd);
}


void
on_sa_valider_h_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;

//GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infohotel hotel;
date date_h;
char msg[50];
int j,m,a;
char x[5],y[5],z[5];
window1=lookup_widget(objet_graphique,"modif_res_h");
input1=lookup_widget(objet_graphique,"entrymc");
input2=lookup_widget(objet_graphique,"entrymn");
input3=lookup_widget(objet_graphique,"entrymv");
jour=lookup_widget(objet_graphique,"spinbutton1");
mois=lookup_widget(objet_graphique,"spinbutton2");
annee=lookup_widget(objet_graphique,"spinbutton3");
input4=lookup_widget(objet_graphique,"entrymnui");
input5=lookup_widget(objet_graphique,"entrymch");

//output1=lookup_widget(objet_graphique,"label_fin_modifier_client");
strcpy(hotel.code,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(hotel.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(hotel.ville,gtk_entry_get_text(GTK_ENTRY(input3)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(hotel.date_h.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(hotel.date_h.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(hotel.date_h.annee,z);

Ajouter_h(hotel);
//strcpy(msg ,"modification réussit");
//GdkColor color;
//gdk_color_parse ("green",&color);
//gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
//gtk_label_set_text(GTK_LABEL(output1), msg);
}


void
on_sa_valider_v_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;


//GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
infovol vol;
date date_v;
//char msg[50];
int j,m,a;
char x[5],y[5],z[5];
window1=lookup_widget(objet_graphique,"modif_res_v");
input1=lookup_widget(objet_graphique,"entrymnv");
input2=lookup_widget(objet_graphique,"entrymdv");
jour=lookup_widget(objet_graphique,"spinbutton4");
mois=lookup_widget(objet_graphique,"spinbutton5");
annee=lookup_widget(objet_graphique,"spinbutton6");

//output1=lookup_widget(objet_graphique,"label_fin_modifier_client");
strcpy(vol.num,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(vol.destination,gtk_entry_get_text(GTK_ENTRY(input2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(vol.date_v.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(vol.date_v.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(vol.date_v.annee,z);

Ajouter_v(vol);
//strcpy(msg ,"modification réussit");
//GdkColor color;
//gdk_color_parse ("green",&color);
//gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
//gtk_label_set_text(GTK_LABEL(output1), msg);
}


void
on_sa_modifier_v_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1; 
GtkWidget *fenetremodifiervol;
GtkWidget *input1; 
char cod[50];
window1=lookup_widget(objet_graphique,"affich_v");
fenetremodifiervol=lookup_widget(objet_graphique,"modif_res_v");
input1=lookup_widget(objet_graphique,"entrymodv");
strcpy(cod,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_v(cod);
//gtk_widget_hide(window1);
fenetremodifiervol = create_modif_res_v ();
gtk_widget_show(fenetremodifiervol);
}


void
on_sa_valider_vo_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *input1;
GtkWidget *input2;


//GtkWidget *output1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *nbre;
infovoiture voiture;
date date_vo;
//char msg[50];
int j,m,a,b;
char x[5],y[5],z[5],w[5];
window1=lookup_widget(objet_graphique,"modif_res_voi");
input1=lookup_widget(objet_graphique,"entrymodifcodevo");
input2=lookup_widget(objet_graphique,"entrymodifmarqvo");
jour=lookup_widget(objet_graphique,"spinbutton_mod_j_vo");
mois=lookup_widget(objet_graphique,"spinbutton_mo_m_vo");
annee=lookup_widget(objet_graphique,"spinbutton_mo_a_vo");
nbre=lookup_widget(objet_graphique,"spinbutton_mod_nbre_j");

//output1=lookup_widget(objet_graphique,"label_fin_modifier_client");
strcpy(voiture.code,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(voiture.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
sprintf(x,"%d\0",j);
strcpy(voiture.date_vo.jour,x);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
sprintf(y,"%d\0",m);
strcpy(voiture.date_vo.mois,y);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
sprintf(z,"%d\0",a);
strcpy(voiture.date_vo.annee,z);
b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nbre));
sprintf(w,"%d\0",b);
strcpy(voiture.nbre,x);

Ajouter_vo(voiture);
//strcpy(msg ,"modification réussit");
//GdkColor color;
//gdk_color_parse ("green",&color);
//gtk_widget_modify_fg (output1,GTK_STATE_NORMAL,&color);
//gtk_label_set_text(GTK_LABEL(output1), msg);
}

void
on_sa_modifier_vo_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1; 
GtkWidget *fenetremodifiervoiture;
GtkWidget *input1; 
char cod[50];
window1=lookup_widget(objet_graphique,"affich_res_voi");
fenetremodifiervoiture=lookup_widget(objet_graphique,"modifier_res_vo");
input1=lookup_widget(objet_graphique,"entrymodvo");
strcpy(cod,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_v(cod);
//gtk_widget_hide(window1);
fenetremodifiervoiture = create_modifier_res_vo ();
gtk_widget_show(fenetremodifiervoiture);
}

