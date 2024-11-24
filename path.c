
#include "path.h"

p_node* tabLeafMin(p_node node, int* len){

    int min_val = searchMinNode(node); //Cherche la val min dans l'arbre
    p_node* min_leaf = (p_node*) malloc(MAX * sizeof(p_node));//Tableau où stocker les feuilles de val min

    t_queue_tab q;
    p_node cur;
    q = createEmptyQueue();
    enqueueNode(&q, node);

    while (q.first != q.last){
        cur = dequeueNode(&q);

        if(cur->value == min_val){
            int depth_of_min = cur->depth;

            while (cur->depth == depth_of_min && q.first != q.last){

                if(cur->value == min_val){
                    min_leaf[(*len)++] = cur; //Ajoute cur dans le tableau de feuille de val min
                }
                cur = dequeueNode(&q); //Passe au noeud suivant
            }
            return min_leaf;
        }
        else if (cur->nbSons != 0){
            for (int i = 0; i < cur->nbSons; i++) {
                if (cur->sons[i] != NULL){
                    enqueueNode(&q, cur->sons[i]);
                }
            }
        }
    }
    return NULL;
}

p_node minLeaf(t_tree t) {
    return minLeafNode(t.root);
}


p_node minLeafNode(p_node node){
    int len = 0, cost = 0, cheaper = 10000, idx;
    p_node* tab_min = tabLeafMin(node, &len); //Prend toutes les feuilles de val min

    for (int i = 0; i < len; i++){
        p_node cur = tab_min[i];
        while (cur != NULL) {
            cost += cur->value; //Additionne la val du noeud au coût total de la feuille
            cur = cur->sup;  //Remonte au noeud sup
        }
        if (cost < cheaper){
            cheaper = cost; //On remplace le coût minimum par le coût de la feuille
            idx = i;    //Stocke l'indice de la feuille avec le parcours le plus optimal (moins chère)
        }
    }
    return tab_min[idx];
}


t_move* bestPath(t_tree t, int *len){
    p_node leaf = minLeaf(t);

    int depth = leaf->depth;
    *len = depth - 1;   //Définit le nombre de mouvements à effectuer
    t_move* path = (t_move*) malloc((depth) * sizeof(t_move));  //pour stocker les mouvements à effectuer

    for (int i = depth - 1; i >= 0; i--){
        path[i] = leaf->mouvement; //Stocke le mouvement associé au noeud
        leaf = leaf->sup;
    }
    return path;
}
