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

            printf("\n��ϲ�û�:%s  ��¼�ɹ�\n\n",run->name);
             ShowPJ(run);
              __COUTASTERISK__  printf("1.�˺ų�ֵ 2.�˺���� 3.��Ҫ���� 4.���۶��� 5.�鿴������¼ 0.ע���û�\n");__COUTASTERISK__

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
       case 0:printf("ע���ɹ�\n");break;
       default: clschoice=0; printf("�������,����������\n");break;
       }
  }
}
void CheckMenu(struct user *run)
{   int selector=10;
    while(selector!=0)
        {
            system("cls");
           __COUTASTERISK__ printf("��ѡ��ʽ�鿴������¼\n1.�鿴���ж�����¼\n2.���ݲ������鿴\n3.���ݲ�Ʒ���鿴\n4.�������ѽ��鿴\n0.�������˵�\n"); __COUTASTERISK__
            scanf("%d",&selector);
            fflush(stdin);
            switch(selector)
            {
                case 1:CheckByCanTeen(run,0);break;
                case 2:CheckByCanTeen(run,1);break;
                case 3:CheckByCanTeen(run,2);break;
                case 0:break;
                default: printf("������� ���������룡\n");
            }
        }
}



void CheckByCanTeen(struct user *run,int selector)
{   FILE *fp;
    time_t t = time(0);
       char tmp[64];
    strftime( tmp, sizeof(tmp), "%Y-%m-%d-%H.%M.%S",localtime(&t) );                 //�¿�һ������
    system("cls");
    char a[30]="\0";
    strcat(a,run->name);

    strcat(a,"@");
    strcat(a,tmp);
    strcat(a,".txt");
    fp=fopen(a,"w+");
    fprintf(fp,"\n�û�%s��%sʱ���е��������:\n\n",run->name,tmp);
    fprintf(fp,"***********************************************************************************************************************\n");
    fprintf(fp,"    �û���      ������    ��Ʒ�� ���� �µ�����     �Ͳ͵�ַ �Ƿ��Ͳ�                                       �û�����\n");
    fprintf(fp,"***********************************************************************************************************************\n");

   // int temp=0;
    int log=1;
//    loadrecorded();
    char tempname[11]="\0";
    if(selector==1||selector==2)                     //�������صĹ���
   {__COUTASTERISK__ if(selector==1)printf("�������������:\n"); else printf("�������Ʒ����:\n"); __COUTASTERISK__
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
    if(sel==0) {printf("���޴˼�¼\n"); }
    __COUTASTERISK__ printf("�ѽ��û��Ĳ�ѯ��¼���ɵ���Ŀ¼\n");
    BackToMenu();
     fclose(fp);
}
void PrintRecord(int log,struct record *rec)
{
            char *a="δ�Ͳ�";
            char *b="���Ͳ�";
            if(rec->used==0)
                 printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log,rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
            else printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log,rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
}

int showrec(int log,struct user *run,struct record *rec)
{
    while(1)
                                {
                                    if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"��δ����")==0)
                                    { __COUTASTERISK__;
                                          char *a="δ�Ͳ�";
                                        char *b="���Ͳ�";
                                        if(rec->used==0)
                                             printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
                                        else printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
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
    while(1)                                      //�����һ�rec
                                {
                                     if(rec->log==selector) break;
                                      if(rec->next==NULL) break;
                                      rec=rec->next;
                                }

}
void PJCT(struct user *run)
                            {
                                system("cls");
                                __COUTASTERISK__ printf("�������¶�����δ���ۣ�\n");
                                int temp=0;
                                int log=1;       //���������һ��������
                                int recordinalllist[max]={0};//����û����������ж�����λ��
                                int ctofrecordinalllist=0;                        //¥�ϵ�һ��������
                                struct record* head,*rec=creatrecord();
                                head=rec;
                              //  for(temp=0;strcmp(record[temp].name,"\000\000\000\000\000\000\000\000\000")!=0;temp++)
                              while(1)
                                {
                                    if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"��δ����")==0)
                                    { __COUTASTERISK__;
                                          char *a="δ�Ͳ�";
                                        char *b="���Ͳ�";
                                        if(rec->used==0)
                                             printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
                                        else printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
                                        __COUTASTERISK__;
                                        rec->log=log;
                                        log++;

                                    }

                                    if(rec->next==NULL) break;
                                    rec=rec->next;

                                }
                                rec=head;
                                if(log==1) {__COUTASTERISK__ printf("��Ŀǰ��û����Ҫ���۵Ķ���\n��������ز˵�\n"); __COUTASTERISK__ BackToMenu();}


                                printf("��������Ҫ���۵Ķ����ţ�(��0����)\n");__COUTASTERISK__
                                int selector=65536;
                                scanf("%d",&selector);                                                                             //���ж���
                                fflush(stdin);
                                if(selector==0) return ;
                                while(selector>=log||selector<1)
                                {
                                    printf("������Ķ������д� ���������� ��0����\n");
                                    scanf("%d",&selector);                                                                             //���ж���
                                    fflush(stdin);
                                    if(selector==0) return ;
                                }

                                struct canteen *canteenhead,*canteen=creatcanteen();                         //�һؼ�¼�����̼�
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
                                rec=head;     //��rec�����׵�ַ
                                struct menu *menuhead,*menu=creatmenu();                  //�һؼ�¼����menu
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
                                while(1)                                      //�����һ�rec
                                {
                                     if(rec->log==selector) break;
                                      if(rec->next==NULL) break;
                                      rec=rec->next;
                                }

                                __COUTASTERISK__  printf("������� %s ������Ϊ�� 1.���� 2.���� 3.����(�Ҵ���Ϊ�����������ۣ���)\n",rec->canteen); __COUTASTERISK__
                                int selector1=5;  //ר��Ϊ�������ı���
                                scanf("%d",&selector1);
                                fflush(stdin);
                                __COUTASTERISK__
                                 switch(selector1)
                                 {
                                     case 1:printf("���۲����ɹ���\n");canteen->PJ.good++;break;
                                     case 2:printf("���۲����ɹ���\n");canteen->PJ.normal++;break;
                                     case 3:printf("���۲����ɹ���\n");canteen->PJ.bad++;break;
                                     default :printf("���۲���ʧ�ܣ�\n");break;
                                 }
                            __COUTASTERISK__
                                  printf("������� %s ������Ϊ�� 1.���� 2.���� 3.����(�Ҵ���Ϊ�����������ۣ���)\n",rec->foodname); __COUTASTERISK__
                                 selector1=5;//   ������
                                scanf("%d",&selector1);
                                fflush(stdin);
                                __COUTASTERISK__
                                 switch(selector1)
                                 {
                                     case 1:printf("���۲�Ʒ�ɹ���\n");menu->PJ.good++;break;
                                     case 2:printf("���۲�Ʒ�ɹ���\n");menu->PJ.normal++;break;
                                     case 3:printf("���۲�Ʒ�ɹ���\n");menu->PJ.bad++;break;
                                      default :printf("���۲�Ʒʧ�ܣ�\n");break;
                                 }
                                  __COUTASTERISK__ printf("��������Բ��������ۣ�(��TMд�ո� д�ո�ͱ��� ��Ϊ������scanf����ģ�)\n"); __COUTASTERISK__
                                 scanf("%s",&rec->view);
                                 fflush(stdin);
                                 __COUTASTERISK__ printf("������� ��ӭ�´ι��٣�\n����������ز˵�\n"); __COUTASTERISK__
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
//                                __COUTASTERISK__ printf("�������¶�����δ���ۣ�\n");
//                                int temp=0;
//                                int log=1;       //���������һ��������
//                                int recordinalllist[max]={0};//����û����������ж�����λ��
//                                int ctofrecordinalllist=0;                        //¥�ϵ�һ��������
//                                struct record* head,*rec=creatrecord();
//                                head=rec;
//                    //            log=showrec(log,run,rec);    //��ʾû�����۵Ķ�����¼
//                            while(1)
//                                {
//                                    if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"��δ����")==0)
//                                    { __COUTASTERISK__;
//                                          char *a="δ�Ͳ�";
//                                        char *b="���Ͳ�";
//                                        if(rec->used==0)
//                                             printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,a);
//                                        else printf("%d:\n�û�������%s\n�������֣�%s\n��Ʒ���֣�%s\n��Ʒ�۸� %7.2fԪ\n�µ�����: %s\n�Ͳ͵�ַ��%s\n�Ͳ�״̬��%s\n",log, rec->name,rec->canteen,rec->foodname,rec->price,rec->data,rec->destination,b);
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
//                                if(log==1) {__COUTASTERISK__ printf("��Ŀǰ��û����Ҫ���۵Ķ���\n��������ز˵�\n"); __COUTASTERISK__ BackToMenu();}
//
//
//                                printf("��������Ҫ���۵Ķ����ţ�(��0����)\n");__COUTASTERISK__
//                                int selector=65536;
//                                scanf("%d",&selector);                                                                             //���ж���
//                                fflush(stdin);
//                                if(selector==0) return ;
//                                while(selector>=log||selector<1)
//                                {
//                                    printf("������Ķ������д� ���������� ��0����\n");
//                                    scanf("%d",&selector);                                                                             //���ж���
//                                    fflush(stdin);
//                                    if(selector==0) return ;
//                                }
//
//                                struct canteen *canteenhead,*canteen=creatcanteen();                         //�һؼ�¼�����̼�
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
//                                rec=head;     //��rec�����׵�ַ
//                                struct menu *menuhead,*menu=creatmenu();                  //�һؼ�¼����menu
//                                menuhead=menu;
//                                FindMenu(selector,rec,menu);
//                                rec=head;
//                                FindRec(selector,rec);
//                                __COUTASTERISK__  printf("������� %s ������Ϊ�� 1.���� 2.���� 3.����(�Ҵ���Ϊ�����������ۣ���)\n",rec->canteen); __COUTASTERISK__
//                                int selector1=5;  //ר��Ϊ�������ı���
//                                scanf("%d",&selector1);
//                                fflush(stdin);
//                                __COUTASTERISK__
//                                 switch(selector1)
//                                 {
//                                     case 1:printf("���۲����ɹ���\n");canteen->PJ.good++;break;
//                                     case 2:printf("���۲����ɹ���\n");canteen->PJ.normal++;break;
//                                     case 3:printf("���۲����ɹ���\n");canteen->PJ.bad++;break;
//                                     default :printf("���۲���ʧ�ܣ�\n");break;
//                                 }
//                            __COUTASTERISK__
//                                  printf("������� %s ������Ϊ�� 1.���� 2.���� 3.����(�Ҵ���Ϊ�����������ۣ���)\n",rec->foodname); __COUTASTERISK__
//                                 selector1=5;//   ������
//                                scanf("%d",&selector1);
//                                fflush(stdin);
//                                __COUTASTERISK__
//                                 switch(selector1)
//                                 {
//                                     case 1:printf("���۲�Ʒ�ɹ���\n");menu->PJ.good++;break;
//                                     case 2:printf("���۲�Ʒ�ɹ���\n");menu->PJ.normal++;break;
//                                     case 3:printf("���۲�Ʒ�ɹ���\n");menu->PJ.bad++;break;
//                                      default :printf("���۲�Ʒʧ�ܣ�\n");break;
//                                 }
//                                  __COUTASTERISK__ printf("��������Բ��������ۣ�(��TMд�ո� д�ո�ͱ��� ��Ϊ������scanf����ģ�)\n"); __COUTASTERISK__
//                                 scanf("%s",&rec->view);
//                                 fflush(stdin);
//                                 __COUTASTERISK__ printf("������� ��ӭ�´ι��٣�\n����������ز˵�\n"); __COUTASTERISK__
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
         __COUTASTERISK__  printf("1.��ֵ�Լ��˺� 2.Ϊ���˳�ֵ 3.Ϊ����ת�� 0.����\n"); __COUTASTERISK__
        }

        scanf("%d",&selector);
        fflush(stdin);
        switch(selector)
        {
            case 1:clschoice=1;ChargeForMe(run,head);  break;
            case 2:clschoice=1;ChargeForOther();break;
           case 3:clschoice=1;Tranfser(run); break;
            case 0:break;
            default: clschoice=0;printf("������� ����������\n");
        }
    }
}

