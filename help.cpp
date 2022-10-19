#include <stdio.h>   
#include <malloc.h> 
#include <string.h> 
#include <stdlib.h> 
typedef struct Student
{
    char thing_name[100]; 		    //物品名称  
    char owner_name[100];  		    //物主     
    char thing_quantity[100];       //物品数量 
    char owner_sex[100];		    //物主性别(m代表女生f代表男生)
    char owner_address[100];        //物主住址
    char owner_mobile_number[100];  //物主联系方式 
}stu;
typedef struct LNode
{
    stu data;
    struct LNode* next;
}LinkList;


char th_name[100];             //物品名称  
char ow_name[100];             //物主    
char th_quantity[100];         //物品数量  
char owner_sex[100];		   //物主性别(m代表女生f代表男生)
char owner_address[100];       //物主住址
char owner_mobile_number[100]; //物主联系方式 

void menu()/* 菜单界面*/
{
    printf("\t\t\t  --------------------“你帮我助”系统--------------------  \n\n");
    printf("\t\t\t                        系统功能菜单                        \n\n");
    printf("\t\t\t     ************************************************  \n");
    printf("\t\t\t     * 0.系统帮助及说明   * 1.刷新物品信息      \n");
    printf("\t\t\t     * 2.查询物品信息     * 3.修改物品信息      \n");
    printf("\t\t\t     * 4.增加物品信息     * 5.删除信息    \n");
    printf("\t\t\t     * 6.显示当前信息     * 7.保存当前物品信息   \n");
    printf("\t\t\t     * 8.退出系统               \n");
    printf("\t\t\t     ----------------------   ----------------------  \n");
}

void help()/*帮助界面*/
{
    printf("\n\t\t\t0.欢迎使用系统帮助！\n");
    printf("\n\t\t\t1.初次进入系统后,请先选择增加物品信息;\n");
    printf("\n\t\t\t2.按照菜单提示键入数字代号;\n");
    printf("\n\t\t\t3.增加物品信息后,切记保存;\n");
    printf("\n\t\t\t4.谢谢您的使用！\n");
}

void InitList(LinkList*& L)//初始化链表  
{
    L = (LinkList*)malloc(sizeof(LinkList));
    L->next = NULL;
}
void ListInsert(LinkList*& L, LinkList* p)//插入新的节点  
{
    LinkList* q = NULL;
    q = L;
    p->next = q->next;
    q->next = p;
}
void addthing(LinkList*& L)//增加新的物品信息  
{
    printf("请输入物品的信息：\n");
    printf("物品名称：");
    scanf("%s", th_name);
    LinkList* q = L->next;
    LinkList* p;
    InitList(p);
    strcpy(p->data.thing_name, th_name);
    printf("物主姓名：");
    scanf("%s", ow_name);
    strcpy(p->data.owner_name, ow_name);
    printf("物品数量：");
    scanf("%s", &th_quantity);
    strcpy(p->data.thing_quantity, th_quantity);
    printf("物主性别：（m为男 f为女）");
    scanf("%s", &owner_sex);
    strcpy(p->data.owner_sex, owner_sex);
    printf("物主住址：");
    scanf("%s", &owner_address);
    strcpy(p->data.owner_address, owner_address);
    printf("物主手机号码：");
    scanf("%s", &owner_mobile_number);
    strcpy(p->data.owner_mobile_number, owner_mobile_number);
    ListInsert(L, p);
}

void deletething(LinkList* L)//删除物品信息  
{
    printf("请输入您要删除的物品:");
    scanf("%s", th_name);
    printf("请输入您要删除的物品的物主:");
    scanf("%s", ow_name);
    //判断  
    LinkList* p, * pre;
    if (L->next == NULL)
    {
        printf("还没有物品信息,请增加信息\n");
        return;
    }
    pre = L;
    p = pre->next;
    int judge = 0;
    while (p)
    {
        if (0 == strcmp(p->data.thing_name, th_name) && 0 == strcmp(p->data.owner_name, ow_name))
        {
            judge = 1;
            pre->next = p->next;
            free(p);
            printf("删除物品信息成功\n");
            break;
        }
        pre = p;
        p = p->next;
    }
    if (judge == 0)
        printf("该项物品不存在\n");
}

