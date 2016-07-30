#include "user.h"
void UserMenu(struct user *run,struct user *head)
{

     int selector=10;
     int clschoice=1;
while(selector!=0)
  {
      if(clschoice==1)
        {
            system("cls");

            printf("\n恭喜用户:%s  登录成功\n\n",run->name);
             ShowPJ(run);
              __COUTASTERISK__  printf("1.账号充值 2.账号余额 3.我要订餐 4.评价订单 5.查看订单记录 0.注销用户\n");__COUTASTERISK__

        }

      scanf("%d",&selector);
      fflush(stdin);
      switch(selector)
       {

       case 1:clschoice=1;  ZhangHaoChongZhi(run,head);selector=10;break;
      case 2:clschoice=1;  showuser(run);        selector=10;break;
//       case 3:clschoice=1;  book(i);            selector=10;break;
       case 4:clschoice=1;  PJCT(run);            selector=10;break;
      case 5:clschoice=1;  CheckMenu(run);           selector=10;break;
       case 0:printf("注销成功\n");break;
       default: clschoice=0; printf("输入错误,请重新输入\n");break;
       }
  }
}
void CheckMenu(struct user *run)
{   int selector=10;
    while(selector!=0)
        {
            system("cls");
           __COUTASTERISK__ printf("请选择方式查看订单记录\n1.查看所有订单记录\n2.根据餐厅名查看\n3.根据菜品名查看\n4.根据消费金额查看\n0.返回主菜单\n"); __COUTASTERISK__
            scanf("%d",&selector);
            fflush(stdin);
            switch(selector)
            {
                case 1:CheckByCanTeen(run,0);break;
                case 2:CheckByCanTeen(run,1);break;
                case 3:CheckByCanTeen(run,2);break;
                case 0:break;
                default: printf("输入错误 请重新输入！\n");
            }
        }
}



void CheckByCanTeen(struct user *run,int selector)
{   FILE *fp;
    time_t t = time(0);
       char tmp[64];
    strftime( tmp, sizeof(tmp), "%Y-%m-%d-%H.%M.%S",localtime(&t) );                 //新开一个函数
    system("cls");
    char a[30]="\0";
    strcat(a,run->name);

    strcat(a,"@");
    strcat(a,tmp);
    strcat(a,".txt");
    fp=fopen(a,"w+");
    fprintf(fp,"\n用户%s在%s时进行的搜索结果:\n\n",run->name,tmp);
    fprintf(fp,"***********************************************************************************************************************\n");
    fprintf(fp,"    用户名      餐厅名    菜品名 单价 下单日期     送餐地址 是否送餐                                       用户评价\n");
    fprintf(fp,"***********************************************************************************************************************\n");

   // int temp=0;
    int log=1;
//    loadrecorded();
    char tempname[11]="\0";
    if(selector==1||selector==2)                     //类似重载的功能
   {__COUTASTERISK__ if(selector==1)printf("请输入餐厅名字:\n"); else printf("请输入菜品名字:\n"); __COUTASTERISK__
    scanf("%s",tempname);
    fflush(stdin);}
    int sel=0;
    struct record *rec=creatrecord();
   // for(temp=0;strcmp(record[temp].name,"\000\000\000\000\000\000\000\000\000")!=0;temp++)
    while(1)
    {

        if(selector==1&&strcmp(run->name,rec->name)==0&&strcmp(tempname,rec->canteen)==0)
        {   sel=1;
            PrintRecord(log,rec);
            log++;
            fprintf(fp,"%10s %10s %10s %7.2f %10s %10s %5d %50s %d\n", rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,rec->used,rec->view,rec->readview);
        }
         if(selector==2&&(strcmp(run->name,rec->name)==0)&&(strcmp(tempname,rec->foodname)==0))
        {   sel=1;
            PrintRecord(log,rec);
            log++;
            fprintf(fp,"%10s %10s %10s %7.2f %10s %10s %5d %50s %d\n",rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,rec->used,rec->view,rec->readview);
        }
        if(selector==0&&strcmp(run->name,rec->name)==0)
        {   sel=1;
            PrintRecord(log,rec);
            log++;
            fprintf(fp,"%10s %10s %10s %7.2f %10s %10s %5d %50s %d\n",rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,rec->used,rec->view,rec->readview);
        }
        if(rec->next==NULL) break;
        rec=rec->next;

    }
    if(sel==0) {printf("查无此记录\n"); }
    __COUTASTERISK__ printf("已将用户的查询记录生成到根目录\n");
    BackToMenu();
     fclose(fp);
}
void PrintRecord(int log,struct record *rec)
{
            char *a="未送餐";
            char *b="已送餐";
            if(rec->used==0)
                 printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log,rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
            else printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log,rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
}

