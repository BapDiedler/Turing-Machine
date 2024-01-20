#include <stdlib.h>

#ifndef AVL_H


/// @brief structure de données représentant les avl
typedef struct node {
    int     hauteur;    //hauteur du node
    char    val;        //valeur du node
    node*   fg;         //sous avl gauche
    node*   fd;         //sous avl droit
}node, * avl;

/*********CONSTRUCTEUR**********/

/// @brief  initialisation d'un nouvel avl
/// @return le nouvel avl
avl init_avl();

/// @brief      construction d'un nouvel avl
/// @param val  valeur du nouvel avl
/// @param fg   fils gauche de l'avl
/// @param fd   fils droit de l'avl
/// @return     le nouvel avl
avl cons_avl(char val, avl fg, avl fd);

/// @brief      change la valeur de l'avl
/// @param tree avl transformé
/// @param val  nouvelle valeur
void change_valeur(avl* tree, char val);

/// @brief      changement du fils gauche
/// @param tree avl transformé
/// @param fg   nouveau fils gauche
void change_fg(avl* tree, avl fg);

/// @brief      changement du fils droit
/// @param tree avl transformé
/// @param fd   nouveau fils droit
void change_fd(avl* tree, avl fd);

/// @brief      libère l'espace de l'avl
/// @param tree avl que l'on libère
void libre_avl(avl* tree);


/*********AUTRE**********/

/// @brief      affichage préfixe d'un avl
/// @param tree avl à afficher
void print_pre_avl(avl tree);

/// @brief      affichage infixe d'un avl
/// @param tree avl à afficher
void print_inf_avl(avl tree);

/// @brief      affichage subfixe d'un avl
/// @param tree avl à afficher
void print_sub_avl(avl tree);



#endif AVL_H