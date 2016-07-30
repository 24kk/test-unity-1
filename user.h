
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define LENUSER sizeof(struct user)
#define LENCT sizeof(struct canteen)
#define LENREC sizeof(struct record)
#define LENMENU sizeof(struct menu)
#define __COUTASTERISK__ printf("********************************************\n");

struct pingjia
{
    int good;
    int normal;
    int bad;
};

struct user{
    char name[11] ;
    char code[11] ;
    char data[11];
    double yue;
    int dingdanshu;
    struct user *next;
};


struct canteen{
    char name[11] ;
    char code[11] ;
    char data[11];
    char dial[21];
    struct pingjia PJ;
    int ordernum;
    struct canteen *next;
};


struct record{
    int log;
   char name[10];
   char canteen[10];
   char foodname[10];
   double price;
   char data[11];
   char destination[10];
   int used;
   char view[50];
   int readview;
   struct record *next;
};


struct menu
{   char ctname[10];
    char foodname[10];
    double price;
    int times;
    struct pingjia PJ;
    struct menu *next;
};