int showrec(int log,struct user *run,struct record *rec)
{
    while(1)
                                {
                                    if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"尚未评价")==0)
                                    { __COUTASTERISK__;
                                          char *a="未送餐";
                                        char *b="已送餐";
                                        if(rec->used==0)
                                             printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
                                        else printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
                                        __COUTASTERISK__;
                                        rec->log=log;
                                        log++;

                                    }

                                    if(rec->next==NULL) break;
                                    rec=rec->next;

                                }


    return log;
}


void FindCanteen(int selector,struct record *rec,struct canteen *canteen)
{
    while(1)
                                {
                                    if(rec->log==selector)
                                    {
                                        while(1)
                                        {
                                            if(strcmp(rec->canteen,canteen->name)==0)break;
                                            if(canteen->next==NULL) break;
                                            canteen=canteen->next;
                                        }
                                    }
                                    if(rec->next==NULL) break;
                                    rec=rec->next;
                                }
}

void FindMenu(int selector,struct record *rec,struct menu *menu)
{
    while(1)
                                {
                                    if(rec->log==selector)
                                    {
                                        if(strcmp(rec->foodname,menu->foodname)==0) break;
                                        if(menu->next==NULL) break;
                                        menu=menu->next;
                                    }

                                    if(rec->next==NULL) break;
                                    rec=rec->next;
                                }
}

void FindRec(int selector,struct record *rec)
{
    while(1)                                      //重新找回rec
                                {
                                     if(rec->log==selector) break;
                                      if(rec->next==NULL) break;
                                      rec=rec->next;
                                }

}
void PJCT(struct user *run)
                            {
                                system("cls");
                                __COUTASTERISK__ printf("您的以下订单尚未评价：\n");
                                int temp=0;
                                int log=1;       //下面数组的一个计数器
                                int recordinalllist[max]={0};//存该用户订单在所有订单的位置
                                int ctofrecordinalllist=0;                        //楼上的一个计数器
                                struct record* head,*rec=creatrecord();
                                head=rec;
                              //  for(temp=0;strcmp(record[temp].name,"\000\000\000\000\000\000\000\000\000")!=0;temp++)
                              while(1)
                                {
                                    if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"尚未评价")==0)
                                    { __COUTASTERISK__;
                                          char *a="未送餐";
                                        char *b="已送餐";
                                        if(rec->used==0)
                                             printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
                                        else printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
                                        __COUTASTERISK__;
                                        rec->log=log;
                                        log++;

                                    }

                                    if(rec->next==NULL) break;
                                    rec=rec->next;

                                }
                                rec=head;
                                if(log==1) {__COUTASTERISK__ printf("您目前还没有需要评价的订单\n任意键返回菜单\n"); __COUTASTERISK__ BackToMenu();}


                                printf("请输入所要评价的订单号：(按0返回)\n");__COUTASTERISK__
                                int selector=65536;
                                scanf("%d",&selector);                                                                             //得判定！
                                fflush(stdin);
                                if(selector==0) return ;
                                while(selector>=log||selector<1)
                                {
                                    printf("您输入的订单号有错 请重新输入 按0返回\n");
                                    scanf("%d",&selector);                                                                             //得判定！
                                    fflush(stdin);
                                    if(selector==0) return ;
                                }

                                struct canteen *canteenhead,*canteen=creatcanteen();                         //找回记录所在商家
                                canteenhead=canteen;
                                while(1)
                                {
                                    if(rec->log==selector)
                                    {
                                        while(1)
                                        {
                                            if(strcmp(rec->canteen,canteen->name)==0)break;
                                            if(canteen->next==NULL) break;
                                            canteen=canteen->next;
                                        }
                                    }



                                    if(rec->next==NULL) break;
                                    rec=rec->next;

                                }
                                rec=head;     //将rec返回首地址
                                struct menu *menuhead,*menu=creatmenu();                  //找回记录所在menu
                                menuhead=menu;
                                while(1)
                                {
                                    if(rec->log==selector)
                                    {
                                        if(strcmp(rec->foodname,menu->foodname)==0) break;
                                        if(menu->next==NULL) break;
                                        menu=menu->next;
                                    }

                                    if(rec->next==NULL) break;
                                    rec=rec->next;
                                }
                                rec=head;
                                while(1)                                      //重新找回rec
                                {
                                     if(rec->log==selector) break;
                                      if(rec->next==NULL) break;
                                      rec=rec->next;
                                }

                                __COUTASTERISK__  printf("请问你对 %s 的评价为： 1.好评 2.中评 3.差评(乱打将视为放弃本次评价！！)\n",rec->canteen); __COUTASTERISK__
                                int selector1=5;  //专门为下面服务的变量
                                scanf("%d",&selector1);
                                fflush(stdin);
                                __COUTASTERISK__
                                 switch(selector1)
                                 {
                                     case 1:printf("评价餐厅成功！\n");canteen->PJ.good++;break;
                                     case 2:printf("评价餐厅成功！\n");canteen->PJ.normal++;break;
                                     case 3:printf("评价餐厅成功！\n");canteen->PJ.bad++;break;
                                     default :printf("评价餐厅失败！\n");break;
                                 }
                            __COUTASTERISK__
                                  printf("请问你对 %s 的评价为： 1.好评 2.中评 3.差评(乱打将视为放弃本次评价！！)\n",rec->foodname); __COUTASTERISK__
                                 selector1=5;//   防爆！
                                scanf("%d",&selector1);
                                fflush(stdin);
                                __COUTASTERISK__
                                 switch(selector1)
                                 {
                                     case 1:printf("评价菜品成功！\n");menu->PJ.good++;break;
                                     case 2:printf("评价菜品成功！\n");menu->PJ.normal++;break;
                                     case 3:printf("评价菜品成功！\n");menu->PJ.bad++;break;
                                      default :printf("评价菜品失败！\n");break;
                                 }
                                  __COUTASTERISK__ printf("请输入你对餐厅的评价：(别TM写空格 写空格就崩了 因为我是用scanf读入的！)\n"); __COUTASTERISK__
                                 scanf("%s",&rec->view);
                                 fflush(stdin);
                                 __COUTASTERISK__ printf("评价完成 欢迎下次光临！\n按任意键返回菜单\n"); __COUTASTERISK__
                             //   newchangemenu(findmenu);
                               // newchangerecord(recordinalllist[selector]);
                               // newchangect(findct);
                               ChangeMenu(menuhead);
                               ChangeRec(head);
                               ChangeCantenn(canteenhead);
                               BackToMenu();


                            }