void changething(LinkList* L)//改变物品信息  
{
    int judge = 0;
    printf("请输入您要修改的物品：\n");
    scanf("%s", th_name);
    printf("请输入您要修改物品的物主：\n");
    scanf("%s", ow_name);
    LinkList* q = L->next;
    while (q != NULL)
    {
        if (0 == strcmp(q->data.owner_name, ow_name) && 0 == strcmp(q->data.thing_name, th_name))
        {
            judge = 1;
            printf("请输入您要修改的信息选项：1.物品名称 2.物主性别 3.物主住址 4.物主手机号码  5.物品数量   \n");
            int choose;
            scanf("%d", &choose);
            switch (choose)
            {
            case 1:
                printf("请输入您要修改的物品名称：");
                scanf("%s", th_name);
                printf("修改的名字为：%s\n", th_name);
                strcpy(q->data.thing_name, th_name);
                printf("修改名字成功！\n");
                break;
            case 2:
                printf("请输入您要修改的性别");
                scanf("%s%s%d", &owner_sex);
                printf("修改的物主性别为：%s\n", owner_sex);
                strcpy(q->data.owner_sex , owner_sex);
                printf("修改物主信息成功！\n");
                break;
            case 3:
                printf("请输入您要修改的住址");
                scanf("%s%s%d", &owner_address);
                printf("修改的物主住址为：%s\n", owner_address);
                strcpy(q->data.owner_address , owner_address);
                printf("修改物主住址成功！\n");
                break;
            case 4:
                printf("请输入您要修改的电话号码");
                scanf("%s%s%d", &owner_mobile_number);
                printf("修改的物主电话号码为：%s\n", owner_mobile_number);
                strcpy(q->data.owner_mobile_number , owner_mobile_number);
                printf("修改物主电话号码成功！\n");
                break;
            case 5:
                printf("请输入您要修改的物品数量：");
                scanf("%s", &th_quantity);
                printf("修改的物品数量为：%s\n", th_quantity);
                strcpy(q->data.thing_quantity , th_quantity);
                printf("修改物品数量成功！\n");
                break;
            default:
                printf("请输入正确的选项\n");
                break;
            }
        }
        q = q->next;
    }
    if (judge == 0)
    {
        printf("该物品不存在\n");
    }
}
void findthing(LinkList* L)//查找并输出对应物品信息  
{
    int flag;
    printf("1.按物品名称查询：\n");
    printf("2.按物主查询：\n");
    printf("请输入查询方式：");
    scanf("%d", &flag);
    if (flag == 1) {
        printf("请输入物品名称：");
        scanf("%s", th_name);
        //判断  
        LinkList* q = L->next;
        while (q != NULL)
        {
            if (strcmp(q->data.thing_name, th_name) == 0)
            {
                printf("物品名称：%s\n", q->data.thing_name);
                printf("物主：%s\n", q->data.owner_name);
                printf("物品数量：%s\n", q->data.thing_quantity);
                printf("物主性别：%s\n", q->data.owner_sex);
                printf("物主住址：%s\n", q->data.owner_address);
                printf("物主手机号码：%s\n", q->data.owner_mobile_number);
                //break;
            }
            q = q->next;
        }
        if (q == NULL)
            printf("全部信息已加载\n");
    }
    else {
        printf("请输入物主：");
        scanf("%s", ow_name);
        LinkList* q = L->next;
        while (q != NULL)
        {
            if (strcmp(q->data.owner_name, ow_name) == 0)
            {
                printf("物品名称：%s\n", q->data.thing_name);
                printf("物主：%s\n", q->data.owner_name);
                printf("物品数量：%s\n", q->data.thing_quantity);
                printf("物主性别：%s\n", q->data.owner_sex);
                printf("物主住址：%s\n", q->data.owner_address);
                printf("物主手机号码：%d\n", q->data.owner_mobile_number);
                break;
            }
            q = q->next;
        }
        if (q == NULL)
            printf("物品不存在\n");
    }
}
void display(LinkList*& L)//浏览全部物品信息  
{
    LinkList* q = L->next;
    if (q == NULL)
    {
        printf("还没有物品信息，请增加物品信息\n");
        return;
    }
    while (q)
    {
        printf("物品名称：%s\t", q->data.thing_name);
        printf("物主：%s\t", q->data.owner_name);
        printf("物品数量：%s\t", q->data.thing_quantity);
        printf("物主性别：%s\t", q->data.owner_sex);
        printf("物主住址：%s\t", q->data.owner_address);
        printf("物主手机号码：%s\n", q->data.owner_mobile_number);
        q = q->next;
    }
}
void sort(LinkList* L)//按名称排序排序 并输出排序后的结果  
{
    LinkList* q, * p, * r = L->next;
    //判断  
    if (r == NULL)
    {
        printf("还没有学生信息，请增加学生信息\n");
        return;
    }
    while (r) //两层循环完成排序  
    {
        p = r;
        q = r->next;
        LinkList* tmp;//用于排序时暂存节点  
        InitList(tmp);
        while (q)
        {
            if (strcmp(q->data.thing_name, p->data.thing_name) < 0)  //按物品名称排序
            {
                /*先复制q结点信息到tmp*/
                strcpy(tmp->data.owner_name, q->data.owner_name);
                strcpy(tmp->data.thing_name, q->data.thing_name);
                strcpy(tmp->data.thing_quantity, q->data.thing_quantity);
                strcpy(tmp->data.owner_sex, q->data.owner_sex);
                strcpy(tmp->data.owner_address, q->data.owner_address);
                strcpy(tmp->data.owner_mobile_number, q->data.owner_mobile_number);
                /*再复制p结点信息到q*/
                strcpy(q->data.owner_name, p->data.owner_name);
                strcpy(q->data.thing_name, p->data.thing_name);
                strcpy(q->data.thing_quantity, p->data.thing_quantity);
                strcpy(q->data.owner_sex, p->data.owner_sex);
                strcpy(q->data.owner_address, p->data.owner_address);
                strcpy(q->data.owner_mobile_number, p->data.owner_mobile_number);
                /*最后复制exchange结点信息到p*/
                strcpy(p->data.owner_name, tmp->data.owner_name);
                strcpy(p->data.thing_name, tmp->data.thing_name);
                strcpy(p->data.thing_quantity , tmp->data.thing_quantity);
                strcpy(p->data.owner_sex , tmp->data.owner_sex);
                strcpy(p->data.owner_address , tmp->data.owner_address);
                strcpy(p->data.owner_mobile_number , tmp->data.owner_mobile_number);
            }
            q = q->next;
        }
        r = r->next;
    }
    printf("刷新后的学生信息是：\n");
    display(L);
}
void saveThingFile(LinkList*& L)//保存物品信息到文件  
{
    FILE* fp;
    LinkList* p = L->next;
    if ((fp = fopen("E:\\c++代码\\repos\\help\\student.txt", "w")) == NULL)// 以可写的方式打开当前目录下的.txt  
    {
        printf("不能打开此文件，请按任意键退出\n");
        exit(1);  //异常退出
    }
    while (p)
    {
        fprintf(fp, "%s  %s  %s  %s  %s  %s \n", p->data.owner_name, p->data.thing_name, p->data.thing_quantity, p->data.owner_sex, p->data.owner_address, p->data.owner_mobile_number);
        p = p->next;
    }
    printf("保存成功\n");
    
    fclose(fp);
}

