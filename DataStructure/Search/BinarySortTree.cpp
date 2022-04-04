#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct 
{
    int key;
    int value;
}ElemType;

typedef struct BTNode
{
    ElemType data;
    struct BTNode *parent, *lchild, *rchild;

}BTNODE, *PBTNODE;

typedef struct
{
    PBTNODE root;
}*Tree, TreeNode;


void Insert(Tree pT, int val);
void CreatBTree(Tree pHead);
void TraveseTree(PBTNODE root);

int main(void)
{
    TreeNode pT;
    pT.root = NULL;     //root必须指向NULL，否则在Insert()内会访问root指向的地址

    CreatBTree(&pT);
    TraveseTree(pT.root);
    return 0;
}

void CreatBTree(Tree pHead)
{
    int cnt, val;

    printf("请输入需要创建的二叉树结点的个数: ");
    scanf("%d", &cnt);
    for(int i=0; i<cnt; ++i)
    {
        printf("第%d个结点值: ", i+1);
        scanf("%d", &val);
        Insert(pHead, val);
    }
    return;
}

void Insert(Tree pT, int val)
{
    PBTNODE pNew = (PBTNODE) malloc(sizeof(BTNODE));
    if(NULL == pNew)
    {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data.value = val; 
    pNew->parent = pNew->lchild = pNew->rchild = NULL;

    if(pT->root == NULL)
        pT->root = pNew;
    else
    {
        PBTNODE ptr = pT->root;
        while(ptr != NULL)
        {
            if( val < ptr->data.value)
            {
                if(ptr->lchild == NULL)
                {
                    ptr->lchild = pNew;
                    pNew->parent = ptr;
                    return;                 //插入结点后终结程序
                }
                else
                {
                    ptr = ptr->lchild;
                }
            }
            else
            {
                if(ptr->rchild == NULL)
                {
                    ptr->rchild = pNew;
                    pNew->parent = ptr;
                    return;             //插入结点后终结程序
                }
                else 
                {
                    ptr = ptr->rchild;
                }
            }
        }
    }
}

void TraveseTree(PBTNODE root)
{
    PBTNODE ptr = root;

    printf("%d\n", ptr->data.value);

    if(ptr->lchild != NULL)
        TraveseTree(ptr->lchild);

    if(ptr->rchild != NULL)
        TraveseTree(ptr->rchild);
}