//                        void PJCT(struct user *run)
//                            {
//                                system("cls");
//                                __COUTASTERISK__ printf("您的以下订单尚未评价：\n");
//                                int temp=0;
//                                int log=1;       //下面数组的一个计数器
//                                int recordinalllist[max]={0};//存该用户订单在所有订单的位置
//                                int ctofrecordinalllist=0;                        //楼上的一个计数器
//                                struct record* head,*rec=creatrecord();
//                                head=rec;
//                    //            log=showrec(log,run,rec);    //显示没有评价的订单记录
//                            while(1)
//                                {
//                                    if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"尚未评价")==0)
//                                    { __COUTASTERISK__;
//                                          char *a="未送餐";
//                                        char *b="已送餐";
//                                        if(rec->used==0)
//                                             printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
//                                        else printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n餐品价格： %7.2f元\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
//                                        __COUTASTERISK__;
//                                        rec->log=log;
//                                        log++;
//
//                                    }
//
//                                    if(rec->next==NULL) break;
//                                    rec=rec->next;
//
//                                }
//                                rec=head;
//                                if(log==1) {__COUTASTERISK__ printf("您目前还没有需要评价的订单\n任意键返回菜单\n"); __COUTASTERISK__ BackToMenu();}
//
//
//                                printf("请输入所要评价的订单号：(按0返回)\n");__COUTASTERISK__
//                                int selector=65536;
//                                scanf("%d",&selector);                                                                             //得判定！
//                                fflush(stdin);
//                                if(selector==0) return ;
//                                while(selector>=log||selector<1)
//                                {
//                                    printf("您输入的订单号有错 请重新输入 按0返回\n");
//                                    scanf("%d",&selector);                                                                             //得判定！
//                                    fflush(stdin);
//                                    if(selector==0) return ;
//                                }
//
//                                struct canteen *canteenhead,*canteen=creatcanteen();                         //找回记录所在商家
//                                canteenhead=canteen;
//                                while(1)
//                                {
//                                    if(rec->log==selector)
//                                    {
//                                        while(1)
//                                        {
//                                            if(strcmp(rec->canteen,canteen->name)==0)break;
//                                            if(canteen->next==NULL) break;
//                                            canteen=canteen->next;
//                                        }
//                                    }
//
//
//
//                                    if(rec->next==NULL) break;
//                                    rec=rec->next;
//                                }
//                              //  FindCanteen(selector,rec,canteen);
//                                rec=head;     //将rec返回首地址
//                                struct menu *menuhead,*menu=creatmenu();                  //找回记录所在menu
//                                menuhead=menu;
//                                FindMenu(selector,rec,menu);
//                                rec=head;
//                                FindRec(selector,rec);
//                                __COUTASTERISK__  printf("请问你对 %s 的评价为： 1.好评 2.中评 3.差评(乱打将视为放弃本次评价！！)\n",rec->canteen); __COUTASTERISK__
//                                int selector1=5;  //专门为下面服务的变量
//                                scanf("%d",&selector1);
//                                fflush(stdin);
//                                __COUTASTERISK__
//                                 switch(selector1)
//                                 {
//                                     case 1:printf("评价餐厅成功！\n");canteen->PJ.good++;break;
//                                     case 2:printf("评价餐厅成功！\n");canteen->PJ.normal++;break;
//                                     case 3:printf("评价餐厅成功！\n");canteen->PJ.bad++;break;
//                                     default :printf("评价餐厅失败！\n");break;
//                                 }
//                            __COUTASTERISK__
//                                  printf("请问你对 %s 的评价为： 1.好评 2.中评 3.差评(乱打将视为放弃本次评价！！)\n",rec->foodname); __COUTASTERISK__
//                                 selector1=5;//   防爆！
//                                scanf("%d",&selector1);
//                                fflush(stdin);
//                                __COUTASTERISK__
//                                 switch(selector1)
//                                 {
//                                     case 1:printf("评价菜品成功！\n");menu->PJ.good++;break;
//                                     case 2:printf("评价菜品成功！\n");menu->PJ.normal++;break;
//                                     case 3:printf("评价菜品成功！\n");menu->PJ.bad++;break;
//                                      default :printf("评价菜品失败！\n");break;
//                                 }
//                                  __COUTASTERISK__ printf("请输入你对餐厅的评价：(别TM写空格 写空格就崩了 因为我是用scanf读入的！)\n"); __COUTASTERISK__
//                                 scanf("%s",&rec->view);
//                                 fflush(stdin);
//                                 __COUTASTERISK__ printf("评价完成 欢迎下次光临！\n按任意键返回菜单\n"); __COUTASTERISK__
//                               ChangeMenu(menuhead);
//                               ChangeRec(head);
//                               ChangeCantenn(canteenhead);
//                               BackToMenu();
//
//                            }
void ZhangHaoChongZhi(struct user *run,struct user *head)
{
    int clschoice=1;
    char selector=3;
    while(selector!=0)
    {   if(clschoice==1)
        {system("cls");
         __COUTASTERISK__  printf("1.充值自己账号 2.为他人充值 3.为他人转账 0.返回\n"); __COUTASTERISK__
        }

        scanf("%d",&selector);
        fflush(stdin);
        switch(selector)
        {
            case 1:clschoice=1;ChargeForMe(run,head);  break;
            case 2:clschoice=1;ChargeForOther();break;
           case 3:clschoice=1;Tranfser(run); break;
            case 0:break;
            default: clschoice=0;printf("输入错误 请重新输入\n");
        }
    }
}

