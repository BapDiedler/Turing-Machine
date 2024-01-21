#include <stdlib.h>
#include <stdio.h>

/*********STRUCTURE************/

/// @brief enumération pour les types possibles
typedef enum Element_type {
    UNIT,   //type inconnu
    INT,    //type entier
    STRING  //type chaine de caractères
} Element_type;

/// @brief structure représnetant les éléments d'un ABR
typedef struct element {
    Element_type type;
    int entier;
    char* chaine;
}* element;


/**********CONSTRUCTEUR*************/

element init_element();
element init_element_int(int entier);
element init_element_string(char* chaine);

int change_int(element e, int entier);
int change_string(element e, char* chaine);
int change_type(element e, Element_type type);


/************AUTRE************/
int compare(element e1, element e2);