void ag_ajouter_hotel(char nom[],char localisation[],char rate[],char price[],char code[]);
void ag_ajouter_vol(char nom[], char depart[],char arrive[],char date[],char prix[],char code[]);
void ag_ajouter_voiture(char marque[],char prix[],char info[],char code[]);

void ag_supprimer_hotel(char rcode[]);
void ag_supprimer_vol(char rcode[20]);
void ag_supprimer_voiture(char rcode[20]);

void ag_modifier_hotel(char rnom[],char rlocalisation[],char rrate[],char rprice[],char rcode[]); 
void ag_modifier_vol(char nom[],char rdepart[],char rarrive[],char rdate[],char rprix[],char rcode[]);
void ag_modifier_voiture(char rmarque[],char rprix[],char rinfo[],char rcode[]);




int ag_test_vide_hotel( char nom[],char localisation[],char rate[],char price[],char code[]);
int ag_tab_hotel(char tabh[20]);
int ag_cmp_code_hotel( char tabh[20],char code[20]);
