#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}LinkedList;
void interface()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~输入1  初始化链表~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int input;
    scanf("%d", &input);
    /*switch(input)
    {
    case 1:
        printf("1");/*InitList();break;
    case 2:
        printf("helll");break;
    default:
        printf("error");break;
    }*/
}
void InitList(LinkedList *L, int n)
{
    LinkedList *old, *new;
    L = (LinkedList*)malloc(sizeof(LinkedList));
    L->next = NULL;
    old = L;
    for (int i=1;i<n;i++)
    {
        new = (LinkedList*)malloc(sizeof(LinkedList));
        printf("请输入数据：");
        scanf("%d", &new->data);
        new->next = NULL;
        old->next=new;
        old=old->next;
    }
}
void print(LinkedList *L)
{
    LinkedList *p;
    int count = 0;
    p = L;
    while(p != NULL)
    {
        ++count;
        printf("第%d个节点数据为：%d",count,p->data);
        p=p->next;
    }
}
int main()
{

    LinkedList *L;
    //interface();
    InitList(L,3);
    print(L);
    return 0;
}