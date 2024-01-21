#include <stdlib.h>
#include <stdio.h>
#include <element.h>

element init_element(){
    element e = (element)malloc(sizeof(struct element));
    e->chaine = NULL;
    e->entier = 0;
    e->type = UNIT;
    return e;
}

element init_element_int(int entier){
    element e = init_element();
    e->entier = entier;
    e->type = INT;
    return e;
}

element init_element_string(char* chaine){
    element e = init_element();
    e->chaine = chaine;
    e->type = STRING;
    return e;
}

int change_int(element e, int entier){
    if(e->type == INT){
        e->entier = entier;
        return 0;
    }else
        return -1;
}

int change_string(element e, char* chaine){
    if(e->type == STRING){
        free(e->chaine);
        e->chaine = chaine;
        return 0;
    }else
        return -1;
}

int change_type(element e, Element_type type){
    e->type = type;
    e->chaine = NULL;
    e->entier = 0;
    return 0;
}

int compare(element e1, element e2){
    if((e1->type != e2->type) || e1->type == UNIT)
        return -1;
    else{
        if(e1->type == INT)
            return e1->entier == e2->entier;
        else{
            if(e1->chaine == NULL || e2->chaine == NULL)
                return -1;
            else{
                for(int i=0; e1->chaine[i]!='\0' && e2->chaine[i]!='\0';i++){
                    if(e1->chaine[i] != e2->chaine[i])
                        return -1;
                }
                return 1;
            }
        }
    }
}