void ChargeForMe(struct user *run,struct user *head)
   {    system("cls");
       __COUTASTERISK__ printf("请输入充值额度：\n"); __COUTASTERISK__
        char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0)
        {
           __COUTASTERISK__ printf("输入的不是符合规格的数字，请重新输入：\n"); __COUTASTERISK__
           scanf("%10s",&tempprice);
            fflush(stdin);
        }
      //  price=atoi(tempprice);
      //  scanf("%d",&tempmoney);
        run->yue+=atof(tempprice);
    //    changeuserlist();
         ChangeUser(head);                             //   newchangeuser(i);     //写changes！
      __COUTASTERISK__  printf("充值成功\n");__COUTASTERISK__
        BackToMenu();

   }

void ChargeForOther()
{   int  tempmoney;
    __COUTASTERISK__ printf("请输入你想充值的账号：按0返回\n"); __COUTASTERISK__
    char selector[10];
    scanf("%10s",&selector);
    fflush(stdin);
    if(selector[0]==0&&selector[1]=='\0') return;
    struct user *head, *run=creatuser();
    head=run;
    int ret=0;    //ret判断用不用run=run->next;
     while(1)
    {
        ret=0;

        if(strcmp(selector,run->name)==0) break;
        if(run->next==NULL)
        {   __COUTASTERISK__  printf("查询不到该用户，请重新输入(按0返回):\n"); __COUTASTERISK__
            scanf("%10s",&selector);
            fflush(stdin);
            if(selector[0]=='0'&&selector[1]=='\0') return 0;
            run=head;
            ret=1;
        }
       if(ret!=1) run=run->next;
    }


   __COUTASTERISK__ printf("请输入充值额度：\n"); __COUTASTERISK__
//        scanf("%d",&tempmoney);
//        localuser[i].yue+=tempmoney;
        char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0)
        {
           __COUTASTERISK__ printf("输入的不是符合规格的数字，请重新输入：按0返回\n"); __COUTASTERISK__
           scanf("%10s",&tempprice);
            fflush(stdin);
            if(tempprice[0]=='0'&&tempprice[1]=='\0') return 0;
        }
         run->yue+=atof(tempprice);
      //  newchangeuser(i);
       ChangeUser(head);
      __COUTASTERISK__  printf("充值成功\n按任意键返回\n"); __COUTASTERISK__
        BackToMenu();

}
//
void Tranfser(struct user *ran)
{

   __COUTASTERISK__ printf("请输入你想转账的账号：按0返回\n");__COUTASTERISK__
    char selector[10];
    int j;                             //J是所转账的user序号
    scanf("%10s",&selector);
    fflush(stdin);
    if(selector[0]==0&&selector[1]=='\0') return;
    struct user *head, *run=creatuser();
    head=run;
    int ret=0;    //ret判断用不用run=run->next;
     while(1)
    {
        ret=0;

        if(strcmp(selector,run->name)==0) break;
        if(run->next==NULL)
        {   __COUTASTERISK__  printf("查询不到该用户，请重新输入(按0返回):\n"); __COUTASTERISK__
            scanf("%10s",&selector);
            fflush(stdin);
            if(selector[0]=='0'&&selector[1]=='\0') return 0;
            run=head;
            ret=1;
        }
       if(ret!=1) run=run->next;
    }



    __COUTASTERISK__  printf("请输入转账额度（只能输入整数）：\n");__COUTASTERISK__

 char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0||ran->yue<atoi(tempprice))
        {
          if(IntCheck(tempprice)==0){ __COUTASTERISK__ printf("输入的不是符合规格的数字，请重新输入：按0返回\n"); __COUTASTERISK__}
          else {__COUTASTERISK__ printf("您的余额不足，请重新输入：按0返回\n"); __COUTASTERISK__}
           scanf("%10s",&tempprice);
            fflush(stdin);
            if(tempprice[0]=='0'&&tempprice[1]=='\0') return 0;
        }
        run->yue+=atof(tempprice);
        ran->yue-=atof(tempprice);
        run=head;
        while(1)
        {
           if( strcmp(ran->name,run->name)==0) run->yue-=atof(tempprice);
           if(run->next==NULL) break;
           run=run->next;
        }



       ChangeUser(head);
       __COUTASTERISK__ printf("转账成功\n按任意键返回\n");__COUTASTERISK__
        BackToMenu();

}
void showuser(struct user *run)
{   system("cls");
    char c;
  __COUTASTERISK__  printf("您现在的账号余额为：%7.2f\n按任意键返回\n",run->yue);__COUTASTERISK__
   BackToMenu();

}



void ShowPJ(struct user *run)
{
    int count=0;
    int temp=0;
    struct record *rec=creatrecord();
    while(1)
        {
            if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"尚未评价")==0)
            count++;
            if(rec->next==NULL) break;
            rec=rec->next;
        }
    __COUTASTERISK__
    if(count!=0)
    {
    printf("注意： 您有%d份订单未评价\n",count);
    }
    else{
        printf("您目前尚未有订单未评价\n");
    }
     __COUTASTERISK__
}
