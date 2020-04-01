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
            printf("查找成功,该节点地址为 %p",p);
            return p;//返回指针地址返回指针地址
        }
        p=p->next;
    }
    printf("没有这样的节点");
    return NULL;
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

void DeleteList(int data_p, int data_e)//删除指定节点
{
    if (head == NULL)//如果链表为空
    {
        printf("链表为空，请先初始化\n");
        return;
    }
    LinkedList *p = SearchList(data_p);
    if (p == NULL)//如果没有该节点信息
    {
        printf("没有该节点信息存在\n");
        return;
    }
    else if (head == end)//如果存在但只有一个节点
    {
        free(head);
        head = NULL;
        end  = NULL;
    }
    else if (head->next == end)//只有两个节点，判断头尾
    {
        if (end == p)
        {
            end = head;
            end->next = NULL;//搜索知道是的end，end指向head
            ;//释放end节点
            free(p);
        }
        else if (head == p)//同理
        {
            head == end;
            head->next == NULL;
            free(p);
        }
    }
    else//多个节点情况
    {
        if (p == head)//删除头
        {       
            head = head->next;
            free(p);
        }
        else if (p == end)//删除尾
        {
            LinkedList *LastButone = head;
            while (LastButone->next != end)//找到倒数第二个节点
                {LastButone = LastButone->next;}
            free(end);
            end = LastButone;
            end->next = NULL;
        }
        else//删除中间节点
        {
            LinkedList *Former = head;
            while (Former->next != p)//找到前一个节点
                {Former = Former->next;}
            Former->next = p->next;
            free(p);
        }   
    }    
}

void print()//遍历输出所有节点
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

void InsertList(int q,int data)//从后插入节点
{
    if (head = NULL)
    {
        printf("链表没有节点");
        return;
    }
    LinkedList *p = SearchList(data);
    if (p == NULL)
    {
        printf("没有该节点");
        return;
    }
    LinkedList *temp = (LinkedList*)malloc(sizeof(LinkedList));
    temp->next = q;
    temp->next = NULL;
    if (p == end)//如果找到的节点在尾部
    {   
        end->next = temp;
              end = temp;
    }
    else//如果在中间（包含头部情况）
    {
       temp->next = p->next; //先连后面
          p->next = temp;  //再连前面
    }
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