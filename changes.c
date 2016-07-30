#include "user.h"


void ChangeUser(struct user *head)
{
    struct user *temphead=head;
    FILE *changeuserlist=fopen("user.txt","w+");
    fprintf(changeuserlist,"***********************************************************************************\n");
    fprintf(changeuserlist,"    用户名   用户密码  注册时间    余额  下单数\n");
    fprintf(changeuserlist,"***********************************************************************************");
    while(1)
       {
            fputc('\n',changeuserlist);
           fprintf(changeuserlist,"%10s %10s %10s %7.2f %3d",temphead->name,temphead->code,temphead->data,temphead->yue,temphead->dingdanshu);
            if(temphead->next==NULL)break;
           temphead=temphead->next;
       }

    fclose(changeuserlist);
}

void ChangeRec(struct record *head)
{
    struct record *temphead=head;

    FILE *changerecord=fopen("recored.txt","w+");
    fprintf(changerecord,"***********************************************************************************************************************\n");
    fprintf(changerecord,"    用户名      餐厅名    菜品名 单价 下单日期     送餐地址 是否送餐                                       用户评价\n");
    fprintf(changerecord,"***********************************************************************************************************************");
    while(1)
    {
        fputc('\n',changerecord);
        fprintf(changerecord,"%10s %10s %10s %7.2f %10s %10s %5d %50s %d", temphead->name,temphead->canteen,temphead->foodname,temphead->price,temphead->data,temphead->destination,temphead->used,temphead->view,temphead->readview);
        if(temphead->next==NULL) break;
        temphead=temphead->next;
    }

    fclose(changerecord);


}

void ChangeMenu(struct menu *head)
{
    struct menu *temphead=head;
    FILE *changemenu=fopen("menu.txt","w+");
    fprintf(changemenu,"***********************************************************************************\n");
    fprintf(changemenu,"    餐厅名     菜品名   单价  下单数  好评  中评  差评                            \n");
    fprintf(changemenu,"***********************************************************************************");
//    for(i=0;i<max;i++)

    while(1)
   {   fputc('\n',changemenu);
       fprintf(changemenu,"%10s %10s %7.2f %5d %5d %5d %5d",temphead->ctname,temphead->foodname,temphead->price,temphead->times,temphead->PJ.good,temphead->PJ.normal,temphead->PJ.bad);
       if(temphead->next==NULL) break;
         temphead=temphead->next;

   }
    fclose(changemenu);
}



void ChangeCantenn(struct canteen *head)
{   struct canteen *temphead=head;

    FILE *changepingjia=fopen("canteen.txt","w+");
    fprintf(changepingjia,"***********************************************************************************\n");
    fprintf(changepingjia,"      用户名     密码             联系电话  注册时间    好评   中评  差评 订单总数 \n");
    fprintf(changepingjia,"***********************************************************************************");
    while(1)
    {
        fputc('\n',changepingjia);
         fprintf(changepingjia,"%10s %10s %20s %10s %5d %5d %5d %5d",temphead->name,temphead->code,temphead->dial,temphead->data,temphead->PJ.good,temphead->PJ.normal,temphead->PJ.bad,temphead->ordernum);
         if(temphead->next==NULL) break;
         temphead=temphead->next;

    }


    fclose(changepingjia);
}
