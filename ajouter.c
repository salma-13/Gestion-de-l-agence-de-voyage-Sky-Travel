#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ajouter.h"
void ag_ajouter_hotel(char nom[],char localisation[],char rate[],char price[],char code[])
{
FILE *f;

f=fopen("/home/alaa/Projects/project9/src/hotel.txt","a+");

fprintf(f,"%s %s %s %s %s \n",nom,localisation,rate,price,code);


fclose(f);

}
void ag_ajouter_vol(char nom[],char depart[],char arrive[],char date[],char prix[],char code[])
{
FILE *f;

f=fopen("/home/alaa/Projects/project9/src/vol.txt","a+");

fprintf(f,"%s %s %s %s %s %s \n",nom,depart,arrive,date,prix,code);


fclose(f);

}

void ag_ajouter_voiture(char marque[],char prix[],char info[],char code[])
{
FILE *f;

f=fopen("/home/alaa/Projects/project9/src/voiture.txt","a+");

fprintf(f,"%s %s %s %s \n",marque,prix,info,code);


fclose(f);

}




void ag_supprimer_hotel(char rcode[20])
{ 
char nom[20];
char localisation[20];
char rate[20];
char price[20];
char code[20];
  FILE *f,*g;
 f=fopen("/home/alaa/Projects/project9/src/hotel.txt","r");
 g=fopen("/home/alaa/Projects/project9/src/thotel.txt","w");

while (fscanf(f,"%s %s %s %s %s \n",nom,localisation,rate,price,code)!=EOF)
   {
   if (!strcmp(rcode,code))
 {continue;}
else {fprintf(g,"%s %s %s %s %s \n",nom,localisation,rate,price,code); 

        }
        }
fclose(f);
fclose(g);

remove("/home/alaa/Projects/project9/src/hotel.txt");

rename("/home/alaa/Projects/project9/src/thotel.txt","/home/alaa/Projects/project9/src/hotel.txt");
}







void ag_supprimer_vol(char rcode[20])
{ 
char nom[20];
char depart[20];
char arrive[20];
char date[20];
char prix[20];
char code[20];
  FILE *f,*g;
 f=fopen("/home/alaa/Projects/project9/src/vol.txt","r");
 g=fopen("/home/alaa/Projects/project9/src/tvol.txt","w");

while (fscanf(f,"%s %s %s %s %s %s \n",nom,depart,arrive,date,prix,code)!=EOF)
   {
   if (!strcmp(rcode,code))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s \n",nom,depart,arrive,date,prix,code); 

        }
        }
fclose(f);
fclose(g);

remove("/home/alaa/Projects/project9/src/vol.txt");

rename("/home/alaa/Projects/project9/src/tvol.txt","/home/alaa/Projects/project9/src/vol.txt");
}






void ag_supprimer_voiture(char rcode[20])
{ 
char marque[20];
char prix[20];
char info[20];
char code[20];
  FILE *f,*g;
 f=fopen("/home/alaa/Projects/project9/src/voiture.txt","r");
 g=fopen("/home/alaa/Projects/project9/src/tvoiture.txt","w");

while (fscanf(f,"%s %s %s %s \n",marque,prix,info,code)!=EOF)
   {
   if (!strcmp(rcode,code))
 {continue;}
else {fprintf(g,"%s %s %s %s \n",marque,prix,info,code); 

        }
        }
fclose(f);
fclose(g);

remove("/home/alaa/Projects/project9/src/voiture.txt");

rename("/home/alaa/Projects/project9/src/tvoiture.txt","/home/alaa/Projects/project9/src/voiture.txt");
}










