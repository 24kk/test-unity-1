#include "user.h"

void ctmenu(struct canteen *run,struct canteen *head)
{
    int  selector;
    int clschoice=1;
while(selector!=0)
  {
      if(clschoice==1)
    {
        system("cls");
   printf("\n恭喜用户:%s  登录成功\n\n",run->name);
       showmenu(run);
      showview(run);}

     __COUTASTERISK__ printf("1.新增菜单 2.查看评价 3.处理新订单 4.查看所有订单以及阅读其评论 5.修改电话 0.注销用户\n"); __COUTASTERISK__

     scanf("%d",&selector);
      fflush(stdin);
      switch(selector)
       {

       case 1:clschoice=1;__COUTASTERISK__ newmenu(run);selector=10;  break;
       case 2:clschoice=1;__COUTASTERISK__ watchPJ(run);selector=10; break;
       case 3:clschoice=1;__COUTASTERISK__ newbook(run); selector=10;break;
       case 4:clschoice=1;__COUTASTERISK__ checkview(run); selector=10;break;
       case 5:clschoice=1;__COUTASTERISK__ ChangeDialOrMsg(run,head);selector=10;break;                //selector=10防爆！
       case 0:printf("注销成功\n");break;
        default:
            clschoice=0;
            printf("输入错误,请重新输入\n");
            break;

       }
  }
}

void checkview(struct canteen *run)
{
    system("cls");
    int temp=0;
    int log=1;
    struct record *head,*rec=creatrecord();
    head=rec;

        //for(temp=0;strcmp(record[temp].name,"\000\000\000\000\000\000\000\000\000")!=0;temp++)
       // {
      while(1)
         {
            if(strcmp(run->name,rec->canteen)==0)
            {
                char *a="未送餐";
                char *b="已送餐";
                __COUTASTERISK__
                if(rec->used==0)
                     printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n用户评价：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->data,rec->destination,a,rec->view);
                else printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n下单日期: %s\n送餐地址：%s\n送餐状态：%s\n用户评价：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->data,rec->destination,b,rec->view);
                __COUTASTERISK__
                log++;
                rec->readview=1;
               // newchangerecord(temp);

            }

            if(rec->next==NULL) break;
            rec=rec->next;
            temp++;

         }
      //  }
      ChangeRec(head);
        if(log==1){__COUTASTERISK__ printf("您尚未有订单 赶紧新增菜单提升吸引力吧\n"); __COUTASTERISK__}

        BackToMenu();
}

void newbook(struct canteen *run)
{   system("cls");
    int count=0;
    int count2=0;
    int temp=0;
    int log=1;

    struct record *head, *rec=creatrecord();
      head=rec;    //保留首地址  要传给changerec
     while(1)
     {
            if(strcmp(run->name,rec->canteen)==0&&rec->used==0)
            {   count++;
               __COUTASTERISK__ printf("%d:\n用户姓名：%s\n餐厅名字：%s\n餐品名字：%s\n下单日期：%s\n送货地址：%s\n",log, rec->name,rec->canteen,rec->foodname,rec->data,rec->destination);
                log++;
               {printf("是否送餐？1.是  2.否  \n");__COUTASTERISK__
                int send=8;
                scanf("%d",&send);
                fflush(stdin);
                while(1)
                    {
                        if(send==1)
                        {
                            printf("**************************订单已发送**************************\n");
                            count2++;
                             rec->used=1;
                            //changerecord(temp);
                            ChangeRec(head);
                            break;

                        }
                        if(send==2)
                        {
                            printf("**************************订单未发送**************************\n");
                            break;
                        }


                        if(send!=1&&send!=2)
                        {
                            printf("输入错误 请确认后重新输入\n");
                        }
                            scanf("%d",&send);
                            fflush(stdin);
                    }
               }
            }

            if(rec->next==NULL) break;
            rec=rec->next;
        }

        if(count==0){__COUTASTERISK__ printf("暂时没有新的订单\n");__COUTASTERISK__}
        else {__COUTASTERISK__ printf("您已处理%d 张订单（其中%d张未发货）\n",count,count-count2);__COUTASTERISK__}
        BackToMenu();


}


