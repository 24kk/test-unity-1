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
   printf("\n��ϲ�û�:%s  ��¼�ɹ�\n\n",run->name);
       showmenu(run);
      showview(run);}

     __COUTASTERISK__ printf("1.�����˵� 2.�鿴���� 3.�����¶��� 4.�鿴���ж����Լ��Ķ������� 5.�޸ĵ绰 0.ע���û�\n"); __COUTASTERISK__

     scanf("%d",&selector);
      fflush(stdin);
      switch(selector)
       {

       case 1:clschoice=1;__COUTASTERISK__ newmenu(run);selector=10;  break;
       case 2:clschoice=1;__COUTASTERISK__ watchPJ(run);selector=10; break;
       case 3:clschoice=1;__COUTASTERISK__ newbook(run); selector=10;break;
       case 4:clschoice=1;__COUTASTERISK__ checkview(run); selector=10;break;
       case 5:clschoice=1;__COUTASTERISK__ ChangeDialOrMsg(run,head);selector=10;break;                //selector=10������
       case 0:printf("ע���ɹ�\n");break;
        default:
            clschoice=0;
            printf("�������,����������\n");
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
                char *a="δ�Ͳ�";
                char *b="���Ͳ�";
                __COUTASTERISK__
                if(rec->used==0)
                     printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n�û����ۣ�%s\n",log, rec->name,rec->canteen,rec->foodname,rec->data,rec->destination,a,rec->view);
                else printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n�û����ۣ�%s\n",log, rec->name,rec->canteen,rec->foodname,rec->data,rec->destination,b,rec->view);
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
        if(log==1){__COUTASTERISK__ printf("����δ�ж��� �Ͻ������˵�������������\n"); __COUTASTERISK__}

        BackToMenu();
}

void newbook(struct canteen *run)
{   system("cls");
    int count=0;
    int count2=0;
    int temp=0;
    int log=1;

    struct record *head, *rec=creatrecord();
      head=rec;    //�����׵�ַ  Ҫ����changerec
     while(1)
     {
            if(strcmp(run->name,rec->canteen)==0&&rec->used==0)
            {   count++;
               __COUTASTERISK__ printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n�µ����ڣ�%s\n�ͻ���ַ��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->data,rec->destination);
                log++;
               {printf("�Ƿ��Ͳͣ�1.��  2.��  \n");__COUTASTERISK__
                int send=8;
                scanf("%d",&send);
                fflush(stdin);
                while(1)
                    {
                        if(send==1)
                        {
                            printf("**************************�����ѷ���**************************\n");
                            count2++;
                             rec->used=1;
                            //changerecord(temp);
                            ChangeRec(head);
                            break;

                        }
                        if(send==2)
                        {
                            printf("**************************����δ����**************************\n");
                            break;
                        }


                        if(send!=1&&send!=2)
                        {
                            printf("������� ��ȷ�Ϻ���������\n");
                        }
                            scanf("%d",&send);
                            fflush(stdin);
                    }
               }
            }

            if(rec->next==NULL) break;
            rec=rec->next;
        }

        if(count==0){__COUTASTERISK__ printf("��ʱû���µĶ���\n");__COUTASTERISK__}
        else {__COUTASTERISK__ printf("���Ѵ���%d �Ŷ���������%d��δ������\n",count,count-count2);__COUTASTERISK__}
        BackToMenu();


}


void watchPJ(struct canteen *run)
{   system("cls");


      __COUTASTERISK__  printf("���Ĳ���Ŀǰ����Ϊ %d������ %d������ %d������\n",run->PJ.good,run->PJ.normal,run->PJ.bad);__COUTASTERISK__

       BackToMenu();


}



void ChangeDialOrMsg(struct canteen *run,struct canteen *head)
{   system("cls");
    int selector;
    while(selector!=0)
    {   selector=10;
       __COUTASTERISK__ printf("1.�޸ĵ绰 0.����\n");__COUTASTERISK__
        scanf("%d",&selector);
        fflush(stdin);

        switch(selector)
        {
            case 1:  ChangeDial(run,head);selector=10;break;
          //  case 2:  ChangeMsg(i);selector=10;break;
            default:  printf("�������,����������\n");break;
        }

    }

}
void ChangeDial(struct canteen *run,struct canteen *head)
{
    __COUTASTERISK__ printf("�����ڵĵ绰Ϊ��%s\n�������µ绰:\n",run->dial);
    scanf("%10s",run->dial);
    fflush(stdin);
    while(IntCheck(run->dial)==0)
        {
           __COUTASTERISK__ printf("����Ĳ��Ƿ��Ϲ������֣����������룺\n"); __COUTASTERISK__
           scanf("%10s",&run->dial);
            fflush(stdin);
        }
   // newchangect(i);
    ChangeCantenn(head);
    __COUTASTERISK__ printf("�޸ĳɹ� �����µ绰Ϊ��%s\n",run->dial);
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
       __COUTASTERISK__ printf("�������Ʒ����ʮ���ֽڣ�����0���أ�\n");__COUTASTERISK__
       scanf("%10s",&tempfoodname);
        fflush(stdin);
        TooLongCheck(tempfoodname,10,"��Ʒ");
         if(tempfoodname[0]=='0'&&tempfoodname[1]=='\0') return ;

       __COUTASTERISK__ printf("�����뵥��:\n");__COUTASTERISK__
    //    scanf("%d",&price);
       char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0)
        {
           __COUTASTERISK__ printf("����Ĳ��Ƿ��Ϲ������֣����������룺\n"); __COUTASTERISK__
           scanf("%10s",&tempprice);
            fflush(stdin);
        }
        price=atof(tempprice);
        fprintf(pmenu,"%10s %10s %7.2f %5d %5d %5d %5d\n",run->name,tempfoodname,price,0,0,0,0);
        fclose(pmenu);
        printf("�����ɹ�\n");
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
    {     //���¶�������ʾ
    printf("ע�⣺ ����%d�Ŷ���δ����\n",count);
    }
    else{
        printf("��Ŀǰ��δ���µĶ���.\n");
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
    {     //���¶�������ʾ
    printf("ע�⣺ ����%d������δ�Ķ�\n",count);
    }
    else{
        printf("��Ŀǰ��δ�ж�������.\n");
    }
}
