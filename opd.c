#include "opd.h"

double opd(state x0) {
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

    nodes[0] = root;

    double maxB = 0.0f;

    int treeSize = 0;

    for (int i = 0; i < N; i++) {
        
        maxB = 0.0f;
        for (int j = 0; j < treeSize + 1; j++) {
            if(nodes[j].isLeaf && nodes[j].b > maxB) {
                maxB = nodes[j].b;
                nodeToExpand = &nodes[j];
            }
        }

        for (int j = 0; j < 3; j++) {
            treeSize++;
            nodeToExpand->child1 = &nodes[treeSize];
            nodeToExpand->isLeaf = 0;
            nodeToExpand->child1->x = xplus(nodeToExpand->x, -3);
            nodeToExpand->child1->reward = reward(nodeToExpand->x, -3);
            nodeToExpand->child1->parent = nodeToExpand;
            nodeToExpand->child1->depth = nodeToExpand->depth + 1;
            nodeToExpand->child1->isLeaf = 1;
            calculateL(nodeToExpand->child1);
            calculateB(nodeToExpand->child1);


            treeSize++;
            nodeToExpand->child2 = &nodes[treeSize];
            nodeToExpand->isLeaf = 0;
            nodeToExpand->child2->x = xplus(nodeToExpand->x, -3);
            nodeToExpand->child2->reward = reward(nodeToExpand->x, -3);
            nodeToExpand->child2->parent = nodeToExpand;
            nodeToExpand->child2->depth = nodeToExpand->depth + 1;
            nodeToExpand->child2->isLeaf = 1;
            calculateL(nodeToExpand->child2);
            calculateB(nodeToExpand->child2);

            treeSize++;
            nodeToExpand->child3 = &nodes[treeSize];
            nodeToExpand->isLeaf = 0;
            nodeToExpand->child3->x = xplus(nodeToExpand->x, -3);
            nodeToExpand->child3->reward = reward(nodeToExpand->x, -3);
            nodeToExpand->child3->parent = nodeToExpand;
            nodeToExpand->child3->depth = nodeToExpand->depth + 1;
            nodeToExpand->child3->isLeaf = 1;
            calculateL(nodeToExpand->child3);
            calculateB(nodeToExpand->child3);

        }

    }

}