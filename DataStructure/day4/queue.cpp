#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* pNext;
}NODE, *PNODE;

typedef struct Queue
{
    PNODE pHead;
    PNODE pTail;
}QUEUE, *PQUEUE;

void init_queue(PQUEUE pQ);
bool en_queue(PQUEUE pQ, int val);
void multiple_en_queue(PQUEUE pQ);
void traverse(PQUEUE pQ);

int main(void)
{
    QUEUE Q;
    init_queue(&Q);
    multiple_en_queue(&Q);
    traverse(&Q);
    return 0;
}

void init_queue(PQUEUE pQ)
{
    pQ->pHead = (PNODE) malloc(sizeof(NODE));
    if(NULL == pQ->pHead)
    {
        printf("分配内存失败!\n");
        exit(-1);
    }
    pQ->pTail = pQ->pHead;
    pQ->pHead->pNext = NULL;
}

bool en_queue(PQUEUE pQ, int val)
{
    PNODE pNew = (PNODE) malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("内存分配失败\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = NULL;

    pQ->pTail->pNext = pNew;    //在队列中，是尾指针指向新分配的内存块， 而在栈中， 是新分配的内存块指向栈顶指针
    pQ->pTail = pNew;
    return true;
}

void multiple_en_queue(PQUEUE pQ)
{
    int cnt;
    int val;
    printf("请输入需要入队的次数: ");
    scanf("%d", &cnt);
    for(int i=0; i<cnt; ++i)
    {
        printf("请输入第%d次入队值: ", i+1);
        scanf("%d", &val);
        en_queue(pQ, val);
    }
    printf("入队成功\n");
}

void traverse(PQUEUE pQ)
{
    PNODE ptr = pQ->pHead->pNext;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->pNext;
    }
}