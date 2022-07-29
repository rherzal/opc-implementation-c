#include "state.h"

struct node
{

    //variables regarding the system
    state x;
    double reward; 
    double l;
    double b;
    double action;

    //miscelaneous variables
    int isLeaf;
    int depth;

    // graph-tree stuff
    struct node* parent;
    struct node* child1;
    struct node* child2;
    struct node* child3;
};

typedef struct node node; 

void calculateL(node* nod);
void calculateB(node* nod);