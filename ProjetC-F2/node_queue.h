
#ifndef UNTITLED1_NODE_QUEUE_H
#define UNTITLED1_NODE_QUEUE_H
#include "tree.h"

typedef struct s_queue_tab
{
    p_node values[MAX];
    int first, last;
} t_queue_tab;


t_queue_tab createEmptyQueue(); //Initialise une file vide

void enqueue_node(t_queue_tab *, p_node); //Ajoute un noeud à la fin de la liste

p_node dequeue_node(t_queue_tab *); // Retire et retourne un noeud en tête de liste

#endif //UNTITLED1_NODE_QUEUE_H