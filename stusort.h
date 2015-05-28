

//student構造体
struct student
{
        char number[20];
        char name[32];
        int eng;
        int math;
        int soft;
};


//英語の点数をもとにを昇順に並び替える
int comp_asc_eng( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2= *(student *)c2;

  int tmp1 = stu1.eng;
  int tmp2 = stu2.eng;
  
  return tmp1-tmp2;
}

//英語の点数をもとに降順に並び替える
int comp_des_eng( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2 = *(student *)c2;

  int tmp1 = stu1.eng;
  int tmp2 = stu2.eng;

  return tmp2-tmp1;
}

//数学の点数をもとに昇順に並び替える
int comp_asc_math( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2= *(student *)c2;

  int tmp1 = stu1.math;
  int tmp2 = stu2.math;
  
  return tmp1-tmp2;
}



//数学の点数をもとに降順に並び替える
int comp_des_math( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2 = *(student *)c2;

  int tmp1 = stu1.math;
  int tmp2 = stu2.math;

  return tmp2-tmp1;

}

//ソフトウェアの点数をもとに昇順に並び替える
int comp_asc_soft( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2= *(student *)c2;

  int tmp1 = stu1.soft;
  int tmp2 = stu2.soft;
  
  return tmp1-tmp2;
}


//ソフトウェアの点数をもとに降順に並び替える
int comp_des_soft( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2 = *(student *)c2;

  int tmp1 = stu1.soft;
  int tmp2 = stu2.soft;

  return tmp2-tmp1;

}

//昇順に並び替え
void sort_asc(struct student students[],int num,int sub_num)
{
        switch(sub_num)
        {
                case 1:qsort(students,num,sizeof(student),comp_asc_eng);break;
                case 2:qsort(students,num,sizeof(student),comp_asc_math);break;
                case 3:qsort(students,num,sizeof(student),comp_asc_soft);break;
        }
}


//降順に並び替え
void sort_des(struct student students[],int num,int sub_num)
{
        switch(sub_num)
        {
                case 1:qsort(students,num,sizeof(student),comp_des_eng);break;
                case 2:qsort(students,num,sizeof(student),comp_des_math);break;
                case 3:qsort(students,num,sizeof(student),comp_des_soft);break;
        }
 
}


