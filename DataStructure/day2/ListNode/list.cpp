#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* pNext;
}NODE, *PNODE;

PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE, int index, int val);

int main(void)
{
    PNODE pHead = NULL;

    pHead = create_list();
    traverse_list(pHead);
    // if(is_empty(pHead))
    //     printf("该链表为空！\n");
    // else 
    // {
    //     printf("链表不为空！\n");
    //     traverse_list(pHead);
    // }
    printf("该链表的长度为%d\n", length_list(pHead));
    if(insert_list(pHead, 5, 24))
        traverse_list(pHead);
    else 
        printf("您插入的位置超过了链表长度！\n");
    return 0;
}

PNODE create_list()
{
    int len;
    int val;

    PNODE pHead = (PNODE) malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("内存分配失败！\n");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入您需要生成的链表节点的个数: len = ");
    scanf("%d", &len);

    for(int i=0; i<len; ++i)
    {
        printf("请输入第%d个节点的值: ", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE) malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("内存分配失败！\n");
            exit(-1);
        }
        pTail->pNext = pNew;
        pNew->data = val;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE ptr = pHead->pNext;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->pNext;
    }
}

bool is_empty(PNODE pHead)
{
    if(pHead->pNext == NULL)
        return true;
    else
        return false;
}

int length_list(PNODE pHead)
{
    int cnt = 0;
    PNODE ptr = pHead->pNext;
    while(ptr != NULL)
    {
        cnt++;
        ptr = ptr->pNext;
    }
    return cnt; 
}

bool insert_list(PNODE pHead, int index, int val)
{
    if(index > length_list(pHead)+1)
        return false;

    PNODE ptr = pHead;
    for(int i=0; i<index-1; ++i)
    {
        ptr = ptr->pNext;
    }

    PNODE pNew = (PNODE) malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = NULL;

    pNew->pNext = ptr->pNext;
    ptr->pNext = pNew;

    return true;
}