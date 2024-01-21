#include <stdlib.h>
#include <stdio.h>

/// @brief structure de données représentant les abr
typedef struct node {
    int             hauteur;    //hauteur du node
    char            val;        //valeur du node
    struct node*    fg;         //sous abr gauche
    struct node*    fd;         //sous abr droit
}node, * abr;

/*********CONSTRUCTEUR**********/

/// @brief  initialisation d'un nouvel abr
/// @return le nouvel abr
abr init_abr();

/// @brief      permet de faire une rotation gauche
/// @param tree arbre à transformer
void rotation_gauche(abr* tree);

/// @brief      permet de faire une rotation droite
/// @param tree arbre à transformer
void rotation_droite(abr* tree);

/// @brief      construction d'un nouvel abr
/// @param val  valeur du nouvel abr
/// @param fg   fils gauche de l'abr
/// @param fd   fils droit de l'abr
/// @return     le nouvel abr
abr cons_abr(char val, abr fg, abr fd);

/// @brief      ajoute des valeur dans un abr
/// @param tree abr à transformer
/// @param val  valeur à ajouter
void ajouter(abr* tree, char val);

/// @brief      change la valeur de l'abr
/// @param tree abr transformé
/// @param val  nouvelle valeur
void change_valeur(abr* tree, char val);

/// @brief      met à jour la hauteur d'un abr
/// @param tree arbre à transformer
void change_hauteur(abr* tree);

/// @brief      changement du fils gauche
/// @param tree abr transformé
/// @param fg   nouveau fils gauche
void change_fg(abr* tree, abr fg);

/// @brief      changement du fils droit
/// @param tree abr transformé
/// @param fd   nouveau fils droit
void change_fd(abr* tree, abr fd);

/// @brief      libère l'espace de l'abr
/// @param tree abr que l'on libère
void libre_abr(abr* tree);


/*********AUTRE**********/

/// @brief      affichage préfixe d'un abr
/// @param tree abr à afficher
void print_pre_abr(abr tree);

/// @brief      affichage infixe d'un abr
/// @param tree abr à afficher
void print_inf_abr(abr tree);

/// @brief      affichage subfixe d'un abr
/// @param tree abr à afficher
void print_sub_abr(abr tree);

/// @brief      permet de savoir si l'abre est vide
/// @param tree abr à vérifier
/// @return     0 si non vide autre sinon
int est_vide(abr tree);