#include "user.h"
int main()
{
    int switchi=5;
    int nocls=1;

    while(switchi!=0)
  {
      if(nocls==1) {system("cls");
      __COUTASTERISK__ printf("欢迎使用快餐外卖订单管理系统，请问你是？ \n1.普通用户   2.餐厅商家   0.退出\n");__COUTASTERISK__}
      scanf("%d",&switchi);
      fflush(stdin);
      switch(switchi)
       {
        case 1:nocls=1;Login(1); break;
        case 2:nocls=1;Login(2);  break;
        case 0:
          //  BackUpData();
      //  __COUTASTERISK__ printf("检测到程序正常关闭 备份成功\n") ; __COUTASTERISK__
       exit(0);
       default:nocls=0;   printf("输入错误,请重新输入\n");  break;
       }
  }

    return 0;
}


void BackToMenu()
{
   __COUTASTERISK__ printf("请按任意键返回菜单\n");__COUTASTERISK__
      char close;
      scanf("%c",&close);
      fflush(stdin);
}

int Checkname(char a[10],int choice)
{   int i;

   struct user *p1=creatuser();
    while(1)
    {

        if(choice==1)
       {
           if(strcmp(a,p1->name)==0) return 1;
       }
//       if(choice==2)
//       {
//        if(strcmp(a,p2->name)==0) return 1;
//       }

       // if(p2->next==NULL) break;
        if(p1->next==NULL) break;
         if(choice==1)   p1=p1->next;
     // if(choice==2)   p2=p2->next;
    }
   return 0;
}

int Checkname2(char a[],int choice)
{   int i;
    struct canteen *p2=creatcanteen();
    while(1)
    {
        if(strcmp(a,p2->name)==0) return 1;

        if(p2->next==NULL) break;
          p2=p2->next;
    }
    return 0;
}
void TooLongCheck(char *s,int lenghth ,char *d)
{
     while(strlen(s)>=lenghth)                            //错误判定
    {
       __COUTASTERISK__  printf("%s输入格式错误 请重新输入 按0返回菜单\n",d);__COUTASTERISK__
       scanf("%20s",s);
       fflush(stdin);
       if(*(s+0)=='0'&&*(s+1)=='\0') return ;
    }
}

int  IntCheck(char s[])
{   int i,slength;
    for(i=0;i<strlen(s);i++)
    {
        if((s[i]>'9'||s[i]<'0')&&(s[i]!='.'))
            return 0;
    }
    return 1;
}