void ag_modifier_hotel(char rnom[],char rlocalisation[],char rrate[],char rprice[],char rcode[])
{ 
char nom[20];
char localisation[20];
char rate[20];
char price[20];
char code[20];
  FILE *f,*g;
 f=fopen("/home/alaa/Projects/project9/src/hotel.txt","r");
 g=fopen("/home/alaa/Projects/project9/src/thotel.txt","w");

/*el print ta3 el new */
fprintf(g,"%s %s %s %s %s \n",rnom,rlocalisation,rrate,rprice,rcode);

while (fscanf(f,"%s %s %s %s %s \n",nom,localisation,rate,price,code)!=EOF)
   {
   if (!strcmp(rcode,code))
 {continue;}
else {fprintf(g,"%s %s %s %s %s \n",nom,localisation,rate,price,code); 

        }
        }
fclose(f);
fclose(g);

remove("/home/alaa/Projects/project9/src/hotel.txt");

rename("/home/alaa/Projects/project9/src/thotel.txt","/home/alaa/Projects/project9/src/hotel.txt");
}




void ag_modifier_vol(char rnom[],char rdepart[],char rarrive[],char rdate[],char rprix[],char rcode[])
{ 
char nom[20];
char depart[20];
char arrive[20];
char date[20];
char prix[20];
char code[20];
  FILE *f,*g;
 f=fopen("/home/alaa/Projects/project9/src/vol.txt","r");
 g=fopen("/home/alaa/Projects/project9/src/tvol.txt","w");

fprintf(g,"%s %s %s %s %s %s \n",rnom,rdepart,rarrive,rdate,rprix,rcode); 

while (fscanf(f,"%s %s %s %s %s %s \n",nom,depart,arrive,date,prix,code)!=EOF)
   {
   if (!strcmp(rcode,code))
 {continue;}
else {fprintf(g,"%s %s %s %s %s %s \n",nom,depart,arrive,date,prix,code); 

        }
        }
fclose(f);
fclose(g);

remove("/home/alaa/Projects/project9/src/vol.txt");

rename("/home/alaa/Projects/project9/src/tvol.txt","/home/alaa/Projects/project9/src/vol.txt");
}




void ag_modifier_voiture(char rmarque[],char rprix[],char rinfo[],char rcode[])
{ 
char marque[20];
char prix[20];
char info[20];
char code[20];
  FILE *f,*g;
 f=fopen("/home/alaa/Projects/project9/src/voiture.txt","r");
 g=fopen("/home/alaa/Projects/project9/src/tvoiture.txt","w");

fprintf(g,"%s %s %s %s \n",rmarque,rprix,rinfo,rcode); 

while (fscanf(f,"%s %s %s %s \n",marque,prix,info,code)!=EOF)
   {
   if (!strcmp(rcode,code))
 {continue;}
else {fprintf(g,"%s %s %s %s \n",marque,prix,info,code); 

        }
        }
fclose(f);
fclose(g);

remove("/home/alaa/Projects/project9/src/voiture.txt");

rename("/home/alaa/Projects/project9/src/tvoiture.txt","/home/alaa/Projects/project9/src/voiture.txt");
}

/************************/
/***********************/
/*********************/

int ag_test_vide_hotel( char nom[],char localisation[],char rate[],char price[],char code[])
 { 
   int cnom,clocalisation,crate,cprice,ccode;
   cnom=strcmp(nom,"");
   clocalisation=strcmp(localisation,"");
   crate=strcmp(rate,"");
   cprice=strcmp(price,"");
   ccode=strcmp(code,"");
   
  if ((cnom==0)||(clocalisation==0)||(crate==0)||(cprice==0)||(ccode==0))
  { return (-1);}
 return (1);
} 

/*************************************/
int ag_tab_hotel(char tabh[20])
  { int n=0;
   char nom[20];
char localisation[20];
char rate[20];
char price[20];
char code[20];
    FILE *f;
    f=fopen("/home/alaa/Projects/project9/src/hotel.txt","r");
    if (f!=NULL)
  { while (fscanf(f,"%s %s %s %s %s\n",nom, localisation,rate,price,code)!= EOF)
 {n++;
tabh[n]=code; }

fclose(f);}
return n ;}

int ag_cmp_code_hotel( char tabh[200],char code[20])
{ int n=ag_tab_hotel(tabh);
  int i;
for (i=0; i<n;i++)
if (strcmp(tabh[i],code)==0)
return i;
return -1;}








