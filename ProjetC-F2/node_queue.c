
#include "node_queue.h"

t_queue_tab createEmptyQueue() //Initialise une file vide (FIFO) et return une file vide de type t_queue_tab
{
    t_queue_tab q;
    q.first = q.last = 0; //Initialise la file à vide, first & last valent 0
    return q;
}


void enqueue_node(t_queue_tab *pq, p_node val) // Ajoute un nouveau noeud à la fin de la file d'attente
{
    int pos;
    pos = pq->last % MAX;   //Calcule l'index du tableau pour ajouter le nouveau noeud
    pq->values[pos] = val; //Insère le noeud à l'index calculé dans le tableau
    pq->last = pq->last + 1; //Incrémente last après l'ajout
}


p_node dequeue_node(t_queue_tab *pq)
{
    p_node res;
    int pos = pq->first % MAX; //Calcul de l'index du tableau pour retirer le noeud
    res = pq->values[pos]; //Retire le noeud à cette position
    pq->first = pq->first + 1; //Incrémente first après l'ajout
    return res;
}