#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stusort.h"
#include"dataop.h"


#define rep(i,n) for(int i = 0;i<(int)(n);i++)

using namespace std;

int stu_num = 0;

struct student students[256];



//何でソートを行うかを表示するメニュー
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


//メインメニュー表示
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
                                case 2:add_data(students,&stu_num);break;
                                case 3:erase(students,&stu_num);break;
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

                  sscanf(buf,"%[^\n,],%[^\n,],%d,%d,%d",students[i].number,students[i].name,
                                                        &students[i].eng,&students[i].math,
                                                        &students[i].soft);

                  printf("%s,%s,%d,%d,%d\n",students[i].number,students[i].name,
                                                        &students[i].eng,&students[i].math,
                                                        &students[i].soft);



                  i++;
        }

        stu_num = i;


        show_menu();

        fclose(fin);


}
