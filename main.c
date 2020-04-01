#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList
{
    int data;
    struct LinkList *next;
}LinkedList;
LinkedList *head = NULL;
LinkedList *end = NULL;
void interface()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~输入F1  初始化链表~~~~~~\n");
    printf("~~~~~~~~输入F2    输出链表~~~~~~\n");
    printf("~~~~~~~~输入F3    清空链表~~~~~~\n");
    printf("~~~~~~~~输入F4    查找节点~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
}

void InitList(int data)//初始化链表
{
    LinkedList *p = (LinkedList*)malloc(sizeof(LinkedList));//创建一个节点
    p->data = data;
    p->next = NULL;

    if(head==NULL)//1.没有节点 2.已有节点，从后加入
    {
        head = p;//指向p已经开辟的节点
        end  = p;
    }
    else
    {
        end->next = p;//尾部指向p开辟的节点
        end = p;
    }
    printf("successful\n");
}

LinkedList* SearchList(int data)//搜索函数(指定数据)
{
    LinkedList *p=head;
    while(p!=NULL)
    {
        if (data == p->data)
        {
            return (printf("查找成功,该节点地址为 %p",p));//返回指针地址返回指针地址
        }
        p=p->next;
    }
    return (printf("没有这样的节点"));
}

void DestroyList(LinkedList *head)//清空链表
{
    LinkedList *p = head;
    while (p != NULL)
    {
        LinkedList *d = p;    
        p = p->next;
        free(d);
    }
    head = NULL;
    end  = NULL;
}

void DeleteList(int data)//删除指定节点
{
    LinkedList *p=head;
    while (p != NULL)
    {
        if(p->next = data)
        {

        }
        free(p);
    }
    
}
void print()
{
    LinkedList *p=head;
    int count = 0;
    while (p != NULL)
    {
        ++count;
        printf("第%d个节点数据为：%d",count,p->data);
        p=p->next;
    }
}

void InsertList()
{
    
}
int main()
{
    int data;
    //LinkedList *L;
    interface();
    int n,e;
    //输入数据，测试1
    printf("请输入数据需要多少个节点:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("请输入数据data:\n");
        scanf("%d",&data);
        InitList(data);
    }
    //搜索数据，测试2
    printf("enter e：");
    scanf("%d",&e);
    SearchList(e);

    //print(L);
    return 0;
}