#include "user.h"


void Login(int z)
{
    int denglui=10;
    int nocls=1;
while(denglui!=0)
  {   if(nocls==1)
      {
          system("cls");    //清屏
      __COUTASTERISK__ if(z==1)printf("1.新用户注册 2.旧用户登录 0.返回\n");else printf("1.新商家注册 2.旧商家登录 0.返回\n"); __COUTASTERISK__
      }
     scanf("%d",&denglui);
      fflush(stdin);
      switch(denglui)
       {

       case 1: nocls=1;if(z==1)UserRegister(); if(z==2)CTRegister(); denglui=10;break;
       case 2: nocls=1;if(z==1)UserLogin();if(z==2)CTLogin();denglui=10;break;
       case 0:break;
        default: nocls=0; printf("输入错误,请重新输入\n");break;

       }
  }

}


void CTLogin()
{   struct canteen *run,*head=creatcanteen();
    run=head;
     system("cls");
    int i;
   __COUTASTERISK__ printf("请输入用户名：（按0返回）\n");__COUTASTERISK__
    char tempusername[11];
    char tempusercode[11];
    scanf("%10s",&tempusername);
    fflush(stdin);
     if(tempusername[0]=='0'&&tempusername[1]=='\0') return 0;
     int ret=0;
    while(1)
    {
        ret=0;

        if(strcmp(tempusername,run->name)==0) break;
        if(run->next==NULL)
        {   __COUTASTERISK__  printf("查询不到该商家，请重新输入(按0返回):\n"); __COUTASTERISK__
            scanf("%10s",&tempusername);
            fflush(stdin);
            if(tempusername[0]=='0'&&tempusername[1]=='\0') return 0;
            run=head;
            ret=1;
        }
       if(ret!=1) run=run->next;
    }

     __COUTASTERISK__ printf("请输入密码：(按0返回)\n"); __COUTASTERISK__
    scanf("%10s",&tempusercode);
    fflush(stdin);
    if(tempusercode[0]=='0'&&tempusercode[1]=='\0') return 0;
    while(strcmp(tempusercode,run->code)!=0)
       {
         __COUTASTERISK__  printf("密码输入错误，请重新输入(按0返回):\n");__COUTASTERISK__
            scanf("%10s",&tempusercode);
            fflush(stdin);
            if(tempusercode[0]=='0'&&tempusercode[1]=='\0') return 0;
       }

    ctmenu(run,head);

}
void UserLogin()
{   struct user*run,*head=creatuser();
    run=head;
     system("cls");
    int i;
   __COUTASTERISK__ printf("请输入用户名：（按0返回）\n");__COUTASTERISK__
    char tempusername[11];
    char tempusercode[11];
    scanf("%10s",&tempusername);
    fflush(stdin);
     if(tempusername[0]=='0'&&tempusername[1]=='\0') return 0;
     int ret=0;
    while(1)
    {
        ret=0;

        if(strcmp(tempusername,run->name)==0) break;
        if(run->next==NULL)
        {   __COUTASTERISK__  printf("查询不到该用户，请重新输入(按0返回):\n"); __COUTASTERISK__
            scanf("%10s",&tempusername);
            fflush(stdin);
            if(tempusername[0]=='0'&&tempusername[1]=='\0') return 0;
            run=head;
            ret=1;
        }
       if(ret!=1) run=run->next;
    }

     __COUTASTERISK__ printf("请输入密码：(按0返回)\n"); __COUTASTERISK__
    scanf("%10s",&tempusercode);
    fflush(stdin);
    if(tempusercode[0]=='0'&&tempusercode[1]=='\0') return 0;
    while(strcmp(tempusercode,run->code)!=0)
       {
         __COUTASTERISK__  printf("密码输入错误，请重新输入(按0返回):\n");__COUTASTERISK__
            scanf("%10s",&tempusercode);
            fflush(stdin);
            if(tempusercode[0]=='0'&&tempusercode[1]=='\0') return 0;
       }


    UserMenu(run,head);
}


