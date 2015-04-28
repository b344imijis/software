

#define rep(i,n) for(int i = 0;i<(int)(n);i++)



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


void add_data(struct student students[],int *num)
{
        printf("学籍番号,名前,英語の成績,数学の成績,ソフトウェアの成績の順番でデータを入力してください\n");

        struct student new_stu;

        scanf("%s",new_stu.number);
        scanf("%s",new_stu.name);
        scanf("%d",&new_stu.eng);
        scanf("%d",&new_stu.math);
        scanf("%d",&new_stu.soft);

        students[*num] = new_stu;

        *num = *num + 1;

        printf("%d\n",*num);

        printf("学籍番号:\"%s\"追加完了\n",new_stu.number);

        show_table(students,*num);
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


void erase(struct student students[],int *num)
{

        int del_num = 0;
        char del_stu[20];
        struct student *ptr;
        struct student *last;

        printf("削除する学生データの学籍番号を入力してください\n");

        scanf("%s",del_stu);
        del_num = search(del_stu,students,*num);
        last = students;
        last = last + *num;

        if(del_num > 0)
        {

                ptr = students;

                ptr = ptr + del_num;

                while(++ptr < last)
                {
                         *(ptr-1) = *ptr;
                }

                printf("学籍番号:\"%s\"削除完了\n",del_stu);
                *num--;
        }else 
        {
                printf("そのような学生は存在しません\n");
                return ;
        }

}

void save_data(struct student students[],int num)
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

