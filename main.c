//
//  main.c
//  kznr
//
//  Created by Nishiyama Kazunori on 2015/04/14.
//  Copyright (c) 2015年 Nishiyama Kazunori. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char ID[9];
    char name[33];
    int eigo;
    int sugaku;
    int sohuto;
}student;


void split(void)
{
    
}

void hyouji(int people ,student stu[]){
    printf("一覧表示します\n");
    printf("学籍番号　名前　英語の成績　数学の成績　ソフトウェアの成績\n");
    for(int j=0;j<=people;j++){
        printf("%s %s %d %d %d\n",stu[j].ID, stu[j].name, stu[j].eigo, stu[j].sugaku, stu[j].sohuto );
    }
}
void tuika(void){
    FILE *fp;
    char *fname = "/Volumes/FLASH DRIVE/students.csv";
    char in[51];
    printf("学籍番号　名前　英語の成績　数学の成績　ソフトウェアの成績\n");
    getchar();
    fgets(in,51,stdin);
    fp = fopen( fname, "a" );
    fputs(in,fp);
    fclose(fp);
    }

void sakujyo (int people ,student stu[])
{
  
    
}    /*static char buf[BUFSIZ], str[BUFSIZ];
        
        static void input(char *c) {
            printf("文字を入力してください\n");
            scanf("%s", buf);
            sprintf(str, "%s %s /Volumes/FLASH DRIVE/students.csv", c, buf);
            system(str);
        }
        
        static void output(char *s, int l) {
            while (gets(buf)) if (strncmp(buf, s, l)) puts(buf);
        }*/

int search(int people, student stu[]){
       /* 　int i;
        　for(i = 0; i < people; i++){
            　　if(array[i] == stu) return i;
            　} 
        　return -1; */
    }

void sort(void)
{
    
}

int main(int argc, const char *argv[]) {
    
    //ファイル読み出し
    FILE *fp;
    int MAX_LENGTH=256;
    char *fname = "/Volumes/FLASH DRIVE/students.csv";
    char buf[MAX_LENGTH];
    int i=0;
    student stu[256];
    int num;
    int nizu;
    if( (fp = fopen( fname, "r+" )) == NULL ) {exit(EXIT_FAILURE);}
    while(fgets(buf,MAX_LENGTH,fp)!= NULL){
        sscanf(buf,"%[^\n,],%[^\n,],%d,%d,%d",stu[i].ID, stu[i].name, &stu[i].eigo, &stu[i].sugaku, &stu[i].sohuto );
        i++;
        nizu++;
    }
    nizu--;
    fclose(fp);
   

    
    printf("データベース\n");
    while(1){
    printf("何を実行しますか？\n");
    printf("1.データ一覧の表示\n");
    printf("2.データ追加\n");
    printf("3.データ削除\n");
    printf("4.データの検索\n");
    printf("5.データのソート\n");
    
    printf("番号を入力してください。\n");
    
    scanf("%d",&num);
    while(num<1 || num>5){
        printf("1～5の数字を入力してください。\n");
        scanf("%d",&num);
    }
    switch(num){
        case 1:
            hyouji(nizu,stu);
        break;
        
        case 2:
            tuika();
        break;
            
        case 3:
        printf("データの削除\n");
            sakujyo(nizu,stu);
        break;
            
        case 4:
        printf("データの探索\n");
            search(people,stu);
        break;
            
        case 5:
        printf("データのソート\n");
            sort();
        break;
            
        default:
        printf("何順に整列しますか？\\n");
        break;
            }
    }
    return 0;
}
