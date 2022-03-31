#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BTNode
{
    char data;
    struct BTNode* pLchild;
    struct BTNode* pRchild;
}BTNODE, *PBTNODE;

PBTNODE create_BTree(void);
void PreTraverseBTree(PBTNODE pT);
void InTraverse(PBTNODE pT);
void PostTraverse(PBTNODE pT);

int main(void)
{
    PBTNODE pT = NULL;
    pT = create_BTree();
    // PreTraverseBTree(pT);
    // InTraverse(pT);
    PostTraverse(pT);
    return 0;
}

void PreTraverseBTree(PBTNODE pT)
{
    if(NULL != pT)
    {
        printf("%c\n", pT->data);

        if(NULL != pT->pLchild)
            PreTraverseBTree(pT->pLchild);

        if(NULL != pT->pRchild)
            PreTraverseBTree(pT->pRchild);
    }
}

void InTraverse(PBTNODE pT)
{
    if(NULL != pT->pLchild)
    {
        InTraverse(pT->pLchild);
    }

    printf("%c\n", pT->data);

    if(NULL != pT->pRchild)
    {
        InTraverse(pT->pRchild);
    }
}

void PostTraverse(PBTNODE pT)
{
    if(NULL != pT->pLchild)
    {
        PostTraverse(pT->pLchild);
    }

    if(NULL != pT->pRchild)
    {
        PostTraverse(pT->pRchild);
    }

    printf("%c\n", pT->data);
}

PBTNODE create_BTree(void)
{
    PBTNODE pA = (PBTNODE) malloc(sizeof(BTNODE));
    PBTNODE pB = (PBTNODE) malloc(sizeof(BTNODE));
    PBTNODE pC = (PBTNODE) malloc(sizeof(BTNODE));
    PBTNODE pD = (PBTNODE) malloc(sizeof(BTNODE));
    PBTNODE pE = (PBTNODE) malloc(sizeof(BTNODE));
    PBTNODE pF = (PBTNODE) malloc(sizeof(BTNODE));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pF;
    pE->pRchild = pF->pLchild = pF->pRchild = NULL;

    return pA;
}