#ifndef UNTITLED1_NODEQUEUE_H
#define UNTITLED1_NODEQUEUE_H

#include "tree.h"

/**
 * @brief struct pour représenter une file de noeuds
 */
typedef struct s_queue_tab
{
    p_node values[MAX]; //tableau de pointeurs vers les noeuds
    int first;          //indice du premier élément de la file
    int last;           //indice du dernier élément de la file
} t_queue_tab;

/**
 * @brief initialise une file vide.
 * 
 * @return t_queue_tab, une file vide initialisee
 */
t_queue_tab createEmptyQueue();

/**
 * @brief ajoute un noeud à la fin de la file
 * 
 * @param queue pointeur vers la file où le noeud sera ajouté
 * @param node pointeur vers le noeud à ajouter à la file
 */
void enqueueNode(t_queue_tab *queue, p_node node);

/**
 * @brief retire et retourne un noeud en tête de file
 * 
 * @param queue pointeur vers la file de laquelle le noeud sera retiré
 * @return p_node, pointeur vers le noeud retiré de la file
 */
p_node dequeueNode(t_queue_tab *queue);

#endif //UNTITLED1_NODEQUEUE_H