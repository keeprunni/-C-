#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Queue
{
    int * pBase;
    int len;
    int front;
    int rear;
}QUEUE, *PQUEUE;

void init_queue(PQUEUE pQ, int len);
bool full_queue(PQUEUE pQ);
bool en_queue(PQUEUE pQ, int val);
void traver_queue(PQUEUE pQ);
void multiple_en_queue(PQUEUE pQ);
bool out_queue(PQUEUE pQ, int* val);
void multiple_out_queue(PQUEUE pQ);
bool empty_queue(PQUEUE pQ);

int main(void)
{
    QUEUE Q;
    init_queue(&Q, 6);
    multiple_en_queue(&Q);
    traver_queue(&Q);

    multiple_out_queue(&Q);
    traver_queue(&Q);
    return 0;
}

void init_queue(PQUEUE pQ, int len)
{
    pQ->pBase = (int*) malloc(sizeof(int)*len);
    pQ->len = len;
    pQ->front = pQ->rear = 0;
}

bool full_queue(PQUEUE pQ)
{
    if((pQ->rear+1)%pQ->len == 0)
        return true;
    else 
        return false;
}

bool en_queue(PQUEUE pQ, int val)
{
    if(full_queue(pQ))
    {
        printf("循环队列已满!\n");
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear+1)%pQ->len;
    }
    return true;
}

void multiple_en_queue(PQUEUE pQ)
{
    int cnt, val;
    printf("请输入需要入队的次数: ");
    scanf("%d", &cnt);
    for(int i=0; i<cnt; ++i)
    {
        printf("第%d个入队值: ", i+1);
        scanf("%d", &val);
        en_queue(pQ, val);
    }
}

void traver_queue(PQUEUE pQ)
{
    int p = pQ->front;
    printf("队列中的值为:\n");
    while(p != pQ->rear)
    {
        printf("%d\n", pQ->pBase[p]);
        p = (p+1)%pQ->len;
    }
    printf("\n");
}

bool out_queue(PQUEUE pQ, int* val)
{
    if(empty_queue(pQ))
        return false;
    else 
    {
        *val = pQ->pBase[pQ->front];
        pQ->front = (pQ->front+1)%pQ->len;
        return true;
    }
}

void multiple_out_queue(PQUEUE pQ)
{
    int cnt, val;
    printf("请输入需要出队的次数: ");
    scanf("%d", &cnt);
    printf("出队的值为: \n");
    for(int i=0; i<cnt; ++i)
    {
        if( !out_queue(pQ, &val) )
            return;
        else
        {
            printf("%d\n", val);
        }
    }
}

bool empty_queue(PQUEUE pQ)
{
    if(pQ->front == pQ->rear)
    {
        printf("队列已空!\n");
        return true;
    }
    else 
        return false;
}