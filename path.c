
#include "path.h"

p_node* tab_of_min(p_node node, int* len){

    int min_val = search_min_node(node); //Cherche la val min dans l'arbre
    p_node* min_leaf = (p_node*) malloc(MAX * sizeof(p_node));//Tableau où stocker les feuilles de val min

    t_queue_tab q;
    p_node cur;
    q = createEmptyQueue();
    enqueue_node(&q, node);

    while (q.first != q.last){
        cur = dequeue_node(&q);

        if(cur->value == min_val){
            int depth_of_min = cur->depth;

            while (cur->depth == depth_of_min && q.first != q.last){

                if(cur->value == min_val){
                    min_leaf[(*len)++] = cur; //Ajoute cur dans le tableau de feuille de val min
                }
                cur = dequeue_node(&q); //Passe au noeud suivant
            }
            return min_leaf;
        }
        else if (cur->nbinf != 0){
            for (int i = 0; i < cur->nbinf; i++) {
                if (cur->inf[i] != NULL){
                    enqueue_node(&q,cur->inf[i]);
                }
            }
        }
    }
    return NULL;
}

p_node min_leaf(t_tree t) {
    return min_leaf_node(t.root);
}


p_node min_leaf_node(p_node node){
    int len = 0, cost = 0, cheaper = 10000, idx;
    p_node* tab_min = tab_of_min(node, &len); //Prend toutes les feuilles de val min

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


t_move* best_path(t_tree t, int *len){
    p_node leaf = min_leaf(t);

    int depth = leaf->depth;
    *len = depth - 1;   //Définit le nombre de mouvements à effectuer
    t_move* path = (t_move*) malloc((depth) * sizeof(t_move));  //pour stocker les mouvements à effectuer

    for (int i = depth - 1; i >= 0; i--){
        path[i] = leaf->mouvement; //Stocke le mouvement associé au noeud
        leaf = leaf->sup;
    }
    return path;
}