void readStuDentput(LinkList*& L) //运行前把文件内容读取到电脑内存  
{
    FILE* fp;
    fp = fopen("E:\\c++代码\\repos\\help\\student.txt", "rb"); //以只读方式打开当前目录下的.txt  
    if (fp == NULL)
    {
        printf("文件不存在\n");
        exit(0);                   //终止程序  
    }
    int i = 0;
    while (!feof(fp))
    {
        char ow_name[100];            //物主  
        char th_name[100];            //物品名称   
        char th_quantity;             //物品数量  
        char owner_sex;		          //物主性别(m代表女生f代表男生)
        char owner_address;		      //物主住址
        char owner_mobile_number;     //物主联系方式   
        fscanf(fp, "%s %s %s %s %s %s", ow_name, th_name, &th_quantity, &owner_sex, &owner_address, &owner_mobile_number);
        i++;
    }
    fclose(fp);
    FILE* FP;
    FP = fopen("E:\\c++代码\\repos\\help\\student.txt", "rb"); //以只读方式打开当前目录下的.txt  
    if (FP == NULL)
    {
        printf("无法打开文件\n");
        exit(0); //终止程序  
    }
    int b = i - 1;
    int j = 1;
    while (!feof(FP))
    {
        fscanf(FP, "%s %s %s %s %s %s ", ow_name, th_name, &th_quantity, &owner_sex, &owner_address, &owner_mobile_number);
        LinkList* n = (LinkList*)malloc(sizeof(LinkList));
        strcpy(n->data.owner_name, ow_name);//把后者的内容拷贝到前者中  
        strcpy(n->data.thing_name, th_name);//把后者的内容拷贝到前者中  
        strcpy(n->data.thing_quantity , th_quantity);
        strcpy(n->data.owner_sex , owner_sex);
        strcpy(n->data.owner_address , owner_address);
        strcpy(n->data.owner_mobile_number , owner_mobile_number);
        ListInsert(L, n);//插入新的节点  
        n = n->next;
        if (j == b)
            break;
        j++;
    }
    fclose(FP);    //关闭文件  
}

int main()
{
    LinkList* L;
    InitList(L);
    readStuDentput(L);   //运行前把文件内容读取到电脑   
    int choose;
    while (1)
    {
        printf("\n");
        menu();     //功能菜单 
        printf("请输入您的选择：\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0://系统帮助及说明
            help();
            break;
        case 1://刷新信息（按物品名称排序）
            sort(L);
            break;
        case 2: //查询物品信息
            findthing(L);
            break;
        case 3://修改物品信息  
            changething(L);
            break;
        case 4://增加物品信息  
            addthing(L);
            break;
        case 5://删除物品信息  
            deletething(L);
            break;
        case 6://输出所有物品的信息  
            display(L);
            break;
        case 7://保存物品信息到文件   
            saveThingFile(L);
            break;
        case 8://退出  
            printf("谢谢使用！");
            exit(0);
        default:
            printf("请输入正确的选择\n");
            break;
        }
    }
    return 0;
}
