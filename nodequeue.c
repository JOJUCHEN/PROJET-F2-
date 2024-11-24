//
// Created by CHEN on 20/10/2024.
//
#include "nodequeue.h"

t_queue_tab createEmptyQueue() //Initialise une file vide
{
    t_queue_tab q;
    q.first = q.last = 0;
    return q;
}


void enqueueNode(t_queue_tab *queue, p_node node) // Ajoute un nouveau noeud à la fin de la file d'attente
{
    int pos;
    pos = queue->last % MAX;   //Calcule l'index du tableau pour ajouter le nouveau noeud
    queue->values[pos] = node; //Insère le noeud à l'index calculé dans le tableau
    queue->last = queue->last + 1; //Incrémente last après l'ajout
}


p_node dequeueNode(t_queue_tab *queue)
{
    p_node res;
    int pos = queue->first % MAX; //Calcul de l'index du tableau pour retirer le noeud
    res = queue->values[pos]; //Retire le noeud à cette position
    queue->first = queue->first + 1; //Incrémente first après l'ajout
    return res;
}