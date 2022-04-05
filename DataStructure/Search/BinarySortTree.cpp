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
void DeleteBTNode(PBTNODE root, int val);
int FindMaxBTNode(PBTNODE lchild);

int main(void)
{
    TreeNode pT;
    pT.root = NULL;     //root必须指向NULL，否则在Insert()内会访问root指向的地址

    CreatBTree(&pT);
    TraveseTree(pT.root);

    int val = 45;
    printf("删除结点值为%d后, 二叉树的先序值: \n", val);
    DeleteBTNode(pT.root, val);
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

void DeleteBTNode(PBTNODE root, int val)
{
    PBTNODE ptr = root;

    while( ptr != NULL)
    {
        if(ptr->data.value == val) break; 

        if(ptr->data.value > val) ptr = ptr->lchild;
        else ptr = ptr->rchild;
    }

    if(ptr == NULL)
    {
        printf("您所删除的值在二叉树中不存在！\n");
        return;
    }

    if((ptr->lchild != NULL) && (ptr->rchild != NULL))
    {
        int q;
        q = FindMaxBTNode(ptr->lchild);     //找出左子树的最大值或右子树的最小值
        ptr->data.value = q;            //替换当前结点的值
        DeleteBTNode(ptr->lchild, q);   //找出左子树最大值的结点或右子树最小值的结点，并删除
    }
    else if( (ptr->lchild != NULL) && (ptr->rchild == NULL))   //左子树非空
    {
        PBTNODE q = ptr->lchild;
        ptr->data.value = q->data.value;
        ptr->lchild = NULL;
        free(q);
    }
    else if((ptr->rchild != NULL) && (ptr->lchild == NULL))    //右子树非空
    {
        PBTNODE q = ptr->rchild;
        ptr->data.value = q->data.value;
        ptr->rchild = NULL;
        free(q);
    }
    else 
        free(ptr);
}

int FindMaxBTNode(PBTNODE lchild)
{
    if(lchild == NULL)
        return 0;
    else if(lchild->rchild == NULL)
        return lchild->data.value;
    else if(lchild->rchild != NULL)
        FindMaxBTNode(lchild->rchild);
    
    return 0;
}