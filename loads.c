#include "user.h"

int n;
struct User* creatuser()
{   FILE* fp=fopen("user.txt","r");
    struct user * head=NULL;
    struct user *p1,*p2;
    n=0;
    char st;
    p1=p2=(struct user*)malloc(LENUSER);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    fscanf(fp,"%s%s%s%lf%d",&p1->name,&p1->code,&p1->data,&p1->yue,&p1->dingdanshu);
    head=NULL;
    while(1)
    {
        n+=1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        if(fgetc(fp)==-1) break;
        p1=(struct user*)malloc(LENUSER);
        fscanf(fp,"%s%s%s%lf%d",&p1->name,&p1->code,&p1->data,&p1->yue,&p1->dingdanshu);
    }
    p2->next=NULL;
    fclose(fp);
    return(head);
}


struct canteen* creatcanteen()
{   FILE* fp=fopen("canteen.txt","r");

    struct canteen *head=NULL;
    struct canteen *p1,*p2;
    n=0;
    char st;
    p1=p2=(struct canteen*)malloc(LENCT);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF)
    fscanf(fp,"%s%s%s%s%d%d%d%d",&p1->name,&p1->code,&p1->dial,&p1->data,&p1->PJ.good,&p1->PJ.normal,&p1->PJ.bad,&p1->ordernum);
    head=NULL;
    while(1)
    {
        n+=1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        if(fgetc(fp)==-1) break;
        p1=(struct canteen*)malloc(LENCT);
       fscanf(fp,"%s%s%s%s%d%d%d%d",&p1->name,&p1->code,&p1->dial,&p1->data,&p1->PJ.good,&p1->PJ.normal,&p1->PJ.bad,&p1->ordernum);

    }
    p2->next=NULL;
    fclose(fp);
    return(head);
}


struct record* creatrecord()
{   FILE* fp=fopen("recored.txt","r");

    struct record *head=NULL;
    struct record *p1,*p2;
    n=0;
    char st;
    p1=p2=(struct record*)malloc(LENREC);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
fscanf(fp,"%s%s%s%lf%s%s%d%s%d",&p1->name,&p1->canteen,&p1->foodname,&p1->price,&p1->data,&p1->destination,&p1->used,&p1->view,&p1->readview);

    head=NULL;
    while(1)
    {
        n+=1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        if(fgetc(fp)==-1) break;
        p1=(struct record*)malloc(LENREC);
        fscanf(fp,"%s%s%s%lf%s%s%d%s%d",&p1->name,&p1->canteen,&p1->foodname,&p1->price,&p1->data,&p1->destination,&p1->used,&p1->view,&p1->readview);

    }
    p2->next=NULL;
    fclose(fp);
    return(head);
}


struct menu* creatmenu()
{   FILE* fp=fopen("menu.txt","r");

    struct menu *head=NULL;
    struct menu *p1,*p2;
    n=0;
    char st;
    p1=p2=(struct menu*)malloc(LENMENU);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    while( (st= fgetc(fp)) != '\n' || st == EOF);
    fscanf(fp,"%s%s%lf%d%d%d%d",&p1->ctname,&p1->foodname,&p1->price,&p1->times,&p1->PJ.good,&p1->PJ.normal,&p1->PJ.bad);
    head=NULL;
    while(1)
    {
        n+=1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        if(fgetc(fp)==-1) break;
        p1=(struct menu*)malloc(LENMENU);
        fscanf(fp,"%s%s%lf%d%d%d%d",&p1->ctname,&p1->foodname,&p1->price,&p1->times,&p1->PJ.good,&p1->PJ.normal,&p1->PJ.bad);
    }
    p2->next=NULL;
    fclose(fp);
    return(head);
}
