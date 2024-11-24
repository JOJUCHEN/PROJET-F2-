//
// Created by safia on 20/10/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "map.h"
#include "moves.h"

#define NB_possibilities 9
#define NB_choices 5
#define MAX 18730

/**
* `@brief` struct pour représenter un noeud dans l'arbre
*/
typedef struct s_node
{
    int value;                    //coût associé à ce noeud
    int depth;                    //profondeur de l'arbre à partir de ce noeud
    t_move mouvement;             //mouvement qui conduit à ce noeud
    t_soil soil_type;             //type de sol associé à ce noeud
    struct s_node *sup;           //pointeur vers le noeud supérieur
    struct s_node **sons;         //pointeur vers un tableau contenant les noeuds fils
    int nbSons;                   //nb d'éléments dans le tableau des fils
} t_node;

/**
* `@brief` def du noeud et du pointeur vers un noeud
*/
typedef struct s_node t_node, *p_node;

/**
* `@brief` struct pour représenter un arbre.
*/
typedef struct s_tree
{
    p_node root;  //racine de l'arbre
} t_tree;

/**
* `@brief` retire un mouvement de la liste des mouvements
* 
* @param moves tab des mouvements
* @param index indice du mouvement à retirer
* @param size taille du tableau des mouvements
* @return tab des mouvements mis à jour
*/
t_move* rmMove(t_move* moves, int index, int size);

/**
* `@brief` créer un noeud
* 
* @param nb_sons nb de fils du noeud
* @param depth profondeur du noeud
* @param mouvement pouvement conduisant à ce noeud
* @param loc pocalisation associée
* @param map parte associée
* @param node pointeur vers le noeud supérieur
* @return pointeur vers le noeud créé
*/
p_node createNode(int nb_sons, int depth, t_move mouvement, t_localisation loc, t_map map, p_node node);

/**
* `@brief` créer tous les noeuds possibles
* 
* @param nb_poss nb de possibilités
* @param depth profondeur des noeuds
* @param mouvement mouvement conduisant aux noeuds
* @param possibilities tab des mouvements possibles
* @param robot localisation du robot
* @param map carte associée
* @param sup_node pointeur vers le noeud supérieur
* @return pointeur vers les noeuds créés
*/
p_node createAllNode(int nb_poss, int depth, t_move mouvement, t_move* possibilities, t_localisation robot, t_map map, p_node sup_node);

/**
* `@brief` créer un arbre complet
* 
* @param nb_poss nb de possibilités
* @param depth profondeur de l'arbre
* @param mouvement mouvement conduisant à l'arbre
* @param possibilities tab des mouvements possibles
* @param robot localisation du robot
* @param map carte associée
* @return struct de l'arbre créée
*/
t_tree createTree(int nb_poss, int depth, t_move mouvement, t_move* possibilities, t_localisation robot, t_map map);

/**
* `@brief` cherche la valeur min dans l'arbre
* 
* @param tree arbre dans lequel chercher
* @return val min trouvée
*/
int searchMin(t_tree tree);

/**
* `@brief` cherche la val min dans un noeud
* 
* @param node noeud dans lequel chercher
* @return val min trouvée
*/
int searchMinNode(p_node node);

/**
* `@brief` compte le nombre de noeuds avec une val min
* 
* @param node pointeur vers le noeud
* @param min val min à chercher
* @return nb de noeuds avec la val min
*/
int nbNodeMin(t_node *node, int min);

#endif //UNTITLED1_TREE_H