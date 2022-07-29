#include "opd.h"



double opd(state x0) {


    //FILE *f = fopen("output.csv", "w+");

    int maxTreeSize = N * 3 + 1;

    node nodes[maxTreeSize];
    node* nodeToExpand = NULL;


    node root;
    root.parent = NULL;
    root.depth = 0;
    root.isLeaf = 1;
    root.x = x0;
    root.l = 0;
    root.b = 1 / (1 - (double)(DISCOUNT));
    root.action = 0;


    nodes[0] = root;

    double maxB = 0.0f;
    double maxL = 0.0f;


    int treeSize = 0;


    for (int i = 0; i < N; i++) {
        
        maxB = 0.0f;
        for (int j = 0; j < treeSize + 1; j++) {
            if(nodes[j].isLeaf && nodes[j].b >= maxB) {
                maxB = nodes[j].b;
                nodeToExpand = &nodes[j];
            }
        }

        //printf("%f\n", nodeToExpand->reward);

        treeSize++;
        nodeToExpand->child1 = &nodes[treeSize];
        nodeToExpand->isLeaf = 0;
        nodeToExpand->child1->x = xplus(nodeToExpand->x, -3);
        nodeToExpand->child1->reward = reward(nodeToExpand->x, -3);
        nodeToExpand->child1->parent = nodeToExpand;
        nodeToExpand->child1->depth = nodeToExpand->depth + 1;
        nodeToExpand->child1->isLeaf = 1;
        nodeToExpand->child1->action = -3.0f;
        calculateL(nodeToExpand->child1);
        calculateB(nodeToExpand->child1);

        treeSize++;
        nodeToExpand->child2 = &nodes[treeSize];
        nodeToExpand->isLeaf = 0;
        nodeToExpand->child2->x = xplus(nodeToExpand->x, 0);
        nodeToExpand->child2->reward = reward(nodeToExpand->x, 0);
        nodeToExpand->child2->parent = nodeToExpand;
        nodeToExpand->child2->depth = nodeToExpand->depth + 1;
        nodeToExpand->child2->isLeaf = 1;
        nodeToExpand->child2->action = 0.0f;
        calculateL(nodeToExpand->child2);
        calculateB(nodeToExpand->child2);

        treeSize++;
        nodeToExpand->child3 = &nodes[treeSize];
        nodeToExpand->isLeaf = 0;
        nodeToExpand->child3->x = xplus(nodeToExpand->x, 3);
        nodeToExpand->child3->reward = reward(nodeToExpand->x, 3);
        nodeToExpand->child3->parent = nodeToExpand;
        nodeToExpand->child3->depth = nodeToExpand->depth + 1;
        nodeToExpand->child3->isLeaf = 1;
        nodeToExpand->child3->action = 3.0f;
        calculateL(nodeToExpand->child3);
        calculateB(nodeToExpand->child3);
        
        
    }

    node* finalLeaf = NULL;
    double finalAction = 0.0f;


    for (int i = 0; i < treeSize; i++) {
        if (nodes[i].isLeaf && nodes[i].l >= maxL) {
           
            finalLeaf = &nodes[i];
           
            //printf("%f, %d, %f\n", finalLeaf->l, finalLeaf->depth, finalLeaf->action);
        
            maxL = nodes[i].l;
        }
    }
    // debug variable
    int c = 0;

    while (finalLeaf->parent!= NULL) {
        finalAction = finalLeaf->action;
        finalLeaf = finalLeaf->parent;
        //fprintf(f, "%d, %f, %f, %f\n", c, finalLeaf->action, finalLeaf->x.position, finalLeaf->x.speed);
        c++;

    }
    //fclose(f);


    return finalAction;
    


}