
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


typedef struct s_node
{
    int value; // Le coût associé à ce noeud
    int depth; // La profondeur de l'arbre à partir de ce noeud
    t_move mouvement; // Le mouvement qui conduit à ce noeud
    t_soil soil_type; // Le type de sol associé à ce noeud
    struct s_node *sup; // Pointeur vers le noeud sup
    struct s_node **sons; // Pointeur vers un tableau contenant les noeuds fils
    int nbSons; // Le nombre d'éléments dans le tableau
} t_node;

typedef struct s_node t_node, *p_node;//Définition du noeud et du pointeur vers un noeud

typedef struct s_tree
{
    p_node root; //racine de l'arbre
} t_tree;



t_move* remove_move(t_move*, int, int);

p_node createNode(int nb_sons, int depth, t_move mouvement, t_localisation loc, t_map map, p_node node);

p_node create_all_Node(int nb_poss, int depth, t_move mouvement, t_move* possibilities, t_localisation robot, t_map map, p_node sup_node);

t_tree create_tree(int nb_poss, int depth, t_move mouvement, t_move* possibilities, t_localisation robot, t_map map);

int search_min(t_tree);

int search_min_node(p_node node);

int nb_min(t_node *node, int min);

#endif //UNTITLED1_TREE_H