void ChargeForMe(struct user *run,struct user *head)
   {    system("cls");
       __COUTASTERISK__ printf("�������ֵ��ȣ�\n"); __COUTASTERISK__
        char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0)
        {
           __COUTASTERISK__ printf("����Ĳ��Ƿ��Ϲ������֣����������룺\n"); __COUTASTERISK__
           scanf("%10s",&tempprice);
            fflush(stdin);
        }
      //  price=atoi(tempprice);
      //  scanf("%d",&tempmoney);
        run->yue+=atof(tempprice);
    //    changeuserlist();
         ChangeUser(head);                             //   newchangeuser(i);     //дchanges��
      __COUTASTERISK__  printf("��ֵ�ɹ�\n");__COUTASTERISK__
        BackToMenu();

   }

void ChargeForOther()
{   int  tempmoney;
    __COUTASTERISK__ printf("�����������ֵ���˺ţ���0����\n"); __COUTASTERISK__
    char selector[10];
    scanf("%10s",&selector);
    fflush(stdin);
    if(selector[0]==0&&selector[1]=='\0') return;
    struct user *head, *run=creatuser();
    head=run;
    int ret=0;    //ret�ж��ò���run=run->next;
     while(1)
    {
        ret=0;

        if(strcmp(selector,run->name)==0) break;
        if(run->next==NULL)
        {   __COUTASTERISK__  printf("��ѯ�������û�������������(��0����):\n"); __COUTASTERISK__
            scanf("%10s",&selector);
            fflush(stdin);
            if(selector[0]=='0'&&selector[1]=='\0') return 0;
            run=head;
            ret=1;
        }
       if(ret!=1) run=run->next;
    }


   __COUTASTERISK__ printf("�������ֵ��ȣ�\n"); __COUTASTERISK__
//        scanf("%d",&tempmoney);
//        localuser[i].yue+=tempmoney;
        char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0)
        {
           __COUTASTERISK__ printf("����Ĳ��Ƿ��Ϲ������֣����������룺��0����\n"); __COUTASTERISK__
           scanf("%10s",&tempprice);
            fflush(stdin);
            if(tempprice[0]=='0'&&tempprice[1]=='\0') return 0;
        }
         run->yue+=atof(tempprice);
      //  newchangeuser(i);
       ChangeUser(head);
      __COUTASTERISK__  printf("��ֵ�ɹ�\n�����������\n"); __COUTASTERISK__
        BackToMenu();

}
//
void Tranfser(struct user *ran)
{

   __COUTASTERISK__ printf("����������ת�˵��˺ţ���0����\n");__COUTASTERISK__
    char selector[10];
    int j;                             //J����ת�˵�user���
    scanf("%10s",&selector);
    fflush(stdin);
    if(selector[0]==0&&selector[1]=='\0') return;
    struct user *head, *run=creatuser();
    head=run;
    int ret=0;    //ret�ж��ò���run=run->next;
     while(1)
    {
        ret=0;

        if(strcmp(selector,run->name)==0) break;
        if(run->next==NULL)
        {   __COUTASTERISK__  printf("��ѯ�������û�������������(��0����):\n"); __COUTASTERISK__
            scanf("%10s",&selector);
            fflush(stdin);
            if(selector[0]=='0'&&selector[1]=='\0') return 0;
            run=head;
            ret=1;
        }
       if(ret!=1) run=run->next;
    }



    __COUTASTERISK__  printf("������ת�˶�ȣ�ֻ��������������\n");__COUTASTERISK__

 char tempprice[10];
        scanf("%10s",&tempprice);
        fflush(stdin);

        while(IntCheck(tempprice)==0||ran->yue<atoi(tempprice))
        {
          if(IntCheck(tempprice)==0){ __COUTASTERISK__ printf("����Ĳ��Ƿ��Ϲ������֣����������룺��0����\n"); __COUTASTERISK__}
          else {__COUTASTERISK__ printf("�������㣬���������룺��0����\n"); __COUTASTERISK__}
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
       __COUTASTERISK__ printf("ת�˳ɹ�\n�����������\n");__COUTASTERISK__
        BackToMenu();

}
void showuser(struct user *run)
{   system("cls");
    char c;
  __COUTASTERISK__  printf("�����ڵ��˺����Ϊ��%7.2f\n�����������\n",run->yue);__COUTASTERISK__
   BackToMenu();

}



void ShowPJ(struct user *run)
{
    int count=0;
    int temp=0;
    struct record *rec=creatrecord();
    while(1)
        {
            if(strcmp(run->name,rec->name)==0&&strcmp(rec->view,"��δ����")==0)
            count++;
            if(rec->next==NULL) break;
            rec=rec->next;
        }
    __COUTASTERISK__
    if(count!=0)
    {
    printf("ע�⣺ ����%d�ݶ���δ����\n",count);
    }
    else{
        printf("��Ŀǰ��δ�ж���δ����\n");
    }
     __COUTASTERISK__
}
