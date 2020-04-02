#include <stdio.h>
#include <stdlib.h>
typedef struct Linkedlist{
    struct Linkedlist * prior;
    int data;
    struct Linkedlist * next;
}Linkedlist;

void interface();

Linkedlist* InitList(Linkedlist * head, int n);//双链表的创建

Linkedlist * InsertList(Linkedlist * head,int data,int add);//双链表插入元素，add表示插入位置

Linkedlist * DeleteList(Linkedlist * head,int data);//双链表删除指定元素

void DestroyList(Linkedlist * head);

int SearchList(Linkedlist * head,int elem);//双链表中查找指定元素

Linkedlist *ChangeData(Linkedlist * head,int data,int newElem);//双链表中更改指定位置节点中存储的数据，add表示更改位置

void print(Linkedlist * head);//输出双链表的实现函数
int main() 
{
    Linkedlist * head=NULL;
    interface();
    int input;
    while (1)
    {
        
        printf("告诉我你想干嘛？\n");
        while(scanf("%d",&input) != 1)
        {
            fflush(stdin);
            printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");
        }
        switch (input)
        {
        //输入数据，测试1
        case 1:{
            
            int n;
            printf("请输入数据需要多少个节点:");
            //scanf("%d",&n);
            while(scanf("%d",&n) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }         
            //创建双链表
            head=InitList(head, n);
            
            break;
        }
        //遍历链表，测试2
        case 2:{
            
            print(head);
            break;
        }
        //清空链表，测试3
        case 3:{
            
            DestroyList(head);
            break;
        }
        //查找指定节点，测试4
        case 4:{
            
            int data;
            printf("请输入你要查找的数据：");
            //scanf("%d", &data);
            while(scanf("%d",&data) != 1)
            {
            fflush(stdin);
            printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            if(SearchList(head, data))
                printf("查找成功,该位置为 %d\n",SearchList(head, data));
            else 
                printf("不存在这样的节点\n");
            break;
        }
        //从前插入节点，测试5
        case 5:{
            
            int data,data_new;
            printf("输入数据:");
            //scanf("%d",&q);
            while(scanf("%d",&data_new) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            printf("输入被插入节点的数据（插哪？）:");
            //scanf("%d", &data);
            while(scanf("%d",&data) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            InsertList(head,data_new,data);
            break;
        }
        //删除指定节点，测试6
        case 6:{
          
            int data_p, data_e;
            printf("要删除的数据:");
            //scanf("%d", &data_p);
            while(scanf("%d",&data_p) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            /*printf("换成什么数据");
            scanf("%d", &data_p);*/
            DeleteList(head, data_p);
            break;
        }
        //更新指定节点，测试7
        case 7:{
            int data,newelem;
            printf("修改哪个数据？:");
            while (scanf("%d",&data) != 1)
            {
                fflush(stdin);
                printf("输入有误哦小宝贝\n");
            }
            printf("更新成什么数据？:");
            while (scanf("%d",&newelem) != 1)
            {
                fflush(stdin);
                printf("输入有误哦小宝贝\n");
            }
            ChangeData(head,data,newelem);
            break;

        }
        default:{
            break;}
        }
    }   
    return 0;
    

    
    //在表中第 3 的位置插入元素 7
    //head=InsertList(head, 7, 3);
    //print(head);
    //表中删除元素 2
    //head=DeleteList(head, 2);
    //print(head);

    //printf("元素 3 的位置是：%d\n",SearchList(head,3));
    //表中第 3 个节点中的数据改为存储 6
    //head = ChangeData(head,3,6);
    //print(head);
    
    
}

void interface()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~输入1  初始化链表~~~~~~~\n");
    printf("~~~~~~~输入2    输出链表~~~~~~~\n");
    printf("~~~~~~~输入3    清空链表~~~~~~~\n");
    printf("~~~~~~~输入4    查找节点~~~~~~~\n");
    printf("~~~~~~~输入5    插入节点~~~~~~~\n");
    printf("~~~~~~~输入6    删除节点~~~~~~~\n");
    printf("~~~~~~~输入7    更新节点~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
}

Linkedlist* InitList(Linkedlist * head, int n)
{
    head=(Linkedlist*)malloc(sizeof(Linkedlist));
    head->prior=NULL;
    head->next=NULL;
    head->data=0;
    Linkedlist * end=head;
    for (int i=0; i<n; i++) 
    {
        printf("请输入数据:");
        int data;
        while (scanf("%d", &data) != 1)
        {
            fflush(stdin);
            printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");
        }
        //新节点数据创建
        Linkedlist * body=(Linkedlist*)malloc(sizeof(Linkedlist));
        body->prior=NULL;
        body->next=NULL;
        body->data=data;
        //链接头节点，更新尾节点
        end->next=body;
        body->prior=end;
        end=end->next;
    }
    return head;
}

Linkedlist * InsertList(Linkedlist * head,int data_new,int add)
{   
    if (head == NULL)
    {
        printf("链表不存在\n");
        return 0;
    }
    //新建数据域为data的结点
    Linkedlist * temp=(Linkedlist*)malloc(sizeof(Linkedlist));
    temp->data=data_new;
    temp->prior=NULL;
    temp->next=NULL;
    //插入到链表头，要特殊考虑
    if (add == head->data) 
    {
        temp->next=head;
        head->prior=temp;
        head=temp;
        printf("successful!\n");
        return head;
    }
    else
    {
        Linkedlist * body=head;
        //找到要插入位置的前一个结点
        while (body->next != NULL)
        {
            if (add != body->data)
            {
                body = body->next;
            }
            //判断条件为真，说明插入位置为链表尾
            else if (body->next==NULL) 
            {
                body->next=temp;
                temp->prior=body;
                printf("successful!\n");
                return head;  
            }
            else
            {
                body->next->prior=temp;
                temp->next=body->next;
                body->next=temp;
                temp->prior=body;
                printf("successful!\n");
                return head;
            }
        }
    }
    printf("没有找到该节点\n");
    return head;
}

Linkedlist * DeleteList(Linkedlist * head,int data)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return 0;
    }
    Linkedlist * temp=head;
    //遍历链表
    while (temp) {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data==data)
        {
            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            printf("successful!\n");
            return head;
        }
        temp=temp->next;
    }
    printf("链表中无该数据元素\n");
    return head;
}
//清空链表
void DestroyList(Linkedlist * head)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return;
    }
    Linkedlist * temp=head;
    while (temp != NULL)
    {
        Linkedlist * d = temp;
        temp=temp->next;
        free(d);        
    }
    printf("已经全部删除！！！\n");
} 

