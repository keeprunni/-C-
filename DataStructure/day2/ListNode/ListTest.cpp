#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct LIST
{
    struct LIST * head;
    int data;
    struct LIST * tail;
}ListNode, *PListNode;

void CreatList(PListNode List);
void InsertList(PListNode pHead);
// int ListLength(PListNode List);

int main(void)
{
    int num = 0;
    PListNode List = NULL;

    CreatList(List);


    InsertList(List);
    // InsertList(List);
    // InsertList(List);
    // InsertList(List);
    // InsertList(List);
    // num = ListLength(List);
    // printf("链表长度为%d\n", num);
    return 0;
}

void CreatList(PListNode List)
{
    List = (PListNode) malloc(sizeof(ListNode));
    List->tail = NULL;
    if(NULL == List)
    {
        printf("新链表内存分配失败！\n");
        exit(-1);
    }
}

void InsertList(PListNode pHead)
{
    PListNode pTail = pHead;

    PListNode pNew = (PListNode) malloc(sizeof(ListNode));
    pNew->data = 5;
    pNew->head = pNew->tail = NULL;
    
    while(pTail->tail != NULL)
    {
        pTail = pTail->tail;
    }
    pTail->tail = pNew;
    pTail = pNew;
}


// int ListLength(PListNode List)
// {
//     PListNode p = List->tail;
//     int cnt = 0;
//     while(p != NULL)
//     {
//         p = p->tail;
//         cnt++;
//     }
//     return cnt;
// }
