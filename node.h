#include "state.h"

typedef struct node
{

    //variables regarding the system
    state x;
    double reward; 
    double l;
    double b;


    //miscelaneous variables
    int isLeaf;
    int depth;

    // graph-tree stuff
    node* parent;
    node* child1;
    node* child2;
    node* child3;
};
