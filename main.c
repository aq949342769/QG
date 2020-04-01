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
    printf("~~~~~~~输入1  初始化链表~~~~~~~\n");
    printf("~~~~~~~输入2    输出链表~~~~~~~\n");
    printf("~~~~~~~输入3    清空链表~~~~~~~\n");
    printf("~~~~~~~输入4    查找节点~~~~~~~\n");
    printf("~~~~~~~输入5    插入节点~~~~~~~\n");
    printf("~~~~~~~输入6    删除节点~~~~~~~\n");
    printf("~~~~~~~输入7    反转链表~~~~~~~\n");
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
    printf("successful！\n");
}

void print()//遍历输出所有节点
{
    LinkedList *p=head;
    int count = 0;
    if(p == NULL)
    {
        printf("链表是空的！！！\n");
        return;
    }
    while (p != NULL)
    {
        ++count;
        printf("第%d个节点数据为：%d\n",count,p->data);
        p=p->next;
    }
    printf("\n");
}

void DestroyList()//清空链表
{
    
    if (head == NULL)
    {
        printf("链表是空的！\n");
        return;
    }
    LinkedList *p = head;
        while (p != NULL)
        {
            LinkedList *d = p;    
            p = p->next;
            free(d);
        }
    head = NULL;
    end  = NULL;
    printf("已经全部删除！！！\n");
} 

LinkedList* SearchList(int data)//搜索函数(指定数据)
{
    LinkedList *p=head;
    while(p!=NULL)
    {
        if (data == p->data)
        {
            return p;//返回指针地址返回指针地址
        }
        p=p->next;
    }
    return NULL;
}

void InsertList(int q,int data)//从后插入节点
{
    if (head == NULL)
    {
        printf("链表没有节点，请先输入数据\n");
        return;
    }
    LinkedList *p = SearchList(data);//创建搜索指针
    if (p == NULL)
    {
        printf("没有该节点\n");
        return;
    }
    LinkedList *temp = (LinkedList*)malloc(sizeof(LinkedList));
    temp->data = q;
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
    printf("successful!\n");
} 

void DeleteList(int data_p)//删除指定节点
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
    printf("successful!\n");   
}

void ReverseList()
{
    if (head == NULL)
    {
        printf("链表是空的！\n");
        return;
    }
    LinkedList *pre = head;
    LinkedList *cur = pre->next;
    pre->next = NULL;
    end = pre;
    while(cur!= NULL)
    {
        LinkedList *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;   
    }
    head = pre;
    printf("successful!\n");
}

int main()
{
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
        case 1:{
            //输入数据，测试1
            int n, data;
            printf("请输入数据需要多少个节点:");
            //scanf("%d",&n);
            while(scanf("%d",&n) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            for(int i=0;i<n;i++)
            {
                printf("请输入数据data:\n");    
                //scanf("%d",&data);  
                while(scanf("%d",&data) != 1)
                {
                    fflush(stdin);
                    printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");
                }
                InitList(data);
            }
            break;
        }
        case 2:{
            //遍历链表，测试2
            print();
            break;
        }
        case 3:{
            //清空链表，测试3
            DestroyList();
            break;
        }
        case 4:{
            //查找指定节点，测试4
            int data;
            printf("请输入你要查找的数据：");
            //scanf("%d", &data);
            while(scanf("%d",&data) != 1)
            {
            fflush(stdin);
            printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            if(SearchList(data) != NULL)
                printf("查找成功,该节点地址为 %p\n",SearchList(data));
            else 
                printf("不存在这样的节点");
            break;
        }
        case 5:{
            //从后插入节点，测试5
            int data,q;
            printf("输入待插入链表数据\n");
            //scanf("%d",&q);
            while(scanf("%d",&q) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            printf("输入被插入节点的数据（插哪？）\n");
            //scanf("%d", &data);
            while(scanf("%d",&data) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            InsertList(q,data);
            break;
        }
        case 6:{
            //删除指定节点，测试6
            int data_p, data_e;
            printf("要删除的数据");
            //scanf("%d", &data_p);
            while(scanf("%d",&data_p) != 1)
            {
                fflush(stdin);
                printf("你的输入有误哦~小宝贝，请认真检查呢~~\n");

            }
            /*printf("换成什么数据");
            scanf("%d", &data_p);*/
            DeleteList(data_p);
            break;
        }
        case 7:{
            //链表反转，测试7
            ReverseList();
            break;
        }
        default:{
            break;}
        }
    }   
    return 0;
}
