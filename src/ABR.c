/**
 * Le fichier contient une implémentation d'ABR.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ABR.h>

abr init_abr(){
    return NULL;
}

abr cons_abr(char val, abr fg, abr fd){
    abr tree = (abr)malloc(sizeof(node));
    tree->fd = fd;
    tree->fg = fg;
    tree->val = val;
    if(est_vide(fg) && est_vide(fd))
        tree->hauteur = 0;
    else{
        tree->hauteur = fg->hauteur > fd->hauteur ? fg->hauteur+1 : fd->hauteur+1;
    }
    return tree;
}

void ajouter(abr* tree, char val){
    if(est_vide(*tree))
        *tree = cons_abr(val,NULL,NULL);
    else{
        if(val > (*tree)->val){
            ajouter(&(*tree)->fd,val);
            change_hauteur(*tree);
        }else{
            ajouter(&(*tree)->fg,val);
            change_hauteur(*tree);
        }
    }
}

void change_valeur(abr* tree, char val){
    (*tree)->val = val;
}

void change_hauteur(abr* tree){
    if(!est_vide(*tree)){
        if(est_vide((*tree)->fg) && est_vide((*tree)->fd))
            (*tree)->hauteur = 0;
        else{
            (*tree)->hauteur = (*tree)->fg->hauteur > (*tree)->fd->hauteur ? (*tree)->fg->hauteur+1 : (*tree)->fd->hauteur+1;
        }
    }

}

void change_fg(abr* tree, abr fg){
    (*tree)->fg = fg;
}

void change_fd(abr* tree, abr fd){
    (*tree)->fd = fd;
}

void libre_abr(abr* tree){
    if(*tree != NULL){
        libre_abr(&(*tree)->fg);
        libre_abr(&(*tree)->fg);
    }
    free(*tree);
}

void print_pre_abr(abr tree){
    if(tree == NULL)
        printf("NULL");
    else{
        for(int i=0; i<tree->hauteur;i++)
            printf("----");
        printf("val:%c/hau:%d\n",tree->val,tree->hauteur);
        print_pre_abr(tree->fg);
        print_pre_abr(tree->fd);
    }
}

void print_inf_abr(abr tree){
    if(tree == NULL)
        printf("NULL");
    else{
        print_inf_abr(tree->fg);
        for(int i=0; i<tree->hauteur;i++)
            printf("----");
        printf("val:%c/hau:%d\n",tree->val,tree->hauteur);
        print_inf_abr(tree->fd);
    }
}

void print_sub_abr(abr tree){
    if(tree == NULL)
        printf("NULL");
    else{
        print_sub_abr(tree->fg);
        print_sub_abr(tree->fd);
        for(int i=0; i<tree->hauteur;i++)
            printf("----");
        printf("val:%c/hau:%d\n",tree->val,tree->hauteur);
    }
}

int est_vide(abr tree){
    return tree == NULL;
}