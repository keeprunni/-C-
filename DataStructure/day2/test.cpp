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

int main()
{
    PNODE pHead = NULL;

    pHead = create_list();
    traverse_list(pHead);
    return 0;
}

PNODE create_list()
{
    int len;
    int val;

    PNODE pHead = (PNODE) malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("�ڴ����ʧ��\n");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("����������Ҫ���ɵ�����ڵ�ĸ���: len = ");
    scanf("%d", &len);

    for(int i=0; i<len; ++i)
    {
        printf("�������%d���ڵ��ֵ: ", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE) malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("�ڴ����ʧ��!\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE ptr = pHead->pNext;
    while(NULL != ptr)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->pNext;
    }
    printf("\n");
    
    return;
}
