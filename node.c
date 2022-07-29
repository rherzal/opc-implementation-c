#include "node.h"
#include "config.h"
#include <math.h>


//calculates and attributes l parameter to node
void calculateL(node* nod) {
    nod->l = nod->parent->l + pow(DISCOUNT, (double)(nod->parent->depth)) * nod->reward;
}


//calculates and attributes b paremeter to node
void calculateB(node* nod) { 
    nod->b = nod->l + pow(DISCOUNT, (double) nod->depth) / (1 - DISCOUNT); 
}