//head为原双链表，elem表示被查找元素
int SearchList(Linkedlist * head,int elem)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return 0;
    }
    //新建一个指针t，初始化为头指针 head
    Linkedlist * t=head;
    int i=1;
    while (t->next != NULL) 
    {
        if (t->data != elem)
        {
            i++;
            t=t->next;
        }
        else if (t->data == elem)
        {
            printf("successful!\n");
            return i;
        }
        
    }
    //程序执行至此处，表示查找失败
    printf("不存在这样的节点\n");
    return 0;
}

//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
Linkedlist *ChangeData(Linkedlist * head,int data,int newElem)
{
    if (head == NULL)
    {
        printf("链表不存在\n");
        return 0;
    }
    Linkedlist * temp = head;
    //遍历到被删除结点
    while(temp->next != NULL) 
    {
        if(temp->data == data)
            {
                temp->data=newElem;
                printf("successful!\n");
                return head;
            }
        temp = temp->next;
    }
    printf("没有找到该节点！\n");
    return head;
}

//输出链表的功能函数
void print(Linkedlist * head)
{
    if(head == NULL)
    {
        printf("链表不存在！\n");
        return;
    }
    Linkedlist * temp=head;
    while (temp)
    {
        if (temp->next==NULL)
        {
            printf("%d\n",temp->data);
        }
        else
        {
            printf("%d<->",temp->data);
        }
        temp=temp->next;
    }
}