void CTRegister()
{   system("cls");
    struct canteen anewct;
    char tempcode[11];
    FILE *fp;
    fp=fopen("canteen.txt","a");
     fputc('\n',fp);
    __COUTASTERISK__ printf("请输入用户名(十个字母以内)：按0返回\n");__COUTASTERISK__
    scanf("%11s",anewct.name);
    fflush(stdin);
    Checkname2(anewct.name,2)==1;
    if(anewct.name[0]=='0') return ;
    while(strlen(anewct.name)>10&&anewct.name[1]=='\0'||Checkname2(anewct.name,2)==1)                                      //错误判定   Checkname2(anewct.name,2)==1
    {
        if(strlen(anewct.name)>10)
       {__COUTASTERISK__  printf("用户名输入格式错误 请重新输入 按0返回\n");__COUTASTERISK__}                      //名字输入错误
       else {__COUTASTERISK__  printf("用户名已注册 请重新输入 按0返回\n");__COUTASTERISK__}
       scanf("%11s",anewct.name);
       fflush(stdin);
       if(anewct.name[0]=='0'&&anewct.name[1]=='\0') return ;
    }






   __COUTASTERISK__ printf("请输入密码(十个字母以内)：按0返回\n");__COUTASTERISK__
    scanf("%11s",anewct.code);
    fflush(stdin);
     if(anewct.code[0]=='0'&&anewct.code[1]=='\0') return ;
    TooLongCheck(anewct.code,10,"密码");
    if(anewct.code[0]=='\0'&&anewct.code[1]=='\0') return ;
    __COUTASTERISK__ printf("请确认密码：\n");__COUTASTERISK__
   scanf("%11s",tempcode);
    while(strcmp(anewct.code,tempcode)!=0)
        {
        __COUTASTERISK__   printf("两次密码不符 请重新输入密码(十个字母以内)：按0返回\n");__COUTASTERISK__
           scanf("%11s",anewct.code);
           fflush(stdin);
            TooLongCheck(anewct.code,10,"密码");
            if(anewct.code[0]=='0'&&anewct.code[1]=='\0') return ;
         __COUTASTERISK__  printf("请确认密码：\n");__COUTASTERISK__
           scanf("%11s",tempcode);
        }
      time_t t = time(0);
       char tmp[64];
    strftime( tmp, sizeof(tmp), "%Y/%m/%d",localtime(&t) );
  __COUTASTERISK__  printf("请输入电话(20个字母以内)：\n");__COUTASTERISK__

    scanf("%20s",anewct.dial);
    fflush(stdin);

   while(IntCheck(anewct.dial)==0)
        {
           __COUTASTERISK__ printf("输入的不是符合规格的数字，请重新输入：\n"); __COUTASTERISK__
           scanf("%20s",&anewct.dial);
            fflush(stdin);
        }

    fprintf(fp,"%10s %10s %20s %10s %5d %5d %5d %5d",anewct.name,anewct.code,anewct.dial,tmp,0,0,0,0);
    printf("注册成功按任意键返回\n");

    fclose(fp);
    BackToMenu();
}

void UserRegister()
{


    system("cls");
    struct user anewuser;
    char tempcode[11];
    FILE *fp;
    fp=fopen("user.txt","a");
    fputc('\n',fp);
   __COUTASTERISK__ printf("请输入用户名(十个字母以内)：按0返回\n");__COUTASTERISK__
    //gets(anewuser.name);
    scanf("%11s",&anewuser.name);
    fflush(stdin);
                        if(anewuser.name[0]=='0'&&anewuser.name[1]=='\0') return ;
                         printf("test\n")     ;                                           //做成函数
                        while(strlen(anewuser.name)>10||Checkname(anewuser.name,1)==1)    //||Checkname(anewuser.name,1)==1
                        {
              //错误判定
                        if(strlen(anewuser.name)>10)
                           {__COUTASTERISK__  printf("用户名输入格式错误 请重新输入 按0返回\n");__COUTASTERISK__}                      //名字输入错误
                           else {__COUTASTERISK__  printf("用户名已注册 请重新输入 按0返回\n");__COUTASTERISK__}
                           scanf("%11s",&anewuser.name);
                           fflush(stdin);
                           if(anewuser.name[0]=='0'&&anewuser.name[1]=='\0') return ;
                        }
                        if(anewuser.name[0]=='0'&&anewuser.name[1]=='\0');




                           __COUTASTERISK__ printf("请输入密码(十个字母以内)：按0返回\n");__COUTASTERISK__
                           // gets(anewuser.code);
                            scanf("%11s",&anewuser.code);
                            fflush(stdin);
                             if(anewuser.code[0]=='0'&&anewuser.code[1]=='\0') return ;
                            TooLongCheck(anewuser.code,10,"密码");
                            if(anewuser.code[0]=='\0'&&anewuser.code[1]=='\0') return ;
                            __COUTASTERISK__ printf("请确认密码：\n");__COUTASTERISK__
                          //  gets(tempcode);
                            scanf("%10s",&tempcode);
                            while(strcmp(anewuser.code,tempcode)!=0)
                                {
                                __COUTASTERISK__   printf("两次密码不符 请重新输入密码(十个字母以内)：按0返回\n");__COUTASTERISK__
                                    scanf("%10s",&anewuser.code);
                                   fflush(stdin);
                                    TooLongCheck(anewuser.code,10,"密码");
                                    if(anewuser.code[0]=='0'&&anewuser.code[1]=='\0') return ;
                                 __COUTASTERISK__  printf("请确认密码：\n");__COUTASTERISK__
                                   scanf("%10s",&tempcode);
                                   fflush(stdin);
                                }
      time_t t = time(0);
       char tmp[64];
    strftime( tmp, sizeof(tmp), "%Y/%m/%d",localtime(&t) );
    fprintf(fp,"%10s %10s %10s %7.2f %3d",anewuser.name,anewuser.code,tmp,0.0,0);
    printf("注册成功\n");
    fclose(fp);
     fflush(stdin);
    BackToMenu();

}