void watchPJ(struct canteen *run)
{   system("cls");


      __COUTASTERISK__  printf("您的餐厅目前评价为 %d个好评 %d个中评 %d个差评\n",run->PJ.good,run->PJ.normal,run->PJ.bad);__COUTASTERISK__

       BackToMenu();


}



void ChangeDialOrMsg(struct canteen *run,struct canteen *head)
{   system("cls");
    int selector;
    while(selector!=0)
    {   selector=10;
       __COUTASTERISK__ printf("1.修改电话 0.返回\n");__COUTASTERISK__
        scanf("%d",&selector);
        fflush(stdin);

        switch(selector)
        {
            case 1:  ChangeDial(run,head);selector=10;break;
          //  case 2:  ChangeMsg(i);selector=10;break;
            default:  printf("输入错误,请重新输入\n");break;
        }

    }

}
void ChangeDial(struct canteen *run,struct canteen *head)
{
    __COUTASTERISK__ printf("您现在的电话为：%s\n请输入新电话:\n",run->dial);
    scanf("%10s",run->dial);
    fflush(stdin);
    while(IntCheck(run->dial)==0)
        {
           __COUTASTERISK__ printf("输入的不是符合规格的数字，请重新输入：\n"); __COUTASTERISK__
           scanf("%10s",&run->dial);
            fflush(stdin);
        }
   // newchangect(i);
    ChangeCantenn(head);
    __COUTASTERISK__ printf("修改成功 您的新电话为：%s\n",run->dial);
    BackToMenu();

}
void ChangeMsg(struct canteen *run)
{
    ;
}
void newmenu(struct canteen *run)
{   FILE *pmenu;
    pmenu=fopen("menu.txt","a");
    system("cls");
   // struct menu *menu=creatmenu();


     char tempfoodname[15];
        double price;
       __COUTASTERISK__ printf("请输入菜品名（十个字节）（按0返回）\n");__COUTASTERISK__
       scanf("%10s",&tempfoodname);
        fflush(stdin);
        TooLongCheck(tempfoodname,10,"菜品");
         if(tempfoodname[0]=='0'&&tempfoodname[1]=='\0') return ;

       __COUTASTERISK__ printf("请输入单价:\n");__COUTASTERISK__
    //    scanf("%d",&price);
       char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0)
        {
           __COUTASTERISK__ printf("输入的不是符合规格的数字，请重新输入：\n"); __COUTASTERISK__
           scanf("%10s",&tempprice);
            fflush(stdin);
        }
        price=atof(tempprice);
        fprintf(pmenu,"%10s %10s %7.2f %5d %5d %5d %5d\n",run->name,tempfoodname,price,0,0,0,0);
        fclose(pmenu);
        printf("新增成功\n");
        BackToMenu();


}


void showmenu(struct canteen *run)
{   int count=0;
    int temp=0;
    struct record *rec=creatrecord();
    while(1)
        {
            if(strcmp(run->name,rec->canteen)==0&&rec->used==0)
            count++;
            if(rec->next==NULL) break;
            rec=rec->next;
        }
    __COUTASTERISK__
    if(count!=0)
    {     //有新订单才提示
    printf("注意： 您有%d张订单未处理\n",count);
    }
    else{
        printf("您目前尚未有新的订单.\n");
    }
}

void showview(struct canteen *run)
{
    int count=0;
    int temp=0;
    struct record *rec=creatrecord();
    while(1)
        {
            if(strcmp(run->name,rec->canteen)==0&&rec->readview==0)
            count++;
            if(rec->next==NULL) break;
            rec=rec->next;
        }
    __COUTASTERISK__
    if(count!=0)
    {     //有新订单才提示
    printf("注意： 您有%d条评论未阅读\n",count);
    }
    else{
        printf("您目前尚未有订单评论.\n");
    }
}
