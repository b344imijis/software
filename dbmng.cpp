#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stusort.h"


#define rep(i,n) for(int i = 0;i<(int)(n);i++)

using namespace std;

int stu_num = 0;

struct student students[256];

void show_table(struct student students[256],int num)
{
        rep(i,num)
        {
                printf("%s,%s,%d,%d,%d\n",
                                  students[i].number,students[i].name,
                                  students[i].eng,students[i].math,
                                  students[i].soft);
        }

}

void add_data(struct student students[],int num)
{
        printf("学籍番号,名前,英語の成績,数学の成績,ソフトウェアの成績の順番でデータを入力してください\n");

        struct student new_stu;

        scanf("%s",new_stu.number);
        scanf("%s",new_stu.name);
        scanf("%d",&new_stu.eng);
        scanf("%d",&new_stu.math);
        scanf("%d",&new_stu.soft);

        students[num] = new_stu;

        stu_num++;

        printf("学籍番号:\"%s\"追加完了\n",new_stu.number);

        show_table(students,stu_num);
}


int search(char number[],struct student students[],int num)
{

        rep(i,num)
        {   

                if(strstr(students[i].number,number))
                {
                        printf("%s,%s,%d,%d,%d\n",
                                        students[i].number,students[i].name,
                                        students[i].eng,students[i].math,
                                        students[i].soft);
                        return i;
                }

        }

        printf("データが存在しません\n");

        return -1;
}

int search_byname(struct student students[],int num)
{
        
        char number[20];
        printf("検索する学生の学籍番号を入力してください\n");
        scanf("%s",number);
        
        rep(i,num)
        {   

                if(strstr(students[i].number,number))
                {
                        printf("%s,%s,%d,%d,%d\n",
                                        students[i].number,students[i].name,
                                        students[i].eng,students[i].math,
                                        students[i].soft);
                        return i;
                }

        }

        printf("データが存在しません\n");

        return -1;
}



void erase()
{

        int del_num = 0;
        char del_stu[20];
        struct student *ptr;
        struct student *last;

        printf("削除する学生データの学籍番号を入力してください\n");

        scanf("%s",del_stu);
        del_num = search(del_stu,students,stu_num);
        last = students;
        last = last + stu_num;

        if(del_num > 0)
        {

                ptr = students;

                ptr = ptr + del_num;

                while(++ptr < last)
                {
                         *(ptr-1) = *ptr;
                }

                printf("学籍番号:\"%s\"削除完了\n",del_stu);

        }else 
        {
                printf("そのような学生は存在しません\n");
                return ;
        }

}


void sort_menu()
{

        printf("----------sortmenu--------\n");
        printf("英語の成績でソート:1\n");
        printf("数学の成績でソート:2\n");
        printf("ソフトウェアの成績でソート:3\n");
        int sort_k= 0;
        scanf("%d",&sort_k);

        int sort_by = 0;
        printf("昇順:1\n");
        printf("降順:2\n");
        scanf("%d",&sort_by);

        if(sort_by == 1)
        {
                sort_asc(students,stu_num,sort_k);
                show_table(students,stu_num);
        }else if(sort_by == 2)
        {
                sort_des(students,stu_num,sort_k);
                show_table(students,stu_num);
        }

        

}


void save_data(struct student student[],int num)
{

        FILE *fp ;

        int i = 0;


        if((fp=fopen("save.csv","w"))!=NULL){
                for(i=0;i<num;i++){
                fprintf(fp,"%s,%s,%d,%d,%d",students[i].number,students[i].name,students[i].eng,
                                students[i].math,students[i].soft);
        }
        fclose(fp);
    }
}





void show_menu()
{

        int n = 0;
        
        do
        {

                printf("--------------------menu--------------------------\n");
                printf("データ一覧の表示:1\n");
                printf("データ追加:2\n");
                printf("データ削除:3\n");
                printf("データの検索:4\n");
                printf("データのソート:5\n");
                printf("保存:6\n");
                printf("終了:0\n");
                printf("---------------------------------------------------\n");

               scanf("%d",&n);

               switch(n)
                       {
                                case 1:show_table(students,stu_num);break;
                                case 2:add_data(students,stu_num);break;
                                case 3:erase();break;
                                case 4:search_byname(students,stu_num);break;
                                case 5:sort_menu();break;
                                case 6:save_data(students,stu_num);break;
                        }


        }while(n!=0);


}



int split( char *str, const char *delim, char *outlist[] ) {
    char    *tk;
    int     cnt = 0;

    tk = strtok( str, delim );
    while( tk != NULL && cnt < 20 ) {
        outlist[cnt++] = tk;
        tk = strtok( NULL, delim );
    }
    return cnt;
}


int main()
{
        int i = 0;

        FILE *fin;
        int MAX_LENGTH = 256;

         char buf[MAX_LENGTH];
          if ((fin=fopen("students.csv","r+"))==NULL){exit(EXIT_FAILURE);}
                while(fgets(buf,MAX_LENGTH,fin) != NULL){
                  char str1[MAX_LENGTH],str2[MAX_LENGTH];
                  sscanf(buf,"%[^\n,],%[^\n,],%d,%d,%d",students[i].number,students[i].name,
                                                        &students[i].eng,&students[i].math,
                                                        &students[i].soft);
                  i++;
        }



        stu_num = i-1;

        show_menu();

        fclose(fin);


}
