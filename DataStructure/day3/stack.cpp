#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK, int);
void mutiple_push(PSTACK pS, int cnt);
bool pop(PSTACK, int*);
int* mutiple_pop(PSTACK pS, int cnt);
void traverse(PSTACK);
bool is_empty(PSTACK);
void clear(PSTACK);

int main(void)
{
    STACK S;
    int cnt;
    int* val;
    init(&S);
    
    printf("请输入压栈次数: ");
    scanf("%d", &cnt);
    mutiple_push(&S, cnt);
    traverse(&S);

    // val = mutiple_pop(&S, cnt);
    // printf("出栈:\n");
    // for(int i=0; i<cnt; ++i)
    // {
    //     printf("%d\n", val[i]);
    // }
    
    printf("清空所有栈节点!\n");
    clear(&S);
    if(is_empty(&S))
        printf("现在栈为空!\n");
    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE) malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }
    else 
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE) malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = NULL;

    pNew->pNext = pS->pTop;
    pS->pTop = pNew;

}

void mutiple_push(PSTACK pS, int cnt)
{
    int val;
    for(int i=0; i<cnt; ++i)
    {
        printf("请输入第%d次push的值: ", i+1);
        scanf("%d", &val);
        push(pS, val);
    }
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while(p != pS->pBottom)
    {
        printf("%d\n", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool pop(PSTACK pS, int* val)
{
    if(pS->pTop == pS->pBottom)
        return false;
    PNODE p = NULL;
    *val = pS->pTop->data;
    p = pS->pTop;
    pS->pTop = pS->pTop->pNext;
    free(p);
    return true;
}

int* mutiple_pop(PSTACK pS, int cnt)
{
    int* a;
    for(int i=0; i<cnt; ++i)
    {
        if( !pop(pS, (a+i)))
        {
            printf("第%d次出栈失败", i+1);
        }
    }
    return a;
}

bool is_empty(PSTACK pS)
{
    if(pS->pTop == pS->pBottom)
        return true;
    else 
        return false;
}

void clear(PSTACK pS)
{
    if(is_empty(pS))
        return;
    
    PNODE ptr = NULL;
    while(pS->pTop != pS->pBottom)
    {
        ptr = pS->pTop;
        pS->pTop = pS->pTop->pNext;
        free(ptr);
    }
}