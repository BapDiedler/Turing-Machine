/**
 * Le fichier contient une implémentation d'AVL.
*/

#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"

avl init_avl(){
    return NULL;
}

void rotation_gauche(avl* tree){

}

void rotation_droite(avl* tree){

}

avl cons_avl(char val, avl fg, avl fd){
    avl tree = (avl)malloc(sizeof(node));
    tree->fd = fd;
    tree->fg = fg;
    tree->val = val;
    tree->hauteur = fg->hauteur > fd->hauteur ? fg->hauteur+1 : fd->hauteur;+1
    return tree;
}

void ajouter(avl* tree, char val){
    if(est_vide(*tree))
        *tree = cons_avl(val,NULL,NULL);
    else{
        if(val > (*tree)->val){
            
        }else{

        }
    }
}

void change_valeur(avl* tree, char val){
    (*tree)->val = val;
}

void change_fg(avl* tree, avl fg){
    (*tree)->fg = fg;
}

void change_fd(avl* tree, avl fd){
    (*tree)->fd = fd;
}

void libre_avl(avl* tree){
    if(*tree != NULL){
        libre_avl(&(*tree)->fg);
        libre_avl(&(*tree)->fg);
    }
    free(*tree);
}

void print_pre_avl(avl tree){
    if(tree == NULL)
        printf("NULL");
    else{
        for(int i=0; i<tree->hauteur;i++)
            printf("----");
        printf("val:%c/hau:%d\n",tree->val,tree->hauteur);
        print_pre_avl(tree->fg);
        print_pre_avl(tree->fd);
    }
}

void print_inf_avl(avl tree){
    if(tree == NULL)
        printf("NULL");
    else{
        print_inf_avl(tree->fg);
        for(int i=0; i<tree->hauteur;i++)
            printf("----");
        printf("val:%c/hau:%d\n",tree->val,tree->hauteur);
        print_inf_avl(tree->fd);
    }
}

void print_sub_avl(avl tree){
    if(tree == NULL)
        printf("NULL");
    else{
        print_sub_avl(tree->fg);
        print_sub_avl(tree->fd);
        for(int i=0; i<tree->hauteur;i++)
            printf("----");
        printf("val:%c/hau:%d\n",tree->val,tree->hauteur);
    }
}

int est_vide(avl tree){
    return tree == NULL;
}