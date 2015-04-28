
struct student
{
        char number[20];
        char name[32];
        int eng;
        int math;
        int soft;
};


int comp_asc_eng( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2= *(student *)c2;

  int tmp1 = stu1.eng;
  int tmp2 = stu2.eng;
  
  return tmp1-tmp2;
}

int comp_des_eng( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2 = *(student *)c2;

  int tmp1 = stu1.eng;
  int tmp2 = stu2.eng;

  return tmp2-tmp1;
}


int comp_asc_math( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2= *(student *)c2;

  int tmp1 = stu1.math;
  int tmp2 = stu2.math;
  
  return tmp1-tmp2;
}

int comp_des_math( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2 = *(student *)c2;

  int tmp1 = stu1.math;
  int tmp2 = stu2.math;

  return tmp2-tmp1;

}

int comp_asc_soft( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2= *(student *)c2;

  int tmp1 = stu1.soft;
  int tmp2 = stu2.soft;
  
  return tmp1-tmp2;
}


int comp_des_soft( const void *c1, const void *c2 )
{
  student stu1 = *(student *)c1;
  student stu2 = *(student *)c2;

  int tmp1 = stu1.soft;
  int tmp2 = stu2.soft;

  return tmp2-tmp1;

}

void sort_asc(struct student students[],int num,int sub_num)
{
        switch(sub_num)
        {
                case 1:qsort(students,num,sizeof(student),comp_asc_eng);break;
                case 2:qsort(students,num,sizeof(student),comp_asc_math);break;
                case 3:qsort(students,num,sizeof(student),comp_asc_soft);break;
        }
}

void sort_des(struct student students[],int num,int sub_num)
{
        switch(sub_num)
        {
                case 1:qsort(students,num,sizeof(student),comp_des_eng);break;
                case 2:qsort(students,num,sizeof(student),comp_des_math);break;
                case 3:qsort(students,num,sizeof(student),comp_des_soft);break;
        }
 
}


