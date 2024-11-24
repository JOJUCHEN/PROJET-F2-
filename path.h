//
// Created by clement on 20/10/2024.
//
#ifndef UNTITLED1_PATH_H
#define UNTITLED1_PATH_H

#include "nodequeue.h"

/**
* `@brief` trouve toutes les feuilles ayant la val min dans un noeud
* 
* @param node noeud où chercher les feuilles
* @param len pointeur vers une var qui stockera la longueur du tableau des res
* @return tab de pointeurs vers les feuilles trouvées
*/
p_node* tabLeafMin(p_node node, int* len);

/**
* `@brief` trouve la feuille avec le coût total le plus optimal pour atteindre cette feuille depuis la position de MARC dans un arbre
* 
* @param t arbre dans lequel chercher la feuille optimale
* @return pointeur vers la feuille optimale trouvée
*/
p_node minLeaf(t_tree t);

/**
* `@brief` trouve la feuille avec le coût total le plus optimal pour atteindre cette feuille depuis la position de MARC à partir d'un noeud
* 
* @param node noeud où commencer la recherche
* @return pointeur vers la feuille optimale trouvée
*/
p_node minLeafNode(p_node node);

/**
* `@brief` trouve le meilleur chemin (mvts à faire) pour atteindre la feuille de coût minimal
* 
* @param t arbre dans lequel chercher le meilleur chemin
* @param len pointeur vers une variable qui stockera la longueur du tableau des mouvements
* @return tab de mouvements représentant le meilleur chemin
*/
t_move* bestPath(t_tree t, int *len);

#endif //UNTITLED1_PATH_H