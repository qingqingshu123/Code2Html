#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<conio.h>
#include<malloc.h>
#include <ctype.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 1000
#define MAXN 2000
#define MAXARRAY 20000
#include <ctype.h>
#define len strlen
#define TRUE 1
#define FALSE 0
#define	MIN_INPUT 0x20
#define	MAX_INPUT 0x7e
int student_login_interface();
int admin_interface();
int main_interface();
int exit_interface();
int student_base_data_interface();
int admin_student_base_data_interface();
int main_interface();
int register_user();
int Print_from_Linklist_to_array();
int LinkDelete_student_data();
int LinkInsert_student();
void Init_student_keydata();
void Init_admin_key_data();
int InitList_student_data();
int Initi_course_data();
int Init_student_choose_course_data();
int INIT_ALL();
int Load_student_Linklist();
int Write_ALL();
int Write_admin_key();
int Write_student_data();
int Write_student_key();
int Write_student_chose_course();
int Write_course_data();
int array_delete_student_key(char *s);
int scanf_key(char *key);
int Countdown_Clock();
void main_printf();
int Init_ALL_course_count();
int Input_key(char *key);
void welcome_interface();
int student_login();
int admin_login();
int Insert_student();
int Delete_student_data();
int Delete_course();
void personal_base_information();
void student_choose_class_data();
void student_total_credit();
int Device_studentdependclass();
int Device_studentdependcourse();
int student_course_data_in_oneclasse();
int onecourse_all_student();
int modification_student_data();
int modification_student_key();
int modification_student_basic_data();
int input_student_imformation_of_course();
int input_student_grade_imformation_of_course();
int all_student_total_credit();
int rightful_key(char *s);
int R_L_K(char*s);
int scan_num(char *num);
int scan_phone(char *num);
int scan_course_num(char *num);
int scan_sex(char *s);
int scan_age(char *s);
int scan_dor(char *s);
int scan_name(char *s);
int scan_class(char *s);
int scan_credit(double &s);
int scan_score(double &s);
int right_course(char *s);
int repeat_course(char *s);
int encrypt(char *key);
int decode(char *key);
void quicksort(char s[][20],int left,int right);
int sort_data();
int sort_student_key();
int sort_admin_key();
int sort_course();
int sort_student_course();
void butterfly();
int Fly();
int I_LOVE_YOU();
int logging_grade_data_one_course();
int finish_logging_grade();
int input_grade();
int unpass();
int Total_Credit_Unpass();
int add_course();
int add_delete_course();
int modification_admin_key();
int Look_over_scores();
int SORT_ALL();
int END();
//ѧ����ѡÿһ�ſγ̵Ľṹ��
typedef struct one_course{
   char num[15];//�γ̱��
   char name[20];
   double usual_score;
   double exam_score;
   double final_score;
   double credit;//ѧ��
   int  IsRetake;//�ж��Ƿ�����
   char Retake_semester[20];
   int Retake_count;
   int fnish;
}one_course;
typedef struct oneclass{
    char class_name[20];
    int student_num[200];
    int count;
}oneclass;
oneclass ALLCLASS[200];
//ѧ��������Ϣ
typedef struct student{
    char num[15];
    char class_name[15];
    char name[10];
    char sex[5];
    char age[5];
    char dormitory[30];
    char phone[15];
    one_course All_course[50];
    double total_credit;
    int cousetotal;
    char grade[30];
    char College[30];
    struct student *next;
}*Linklist_student,student;

student student_array[MAXARRAY];//�������д�ȡѧ����Ϣ
Linklist_student Student_L=(Linklist_student)malloc(sizeof(student));//ѧ������ͷ���
//�γ̻�����Ϣ
typedef struct course{
   char num[15];
   char name[20];
   char imformation[200];
   int  count;//�ÿγ���ѡ������
   int Choose_student_idex[2000];//��ѧ��ѧ��ѧ��,��ʼ��ʱ����д
   int finish;
   int unpass;
   //struct course *next;
}course;//*Linklist_course,course;
course ALL_course[1000];
int Init_ALL_course_count()//�Ǹ��༶��ʼ��ʱֵΪ0
{
    for(int i=0;i<100;i++)
    {
        ALL_course[i].count=0;
       // printf("course[%d]=%d\n",i+1,ALL_course[i].count);
    }
    return OK;
}
typedef struct s{
    char num[15];
    char key[15];
}s;
s student_key_data[MAXN];//��¼ѧ������
typedef struct admin{
    char num[15];
    char key[15];
}admin;
admin admin_key_data[MAXN];//��¼ʹ��������
int student_total=0;
int student_key_total=0;
int admin_total=0;
int studenti,coursei;
int classnum;//�༶����
int course_total=0;//ѡ�޿���������
int de_num[100];//ɾ��ѧ����ѧ���±�
int de_total=0;//ɾ������
int admini;//��ǰ����Ա�������±�
int COUNTDOWN=5;//����ʱ��ʼֵ
void Init_student_keydata()//��ʼ��ѧ��������Ϣ
{
  int i=0;
  FILE *fkey=fopen("student_key.txt","r");
    while(fscanf(fkey,"%s%s",student_key_data[i].num,student_key_data[i].key)!=EOF)
    {
        decode(student_key_data[i].key);
        i++;
    }
    student_key_total=i;
    fclose(fkey);
}

void Init_admin_key_data()//��ʼ������Ա������Ϣ
{
    FILE *fkey=fopen("admin.txt","r");
    int i=0;
    while(fscanf(fkey,"%s%s",admin_key_data[i].num,admin_key_data[i].key)!=EOF)
    {
        decode(admin_key_data[i].key);//printf("%s\n",admin_key_data[i].key);
        i++;
    }
    admin_total=i;
}
int Load_student_Linklist()//��ʼ��ѧ����Ϣ
{
    printf("linllist:\n");
    Linklist_student q=Student_L;
     printf("ѧ��  ����  �Ա� ���� ������� �绰����\n");
    while(q->next){printf("%s  %s  %s   %s   %s    %s    \n",q->next->num,q->next->name,q->next->sex,q->next->age,q->next->dormitory,q->next->phone);q=q->next;}
    return 0;
}

int InitList_student_data()//���ļ������ݴ���������������
{
    FILE *fdata=fopen("student_data.txt","r");
    Linklist_student q=(Linklist_student)malloc(sizeof(student));
    Linklist_student p=Student_L;
    Student_L->next=NULL;
    //int i=0;
       while(fscanf(fdata,"%s%s%s%s%s%s%s",q->num,q->class_name,q->name,q->sex,q->age,q->dormitory,q->phone)!=EOF)
     {
         q->next=p->next; p->next=q;p=q;
         q=(Linklist_student)malloc(sizeof(student));
      //   i++;
}
Print_from_Linklist_to_array();
//Load_student_Linklist();
fclose(fdata);
return 0;
}
int Initi_course_data()//��ʼ���γ���Ϣ
{
    int i=0;
    FILE *fp=fopen("course.txt","r");
    while(fscanf(fp,"%s%s%s%d%d",ALL_course[i].num,ALL_course[i].name,ALL_course[i].imformation,&ALL_course[i].unpass,&ALL_course[i].finish)!=EOF)
    {
       // printf("%s\n",ALL_course[i].num);
      i++;
    }

    fclose(fp);course_total=i;
    return 0;

}
int Device_studentdependclass()//��ʼ��ʱ��ѧ�����༶��ͬ����
{
    classnum=0;int j;
    for(int i=0;i<student_total;i++)
    {
        for(j=0;j<=classnum;j++)
            {
                if(!strcmp(ALLCLASS[j].class_name,student_array[i].class_name)){ALLCLASS[j].student_num[ALLCLASS[j].count++]=i;break;}
           }
        if(j>classnum){ALLCLASS[classnum].count=0;strcpy(ALLCLASS[classnum].class_name,student_array[i].class_name);ALLCLASS[classnum].student_num[ALLCLASS[classnum].count++]=i;classnum++;}
    }
    //printf("classnum=%d\n",classnum);
    return 0;
}
int student_course_data_in_oneclasse()//�鿴һ���༶��ѧ�����Գɼ�
{
    for(int i=0;i<classnum;i++)
    {
        printf("                            %s\n",ALLCLASS[i].class_name);
        for(int j=0;j<ALLCLASS[i].count;j++)
        {
        int studenti=ALLCLASS[i].student_num[j];printf("ѧ��ѧ��%s\n",student_array[studenti].num);
        printf("   ���  ����  ƽʱ�ɼ�  ��ĩ�ɼ�  ƽ���ɼ�  ѧ�� \n");
         printf("--------------------------------------------------------------\n");
        for(int j=0;j<student_array[studenti].cousetotal;j++){
    printf(" %s%7s%8.1lf%10.1lf%10.1lf%8.1lf     \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[0].All_course[0].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);
        }
         printf("--------------------------------------------------------------\n");

        }
    printf("\n\n\n");


}
return 0;
}

int Device_studentdependcourse()//��ʼ��ʱ��ѧ�����γ���Ϣ����
{
    int j;
      for(j=0;j<=course_total;j++)
    {
        ALL_course[j].count=0;
       for(int i=0;i<student_total;i++)
            {   for(int k=0;k<student_array[i].cousetotal;k++)
                if(!strcmp(ALL_course[j].num,student_array[i].All_course[k].num)){
                    ALL_course[j].Choose_student_idex[ALL_course[j].count++]=i;break;}
            }
        }
    return 0;

}
int onecourse_all_student()//���һ�ֿ�Ŀ�е�����ѧ���������
{

   // printf("����γ̱��\n");//��ѯ����
   // gets(num);
     for(int i=0;i<course_total;i++)//if(!strcmp(num,ALL_course[i].num))
        {   //printf("%s\n",ALL_course[i].name);
            //printf("����     ƽʱ�ɼ�   ��ĩ�ɼ�   ƽ���ɼ�  ѧ�� \n");
            for(int j=0;j<ALL_course[i].count;j++)
            {
                int k,idex=ALL_course[i].Choose_student_idex[j];
                for( k=0;k<student_array[idex].cousetotal;k++)if(!strcmp(student_array[idex].All_course[k].name,ALL_course[i].name))break;
                //printf("%s%8.1lf%10.1lf%10.1lf%8.1lf\n",student_array[idex].name,student_array[idex].All_course[k].usual_score,student_array[idex].All_course[k].exam_score,student_array[idex].All_course[k].final_score,student_array[idex].All_course[k].credit);
            }
            //printf("\n");
        }
        return 0;
}
int Write_student_data()//��ѧ����Ϣд���ļ�
{
    FILE *fp=fopen("student_data.txt","w");int flag=0;
    for(int i=0;i<student_total;i++){
            flag=0;
    for(int j=0;j<de_total;j++)
        if(i==de_num[j]){flag=1;break;}
       if(!flag){
        fprintf(fp,"%s %s %s %s %s %s %s\n",student_array[i].num,student_array[i].class_name,student_array[i].name,student_array[i].sex,student_array[i].age,student_array[i].dormitory,student_array[i].phone);}
    }
    fclose(fp);
    return 0;
}

int Write_student_key()//��ѧ������д���ļ�
{
    FILE *fkey=fopen("student_key.txt","w");
    for(int i=0;i<=student_key_total;i++)
   {
     encrypt(student_key_data[i].key);
     fprintf(fkey,"%s  %s\n",student_key_data[i].num,student_key_data[i].key);
   }
    fclose(fkey);
    return 0;
}

int Write_admin_key()//������Ա����д���ļ�
{
    FILE *fkey=fopen("admin.txt","w");
    for(int i=0;i<=admin_total;i++)
   {
     encrypt(admin_key_data[i].key);//printf("\n%s\n",admin_key_data[i].key);
     fprintf(fkey,"%s  %s\n",admin_key_data[i].num,admin_key_data[i].key);
   }
    fclose(fkey);
    return 0;
}
int Write_student_chose_course()//��ÿ��ѧ��ѡ����Ϣ�ֱ�д���ļ�
{
    int flag;FILE *fp;char s[20];
    for(studenti=0;studenti<student_key_total;studenti++)
     {flag=0;sort_student_course();
     for(int k=0;k<de_total;k++)if(studenti==de_num[k]){flag=1;break;}
       strcpy(s,student_array[studenti].num);fp=fopen(strcat(s,".txt"),"w");if(flag)continue;
       for(int i=0;i<student_array[studenti].cousetotal;i++){
            fprintf(fp,"%s  %12s %8.1lf %10.1lf%10.1lf%8.1lf",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name,student_array[studenti].All_course[i].usual_score,student_array[studenti].All_course[i].exam_score,student_array[studenti].All_course[i].final_score,student_array[studenti].All_course[i].credit);
       if(student_array[studenti].All_course[i].IsRetake)fprintf(fp,"   %d       %s    %d",1,student_array[studenti].All_course[i].Retake_semester,student_array[studenti].All_course[i].Retake_count);
       else fprintf(fp,"     %d     %s    %d",0,"��",0);
       fprintf(fp,"     %d\n",student_array[studenti].All_course[i].fnish);
       }

        fclose(fp);
    }
    return 0;
}
int Write_course_data()
{
    FILE *fp=fopen("course.txt","w");
    for(int i=0;i<course_total;i++)
    {
        fprintf(fp,"%s   %s\n\n%s\n\n%d\t%d\n\n",ALL_course[i].num,ALL_course[i].name,ALL_course[i].imformation,ALL_course[i].unpass,ALL_course[i].finish);
    }
    fclose(fp);
    return 0;
}
int Insert_student()
{
  int flag=0,ff;
  char new_num[25],key1[15],key2[15];
  while(1){
      flag=0;ff=1;
  printf("��������Ҫע��ѧ����\n");
  if(!scan_num(new_num))break;system("CLS");
  for(int i=0;i<=student_key_total;i++)
        if(strcmp(new_num,student_key_data[i].num)==0){flag=1;break;}
        if(flag){printf("�Բ��𣬸�ѧ�����ѱ�ע�ᣬ�뻻��һ�û���\n");
        continue;
        }
   while(1)
   {
    printf("��������Ҫע�������\n");
    ff=scanf_key(key1);
    if(!ff)break;
    system("CLS");
    printf("����������Ҫע�������\n");
    if(!scanf_key(key2))continue;
    system("CLS");
    if(strcmp(key1,key2)!=0){printf("����ע�����벻һ��,��������������\n");continue;}
    else {
        flag=1;
        Linklist_student q,p=Student_L;
    q=(Linklist_student)malloc(sizeof(student));
    printf("�������ѧ�����й���Ϣ\n");//printf("------����Щ��Ϣ��ʱδ��Ҫ��д������������������#�����д���* *��ϢΪ������Ϣ��\n");
    strcpy(q->num,new_num);
    int fg=0;
    for(;!fg;)
    {
        if(!scan_class(q->class_name)){system("CLS");break;}
        else for(;!fg;)
            if(!(scan_name(q->name))){system("CLS");break;}
        else for(;!fg;)
            if(!(scan_sex(q->sex))){system("CLS");break;}
        else for(;!fg;)
            if(!(scan_age(q->age))){system("CLS");break;}
        else for(;!fg;)
             if(!(scan_dor(q->dormitory))){system("CLS");break;}
        else for(;!fg;)
             {system("CLS");if(!(scan_phone(q->phone))){system("CLS");break;}
        else fg=1;}
    }
    if(!fg)continue;
     while(p->next){
        p=p->next;
    }int fflag=0;
    while(1)
    {
    printf("������ע���ѧ����Ϣ����\n\n\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n    ѧ����       �༶       ����     �Ա�     ����      ����    �绰����\n\n");
             printf("%10s%12s%9s%7s%9s%10s%14s\n",q->num,q->class_name,q->name,q->sex,q->age,q->dormitory,q->phone);
    printf("-----------------------------------------------------------------------\n");

    printf("\n\nY:ע��ѧ��\nN:����ע��\n\n\n\n��������ѡ��   ");
    char cho;
    {
    while(1){fflush(stdin);scanf("%c",&cho);
    if(cho=='Y'||cho=='y'||cho=='N'||cho=='n'||cho=='X'||cho=='x')break;
    else printf("��������Ч������������\n");
    }
    if(cho=='Y'||cho=='y'){q->next=p->next;p->next=q;
    strcpy(student_key_data[student_key_total].num,new_num);
    strcpy(student_key_data[student_key_total].key,key1);
    student_key_total=student_key_total+1;
    strcpy(student_array[student_total].num,q->num);
    strcpy(student_array[student_total].class_name,q->class_name);
    strcpy(student_array[student_total].name,q->name);
    strcpy(student_array[student_total].sex,q->sex);
    strcpy(student_array[student_total].age,q->age);
    strcpy(student_array[student_total].dormitory,q->dormitory);
    strcpy(student_array[student_total].phone,q->phone);
    printf("ע��ɹ���\n");
    student_total++;fflag=1;
        break;
        }if(fflag)break;
        }
        if(cho=='N'||cho=='n'){fflag=1;printf("δ�ɹ�ע��\n"); break;}

        }if(fflag)break;

    }
    system("CLS");
  }
  if(!ff)continue;
  printf("�������ע�����û�\n��������Y ��������N\n");char ch;
  while(1){
      fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("������Ч\n");
      }
if(ch=='n'||ch=='N')break;
  }

   // Write_student_key();
    return OK;
}

int Delete_student_data()
{
    Linklist_student q,p=Student_L;
    char denum[15];
    while(1){printf("������Ҫɾ��ѧ����ѧ��\n");
    if(!scan_num(denum))return 0;
    while(p->next)
    {
        if(strcmp(p->next->num,denum)==0)break;
        p=p->next;
    }
    if(!p->next){printf("�޴�ѧ�������Ϣ\n");continue;}
    printf("�����������ѧ�������Ϣ\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\n    ѧ����       �༶       ����     �Ա�     ����      ����    �绰����\n\n");
    printf("%10s%12s%9s%7s%9s%10s%14s\n\n",p->next->num,p->next->class_name,p->next->name,p->next->sex,p->next->age,p->next->dormitory,p->next->phone);
    printf("--------------------------------------------------------------------------\n\n");
    printf("Y:ɾ��  N:����ɾ��\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("������Ч\n");}
    if(ch=='Y'||ch=='y')
    {   array_delete_student_key(denum);
        q=p->next;p->next=q->next;
    free(q);
    for(int i=0;i<student_total;i++)
        if(!strcmp(denum,student_array[i].num)){de_num[de_total++]=i;break;}
    printf("ɾ���ɹ���\n");
    }
    else printf("δɾ����ѧ��\n");
    printf("����ɾ�� Y ���� N\n");
    {
     char ch;
     while(1){fflush(stdin);printf("����������ѡ��\n");
     scanf("%c",&ch);
     if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("������Ч\n");}
     if(ch=='N'||ch=='n')break;
    }
    }
    return ERROR;
}
int array_delete_student_key(char *s)
{
    int i;
    for(i=0;i<student_key_total;i++)
    {
        if(strcmp(student_key_data[i].num,s)==0)break;
    }
    for(int j=i;j<student_key_total;j++)
        {
            strcpy(student_key_data[j].num,student_key_data[j+1].num);
            strcpy(student_key_data[j].key,student_key_data[j+1].key);
        }
    student_key_total-=1;
    return OK;
}

int Print_from_Linklist_to_array()
{
    Linklist_student q=Student_L->next;
    int i=0;
       while(q)
     {
         strcpy(student_array[i].num,q->num);
         strcpy(student_array[i].class_name,q->class_name);
         strcpy(student_array[i].name,q->name);
         strcpy(student_array[i].sex,q->sex);
         strcpy(student_array[i].age,q->age);
         strcpy(student_array[i].dormitory,q->dormitory);
         strcpy(student_array[i].phone,q->phone);
         q=q->next;
         i++;

}
    student_total=i;
    //printf("S_T=%d\n",student_total);
   // for(int i=0;i<student_total;i++)
   // printf("from array:%s %s %s %s %s %s\n",student_array[i].num,student_array[i].name,student_array[i].sex,student_array[i].age,student_array[i].dormitory,student_array[i].phone);
    return 0;
}

int scanf_key(char* ps)
{
    int MaxSize=80;
unsigned char ch;
while(1){printf("      (������6~12�����ֻ���ĸ����)\n");
printf("              (������һ���� * )\n");
int i=0;
int bIsEcho=TRUE;
while( ( ch = (unsigned char)getch() ) && i < MaxSize )
{
bIsEcho=TRUE;
if ( ch == 13)//�س�
{
ps[i++]=0;
break;
}
else if ( ch >= MIN_INPUT && ch <= MAX_INPUT) /*���пɴ�ӡ�ַ�*/
{
ps[i++]=ch;
}
else if ( ch == 8 && i> 0 )	/*�˸��*/
{
ps[i--] = 0;
bIsEcho = FALSE;
putchar( ch );
putchar( ' ' );
putchar( ch );
}
else
bIsEcho = FALSE;
if(bIsEcho)
putchar('*');
}
ps[i]=0;
if(!strcmp(ps,"*")){system("CLS");return 0;}
if(!R_L_K(ps)){printf("\n���볤�Ȳ���ȷ����������\n");continue;}
if(!rightful_key(ps)){printf("\n���뺬�в��Ϸ��ַ���������������\n");continue;}
system("CLS");return 1;
}
}

int Countdown_Clock()
{
	clock_t start, finish, clsfinish;
	double time_used_in_cls = 0;
	start = clock();
	system("CLS");
	clsfinish = clock();
	time_used_in_cls = double(clsfinish - start);

	int i=COUNTDOWN;
	while(i >= 0)
	{
		start = finish = clock();
		if(i ==COUNTDOWN)
			finish += time_used_in_cls;
		while(finish-start < CLOCKS_PER_SEC - time_used_in_cls)
			finish = clock();
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("                                ");
		printf("���� <%d> ���������������\n", i--);
	}
    system("CLS");
	return 1;
}
void main_printf()
{
    //printf_sin();
    printf("\n\n\n\n\n\n\n\n\n");
    printf("                                     ********************\n");
    printf("                                     ***���ڳ�ʼ������***\n");
    printf("                                     ********************\n\n\n\n\n\n\n\n");
    for(int j=0;j<89;j++)
    {
        for(int i=0;i<10000000;i++);printf("<");
    }
     INIT_ALL();
     printf("<");
    system("CLS");
}
int INIT_ALL()
{
     Initi_course_data();
     Init_ALL_course_count();
     Init_student_keydata();
     Init_admin_key_data();
     InitList_student_data();
     Init_student_choose_course_data();
     Device_studentdependclass();
     Device_studentdependcourse();
     onecourse_all_student();
     //student_course_data_in_oneclasse;
     return 0;
}
int Init_student_choose_course_data()//��ȡÿ��ѧ��ѡ�޿γ̵�����
{
    int i,studenti=0,n=student_total-1;
    char s[20];
    FILE *fp;
    while(strcpy(s,student_array[n].num),fp=fopen(strcat(s,".txt"),"r"))
    //while(fscanf(fp,"%s",student_array[0].All_course[0].num)!=EOF);
    //printf("%s",student_array[0].All_course[0].num);
    {
   // printf("student[%d]num=%s\n",n,student_array[n].num);
    student_array[n].cousetotal=0;i=0;studenti=n;student_array[n].total_credit=0;
    while(fscanf(fp,"%s%s%lf%lf%lf%lf%d%s%d%d",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name,&student_array[studenti].All_course[i].usual_score,&student_array[studenti].All_course[i].exam_score,&student_array[studenti].All_course[i].final_score,&student_array[studenti].All_course[i].credit,&student_array[studenti].All_course[i].IsRetake,student_array[studenti].All_course[i].Retake_semester,&student_array[studenti].All_course[i].Retake_count,&student_array[studenti].All_course[i].fnish)!=EOF)
    {student_array[n].total_credit+=student_array[n].All_course[i].credit;i++;}student_array[n].cousetotal=i;
    //printf("n=%d\n",n);
    //printf("i=%d\n",i);
    n--;if(n<0)break;
    //printf("i=%d\n",i);

   // printf(" student_array[student_total].cousetotal=%d\n" student_array[student_total].cousetotal);
    fclose(fp);
    }
    //for(int j=0;j<i;j++)printf("%s    %s   %.1lf   %.1lf   %.1lf   %.1lf   %d   %s   %d    %d\n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count,student_array[studenti].All_course[j].fnish);
return 0;
}

int Write_ALL()
{
   Write_admin_key();
   Write_student_data();
   Write_student_key();
   Write_student_chose_course();
   Write_course_data();
   return 1;
}

int main()
{
     main_printf();
     main_interface();
     SORT_ALL();
     //Write_ALL();
     END();
     exit_interface();
}


int main_interface()
{
    char chose;int y=28;
    if(!admin_total){
            printf("\n\n\n\n\n");
             for(int i=0;i<y;i++)printf(" ");printf("---------------------------------\n");
             for(int i=0;i<y;i++)printf(" ");printf("�״�ʹ��ϵͳ,���������Ա�����Ϣ\n");
             for(int i=0;i<y;i++)printf(" ");printf("---------------------------------\n");
    char num[20],key1[20],key2[20];
    printf("\n\n���������Ա�˺�\n");
    fflush(stdin);
    if(!scan_num(num)){printf("δ���ע��!\n");return 0;}
    while(1){
            system("CLS");
    printf("���������Ա����\n");
    if(!scanf_key(key1)){printf("δ���ע��!\n");return 0;}
    system("CLS");
    printf("\n���ٴ��������Ա����\n");
    if(!scanf_key(key2))continue;
    if(!strcmp(key1,key2))break;
    printf("\n�����������벻ͬ����ȷ�Ϻ�����������\n");
    }
    printf("\n������ע��Ĺ���Ա�˺�Ϊ%s   ����Ϊ  %s\nȷ���밴Y   �����밴N\n",num,key1);char ch;
    while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("������Ч\n");}
    if(ch=='Y'||ch=='y'){
        strcpy(admin_key_data[admin_total].num,num);
        strcpy(admin_key_data[admin_total++].key,key2);
        system("CLS");printf("\n\n\n\n");
        if(!course_total||!student_total)
        {
                           for(int i=0;i<44;i++)printf(" ");printf("-----------------------------------\n");
        if(!student_total){for(int i=0;i<44;i++)printf(" ");printf("����ϵͳ����ѧ������ȥע��ɣ�\n");}
        if(!course_total){ for(int i=0;i<44;i++)printf(" ");printf("����ϵͳ������ѡ�޿Σ���ȥ�������ɣ�\n");}
                           for(int i=0;i<44;i++)printf(" ");printf("-----------------------------------");
        }
    }
    else return 0;
    }
    while(1)
    {

        printf("\n\n\n\n\n");
        for(int i=0;i<y;i++)printf(" ");printf("-----------------------------------\n");
        for(int i=0;i<y;i++)printf(" ");printf("---          1:ѧ����½         ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---          2:����Ա��½       ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---          *:�˳�ϵͳ         ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("-----------------------------------\n");
        printf("\n\n\n\n\n\n\n\n");
        {
        while(1){char ch;printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='2')||ch=='*'){chose=ch;break;}
        else printf("��������Ч\n");}
        }
        switch(chose)
        {
           case '1':if(student_total){system("CLS");int y=35;
                  printf("\n");
                  for(int i=0;i<y;i++)printf(" "); printf("******************\n");
                  for(int i=0;i<y;i++)printf(" "); printf("***  ѧ����½  ***\n");
                  for(int i=0;i<y;i++)printf(" "); printf("******************\n\n\n");
                   if(!student_login()){system("CLS");break;}
                  if(!student_login_interface())
                  {return 1;}
           }else {
           printf("�Բ���ϵͳ����ά���У��ݲ����ã�\n");
           }
                  break;

           case '2':system("CLS");int y1;
                  printf("\n");y1=37;
                  for(int i=0;i<y1;i++)printf(" "); printf("********************\n");
                  for(int i=0;i<y1;i++)printf(" "); printf("***  ����Ա��½  ***\n");
                  for(int i=0;i<y1;i++)printf(" "); printf("********************\n\n\n");
                  if(!admin_login()){system("CLS");break;}
                  if(!admin_interface())
                  {return 1;}
                  break;
           case '*':return 1;
        }
    }
}
int student_login_interface()
{
    int flag=0;char chose;int y=17;
    welcome_interface();
    while(1)
    {
        for(int i=0;i<7;i++)printf("\n");
        if(flag){system("CLS");printf("�����벻�Ϸ�������������\n");flag=0;}
        for(int i=0;i<y;i++)printf(" ");printf("---------------------------------------------------------\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               1:���˻�����Ϣ�Ĳ鿴���޸�          ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               2:ѡ�޿μ��������                  ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               3:�鿴ȫ��ͬѧ�Ŀ������            ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               4:�鿴��ѡѡ�޿�ȫ�࿼�����        ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               0:���ص�¼����                      ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               *:�˳�ϵͳ                          ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---------------------------------------------------------\n\n\n\n");
        {
        while(1){char ch;printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='4')||ch=='*'){chose=ch;break;}
        else printf("��������Ч\n");}
        }
        switch(chose)
        {
           case '1':system("CLS");
                  printf("���˻�����Ϣ�Ĳ鿴���޸�\n");
                  if(!student_base_data_interface()){system("CLS");return 0;}
                  system("CLS");break;
           case '2':system("CLS");
                  //printf("ѡ�޿μ��������\n");
                  printf("                     %s     %s   ͬѧ����ѡ�޿εĿ������\n",student_array[studenti].class_name,student_array[studenti].name);
                  printf("   -----------------------------------------------------------------------------------");
                  student_choose_class_data();student_total_credit();system("pause");system("CLS");break;
           case '3':system("CLS");
                  printf("�鿴ȫ��ͬѧ�Ŀ������\n");
                   for(int i=0;i<classnum;i++)if(!strcmp(ALLCLASS[i].class_name,student_array[studenti].class_name))
       {
        printf("                            %s\n",ALLCLASS[i].class_name);
        for(int j=0;j<ALLCLASS[i].count;j++)
        {
        int studenti=ALLCLASS[i].student_num[j];//if(!student_array[studenti].cousetotal)continue;
        printf("ѧ����:%s\n",student_array[studenti].num);
        printf("   ���    ����   ƽʱ�ɼ�   ��ĩ�ɼ�   ƽ���ɼ�   ѧ�� \n");
        printf("--------------------------------------------------------------\n");
        for(int j=0;j<student_array[studenti].cousetotal;j++){
                if(!student_array[studenti].All_course[j].fnish)continue;
    printf(" %s%8s%9.1lf%12.1lf%10.1lf%9.1lf     \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);
        }
         printf("--------------------------------------------------------------\n\n");

        }
    printf("\n");}system("pause");system("CLS");
                  break;
           case '4':system("CLS");int i;
                  printf("�鿴��ѡѡ�޿�ȫ�࿼�����\n");
                  while(1){
                  printf("��������ѡ������ѡ�޿�����\n");
                  printf("----------------\n");
                  for( i=0;i<student_array[studenti].cousetotal;i++)
                  {printf("%s      %s ",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);
                  if(!student_array[studenti].All_course[i].fnish)printf("(δ�гɼ���Ϣ)\n");
                  else printf("\n");
                  }
                  printf("----------------\n");
                  printf("������������ҵĿγ̱��\n");
                  char s[20];fflush(stdin);if(!scan_course_num(s))break;
                  for( i=0;i<student_array[studenti].cousetotal;i++)
                  if(!strcmp(s,student_array[studenti].All_course[i].num))break;
                  if(i>=student_array[studenti].cousetotal){printf("�Բ���δ�ҵ��ÿγ�!\n");}
                  else{
                      int m;
                      for(m=0;m<course_total;m++)
                        if(!strcmp(ALL_course[m].num,s))break;
                      if(!ALL_course[m].finish)
                    if(!student_array[studenti].All_course[i].fnish)
                    {printf("�Բ���ÿ�Ŀ��δ�п��Գɼ���Ϣ����δ��ȫ¼����ϣ��ݲ��ɲ�ѯ\n");
                      printf("��������������Ŀ��Y  ������N\n");
                    {char cho;while(1){fflush(stdin);scanf("%c",&cho);
                if(cho=='Y'||cho=='y'||cho=='N'||cho=='n'||cho=='X'||cho=='x')break;
                else printf("��������Ч������������\n");}
                if(cho=='Y'||cho=='y'){system("CLS");continue;}
                else break;
                    }
                      }system("CLS");
                  printf("\n\n  �γ�����: %s      ��ѡ����: %d\n",ALL_course[i].name,ALL_course[i].count);
                  printf("----------------------------------------------------\n");
                  printf("   ����     ƽʱ�ɼ�   ��ĩ�ɼ�   ƽ���ɼ�   ѧ�� \n");
                  for(int j=0;j<ALL_course[i].count;j++)
                {
                int k,idex=ALL_course[i].Choose_student_idex[j];
                for( k=0;k<student_array[idex].cousetotal;k++)if(!strcmp(student_array[idex].All_course[k].name,ALL_course[i].name))break;
                  printf(" %8s%10.1lf%10.1lf%10.1lf%9.1lf\n",student_array[idex].name,student_array[idex].All_course[k].usual_score,student_array[idex].All_course[k].exam_score,student_array[idex].All_course[k].final_score,student_array[idex].All_course[k].credit);
                }
                  printf("----------------------------------------------------\n");
                printf("\n");}
                printf("��������������Ŀ��Y  ������N\n");
                char cho;while(1){fflush(stdin);scanf("%c",&cho);
                if(cho=='Y'||cho=='y'||cho=='N'||cho=='n'||cho=='X'||cho=='x')break;
                else printf("��������Ч������������\n");}
                if(cho=='Y'||cho=='y'){system("CLS");continue;}
                else break;
                }system("pause");system("CLS");
                break;
           case '*':return 0;
           case '0':system("CLS");return 1;
           default :flag=1;break;//printf("�����벻�Ϸ�������������\n");
        }
    }
}
void personal_base_information()
{
    int i=studenti;
    printf("\n    ѧ����       �༶       ����     �Ա�     ����      ����    �绰����\n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("%10s%12s%9s%7s%9s%10s%14s\n",student_array[i].num,student_array[i].class_name,student_array[i].name,student_array[i].sex,student_array[i].age,student_array[i].dormitory,student_array[i].phone);
    printf("--------------------------------------------------------------------------\n\n\n");
}
void student_choose_class_data()
{
printf("\n\n\n\n   ���      ����    ƽʱ�ɼ�  ��ĩ�ɼ�  ƽ���ɼ�  ѧ��   �Ƿ�����   ����ѧ��   ���޴���\n");
    for(int j=0;j<student_array[studenti].cousetotal;j++){
    if(!student_array[studenti].All_course[j].fnish)continue;
    printf("----------------------------------------------------------------------------------------\n");
    printf(" %s %8s  %8.1lf%10.1lf%10.1lf%8.1lf     ",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);

      if(student_array[studenti].All_course[j].IsRetake)
    {
        printf("��     %s      %d\n",student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);}
        else printf("��         ��         ��\n");

    }
    printf("---------------------------------------------------------------------------------------\n");

//  printf("%s    %s   %.1lf   %.1lf   %.1lf   %.1lf \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[0].All_course[0].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);

    //printf("tatatt=%d\n",student_array[studenti].cousetotal);
}
void student_total_credit()
{
    printf("\n\n                                                               ����ѧ��: ");
    printf("%.2lf\n",student_array[studenti].total_credit);
    printf("---------------------------------------------------------------------------------------\n");
    printf("�������ѡ�޿�\n�γ̱��        �γ�����     �ۺϳɼ�\n");
    for(int i=0;i<student_array[studenti].cousetotal;i++)
        if(!student_array[studenti].All_course[i].fnish)continue;
        else if(student_array[studenti].All_course[i].final_score<60)
    {               printf("-------------------------------------\n");
         printf("%s\t\t%s\t\t%.1lf   \n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name,student_array[studenti].All_course[i].final_score);
    }
                    printf("-------------------------------------\n");
         printf("\n\n\n");

            printf("���޳ɼ���ѡ�޿�\n");
            printf(" �γ̱��        �γ�����\n");
    for(int i=0;i<student_array[studenti].cousetotal;i++)
        if(!student_array[studenti].All_course[i].fnish)
        {   printf("---------------------------\n");
            printf(" %s            %s\n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);
        }
            printf("---------------------------\n");
printf("\n\n");

}
int student_base_data_interface()
{
   // printf("���˻�����Ϣ�Ĳ鿴���޸�\n");
    //personal_base_information();
    int keyflag;char news1[20],news2[20],s[20];
    while(1)
    {
        system("CLS");personal_base_information();
        char ch;fflush(stdin);
        printf("1:�����޸�   2:�޸��ֻ�����   0:�����ϸ�����   *:�˳�ϵͳ\n\n\n");
        while(1){
                fflush(stdin);printf("����������ѡ��\n");
        scanf("%c",&ch);if(ch>='1'||ch<='2'||ch=='*')break;
        else printf("������Ч\n");}

        switch(ch)
        {
           case '1':system("CLS");
                  while(1){keyflag=0;
                  printf("������ԭ����\n");
                  fflush(stdin);
                  int p=Input_key(student_key_data[studenti].key);
                  if(p==2)break;
                  if(p==1)
                  while(1)
                  {system("CLS");
                  printf("������������\n");
                  scanf_key(news1);system("CLS");
                  printf("���ٴ�����������\n");
                  scanf_key(news2);system("CLS");
                  if(!strcmp(news1,news2)){strcpy(student_key_data[studenti].key,news1);printf("�޸�����ɹ�\n");keyflag=1;system("pause"); break;}
                  else {printf("�����������벻ͬ�����ٴ�����\n");continue;}
                  }
                  if(keyflag)break;
                  else {system("CLS");printf("ԭ���벻��ȷ����ȷ�Ϻ��ٴ�����\n");continue;}
                  }
                  break;
           case '2':while(1){//int pchose=0;if(pchose!=0||pchose!=1)printf("��������Ч,����������\n");
                  system("CLS");printf("ԭ�ֻ�����Ϊ��%s\n",student_array[studenti].phone);
                  printf("���������ֻ�����\n");
                  fflush(stdin);if(!scan_phone(s))break;system("CLS");
                  printf("ȷ�Ͻ�ԭ�����ֻ��ţ�%s\n��Ϊ���ֻ���:%s\n��������Y����������N\n",student_array[studenti].phone,s);
                while(1){
                fflush(stdin);printf("����������ѡ��\n");
                scanf("%c",&ch);if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
                else printf("������Ч\n");}
                  if(ch=='Y'||ch=='y'){strcpy(student_array[studenti].phone,s);printf("�޸��ֻ�����ɹ�\n");break;}
                  else {printf("�ֻ�����δ�޸ĳɹ�\n");break;}
                  }system("pause");
                  break;
          // case 3:printf("����\n");break;
           case '*':return 0;
           case '0':system("CLS");return 1;
        }
    }
}
int admin_interface()
{
    welcome_interface();
    char  chose;int flag=0;
    while(1)
    {if(!course_total||!student_total)
        {
                 for(int i=0;i<35;i++)printf(" ");printf("��ܰ��ʾ:-----------------------------------\n");
        if(!student_total){for(int i=0;i<44;i++)printf(" ");printf("����ϵͳ����ѧ������ȥע��ɣ�\n");}
        if(!course_total){ for(int i=0;i<44;i++)printf(" ");printf("����ϵͳ������ѡ�޿Σ���ȥ�������ɣ�\n");}
                           for(int i=0;i<44;i++)printf(" ");printf("-----------------------------------");
        }
    else {
for(int i=0;i<52;i++)printf(" ");printf("ϵͳ��Ϣ-----------------\n");
        for(int i=0;i<60;i++)printf(" ");printf("��ע��ѧ������ %d \n",student_total);
        for(int i=0;i<60;i++)printf(" ");printf("���е�ѡ�޿γ� %d \n",course_total);
        for(int i=0;i<60;i++)printf(" ");printf("���еİ༶���� %d \n",classnum);
        for(int i=0;i<60;i++)printf(" ");printf("-----------------\n");
    }
        printf("\n\n\n");int y=15;
        if(flag){system("CLS");printf("�����벻�Ϸ�������������\n");flag=0;}
        for(int i=0;i<y;i++)printf(" ");printf("-------------------------------------------------------------\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               1:ѧ��ע����¼��ѧ��������Ϣ            ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               2:��ѧ��¼��ѡ����Ϣ                    ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               3:¼��γ̻�����Ϣ�Ϳ������            ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               4:�鿴���޸�ѧ��������Ϣ                ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               5:�鿴ѧ������ѧ�ֺ͸��γ̲�����ѧ������---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               6:�鿴ѧ���������                      ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               7:�޸Ĺ���Ա����                        ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               8:���ӻ�ɾ��ĳ��ѡ�޿�                  ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               9:ɾ��ѧ��                              ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               0:���ص�½����                          ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               *:�˳�ϵͳ                              ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("-------------------------------------------------------------\n");
        //printf("9:ע��ĳѧ���˺ż���Ϣ\n0:����������\n9:�˳�ϵͳ\n");
         {
        while(1){char ch;printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='9')||ch=='*'){chose=ch;break;}
        else printf("��������Ч\n");}
        }
        switch(chose)
        {
           case '1':system("CLS");
                  for(int i=0;i<32;i++)printf(" ");printf("ѧ��ע����¼��ѧ��������Ϣ\n");
            printf("    ---------------------------------------------------------------------------------\n");
                  Insert_student();
                  break;
           case '2':system("CLS");if(!student_total){printf("����ϵͳ��û��ѧ����Ϣ����ȥע��ɣ�\n");break;}
              if(!course_total){printf("����ϵͳ������ѡ�޿Σ���ȥ�������ɣ�\n");break;}
           printf("                                    ��ѧ��¼��ѡ����Ϣ\n");
           printf("    ---------------------------------------------------------------------------------\n");
           input_student_imformation_of_course();break;
           case '3': if(!course_total){system("CLS");printf("����ϵͳ������ѡ�޿Σ���ȥ�������ɣ�\n");break;}
                    input_grade();
                    break;

           case '4':system("CLS");if(!student_total){printf("����ϵͳ��û��ѧ����Ϣ����ȥע��ɣ�\n");break;}

           modification_student_data();system("CLS");
           break;
           case '5':system("CLS");if(!student_total){printf("����ϵͳ��û��ѧ����Ϣ����ȥע��ɣ�\n");break;}
           Total_Credit_Unpass();system("CLS");break;
           case '6':Look_over_scores();break;

           case '7':modification_admin_key();break;
           case '8':add_delete_course(); system("CLS"); break;
           case '9':system("CLS");for(int i=0;i<28;i++)printf(" ");printf("       ɾ��ѧ����Ϣ\n");
           printf("    -------------------------------------------------------------------------\n");
           Delete_student_data();break;
           case '*':return 0;
           case '0':system("CLS");return 1;
           default :flag=1;break;//printf("�����벻�Ϸ�������������\n");

        }
    }
}
int admin_student_base_data_interface()
{
     char  chose;int flag=0;
     char s[20];
     printf("�������޸�ѧ����ѧ���Ż�����\n");
     gets(s);gets(s);
     system("CLS");
    while(1)
    {
        if(flag){system("CLS");printf("�����벻�Ϸ�������������\n");flag=0;}
        printf("1:�޸�����\n2:�޸��Ա�\n3:�޸�ѧ��\n4:�޸�����\n5:�޸������\n6:�޸ĵ绰����\n0:�����Ͻ���\n*:�˳�ϵͳ\n");
        {
        while(1){char ch;printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='6')||ch=='*'){chose=ch;break;}
        else printf("��������Ч\n");}
        }
        switch(chose)
        {
           case '1':system("CLS");
                  printf("������������\n");
                  gets(s);gets(s);printf("�޸ĳɹ�\n");break;
           case '2':system("CLS");
                  printf("�������Ա�\n");
                  gets(s);gets(s);printf("�޸ĳɹ�\n");break;
           case '3':system("CLS");
                  printf("������ѧ��\n");
                  gets(s);gets(s);printf("�޸ĳɹ�\n");break;
           case '4':system("CLS");
                  printf("������������\n");
                  gets(s);gets(s);printf("�޸ĳɹ�\n");break;
           case '5':system("CLS");
                  printf("�������������\n");
                  gets(s);gets(s);printf("�޸ĳɹ�\n");break;
           case '6':system("CLS");
                 printf("�������µ绰��\n");
                 gets(s);gets(s);printf("�޸ĳɹ�\n");break;
           case '*':return 0;
           case '0':system("CLS");return 1;
           default :flag=1;break;//printf("�����벻�Ϸ�������������\n");
        }
    }
}
int exit_interface()
{
    int i,j;
    system("CLS");char s[100]="Designed By Chen M L";
    char a[100]="<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<��лʹ�ý���ϵͳ>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    printf("\n\n\n\n\n\n\n\n\n\n");
    int x=strlen(a),b=strlen(s);
    for(i=0;i<x;i++)
    {
        for(int j=0;j<10000000;j++);
        putchar(a[i]);
    }
    printf("\n\n\n\n\n\n\n");
                            printf("                                                             ");
    for(i=0;i<b;i++)
    {
        for(j=0;j<20131400;j++);
        putchar(s[i]);
    }
    printf("\n\n");
    return 0;

}


int student_login()
{
    int flag=0;
    char key[15],num[15];int count=4;
while(1){
    while(1)
{   printf("���������֤������\n");
    if(!scan_num(num))return 0;
    system("CLS");
    flag=0;
    for(int i=0;i<student_key_total;i++)
    if(strcmp(num,student_key_data[i].num)==0){strcpy(key,student_key_data[i].key);flag=1;studenti=i;break;}
    if(!flag)printf("��ѧ����Ч����ȷ�Ϻ�������ѧ��\n");
    else break;
}
int p;
while(1){
printf("���������룺\n");
 while(1)
 {
     p=Input_key(key);
     if(!p){
     system("CLS");
     printf("�������\n�㻹��%d�λ�����������,���ٴ�ȷ�Ϻ���������������\n",--count);
     if(!count){
            if(COUNTDOWN>20){system("CLS");p=3;printf("\n\n\n\n\n\n\n\n                           �뵽�����һ������ַ��ص�½����\n");for(int i=0;i<2000000000;i++);break;}
            printf("�Բ���������  %d ������������\n",COUNTDOWN);Countdown_Clock();COUNTDOWN+=5;count=4;break;}
 }

 if(p==2)break;
    if(p==1) {system("CLS");COUNTDOWN=5;return 1;}
 }system("CLS");if(p==2||p==3)break;
}if(p==2){system("CLS");continue;}
if(p==3)break;
}
return 0;
}

int admin_login()
{
    int flag=0;
    char key[15],num[15];int count=4;
while(1){
    while(1)
{   printf("���������֤������\n");
    if(!scan_num(num))return 0;
    system("CLS");
    flag=0;
    for(int i=0;i<admin_total;i++)
    if(strcmp(num,admin_key_data[i].num)==0){strcpy(key,admin_key_data[i].key);admini=i;flag=1;break;}
    if(!flag)printf("��֤������Ч����ȷ�Ϻ�������֤����\n");
    else break;
}int p;
while(1){
printf("���������룺\n");
 while(1)
 {  p=Input_key(key);
     if(!p){
     system("CLS");
     printf("�������\n�㻹��%d�λ�����������,���ٴ�ȷ�Ϻ���������������\n",--count);
     if(!count){printf("�Բ���������  %d ������������\n",COUNTDOWN);Countdown_Clock();COUNTDOWN=2*COUNTDOWN;count=4;break;}
 }
 if(p==2)break;
 if(p==1){system("CLS");COUNTDOWN=5;return 1;}

 }if(p==2)break;
 system("CLS");
}if(p==2){system("CLS");continue;}
}
}

int Input_key(char *key)
{
   int MaxSize=80;
   unsigned char ch;
   char ps[MaxSize];
  printf("      (�˳����벢���ط�����һ����  *  )\n");
  while(1)
  {

 int i=0;
int bIsEcho=TRUE;
while( ( ch = (unsigned char)getch() ) && i < MaxSize )
{
bIsEcho=TRUE;
if ( ch == 13)//�س�
{
ps[i++]=0;
break;
}
else if ( ch >= MIN_INPUT && ch <= MAX_INPUT) /*���пɴ�ӡ�ַ�*/
{
ps[i++]=ch;
}
else if ( ch == 8 && i> 0 )	/*�˸��*/
{
ps[i--] = 0;
bIsEcho = FALSE;
putchar( ch );
putchar( ' ' );
putchar( ch );
}
else
bIsEcho = FALSE;
if(bIsEcho)
putchar('*');
}
ps[i]=0;
  if(!strcmp(ps,"*"))return 2;
  if(strcmp(key,ps)==0)return 1;
  return 0;
  printf("\n");
  }
}
void welcome_interface()
{int y;
for(int i=1;i<12;i++) printf("\n");
char s[100]="<<<<<<<<<<<<<<<<<<<��ӭ��½����ϵͳ>>>>>>>>>>>>>>>>>>>\n";
y=strlen(s);
 printf("                  ");
 for(int i=0;i<y;i++){for(int j=0;j<=10000000;j++);printf("%c",s[i]);}
  for(int i=1;i<12;i++) printf("\n");
 for(int j=0;j<=300000000;j++);
 system("CLS");
}

int modification_student_data()
{
    char num[20];int i,aa;
    while(1){
             for(int j=0;j<33;j++)printf(" ");
           printf("�޸�ѧ��������Ϣ\n");
           printf("    -----------------------------------------------------------------------------\n");
            aa=0;
            printf("����ѧ��ѧ��\n");
    fflush(stdin);if(!scan_num(num))break;
    for(studenti=0;studenti<student_total;studenti++)
        if(!strcmp(num,student_array[studenti].num))break;
        if(studenti>=student_total){system("CLS");printf("δ�ҵ���ѧ��,����������ѧ��\n");continue;}
        system("CLS");
    while(1)
    {   printf("\n\n ������Ϊ  %s      %s  ͬѧ�޸������Ϣ\n\n\n\n",student_array[studenti].num,student_array[studenti].name);
        printf("\n1:�޸�����     2:�޸�����������Ϣ    *:������һ����\n\n\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);
    if(ch=='1'||ch=='2'||ch=='*')break;
    else printf("��������Ч������������\n");
    }
    if(ch=='*'){aa=1;break;}
    switch(ch)
    {
        case '1':system("CLS");
            for(i=0;i<student_key_total;i++)
            if(!strcmp(num,student_key_data[i].num))break;
                studenti=i;if(!modification_student_key()){continue;}
                break;
        case '2':system("CLS");
               for(i=0;i<student_total;i++)
                if(!strcmp(num,student_array[i].num))break;
                studenti=i;if(!modification_student_basic_data())continue;
                break;
    }
printf("�����޸� Y  �����޸� N\n");
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
        else printf("��������Ч\n");}
        if(ch=='N'||ch=='n')break;
    }if(aa){system("CLS");continue;}
    printf("\n\n�Ƿ�����޸�����ѧ����Ϣ\n");
   printf("�����޸� Y  �����޸� N\n");
    {   char ch;
        while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
        else printf("��������Ч\n");}
        if(ch=='N'||ch=='n')break;
    }
    }
    return 0;
}
int modification_student_basic_data()
{

    char name[20],clas[20],num[20],dor[20],phone[20],age[20],sex[20];
     while(1){int ff;int fflag=0;
    printf("Ҫ�޸ĵ�ѧ����Ϣ����\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n    ѧ����       �༶       ����     �Ա�     ����      ����    �绰����\n\n");
    printf("%10s%12s%9s%7s%9s%10s%14s\n",student_array[studenti].num,student_array[studenti].class_name,student_array[studenti].name,student_array[studenti].sex,student_array[studenti].age,student_array[studenti].dormitory,student_array[studenti].phone);
    printf("-----------------------------------------------------------------------\n");
        printf("\n1:�޸�ѧ��       2:�޸�����       3:�޸İ��     4:�޸��Ա�\n5:�޸�����       6:�޸������     7:�޸ĵ绰��   *:������һ���� \n");
        char ch;fflush(stdin);while(1){fflush(stdin);printf("����������ѡ��\n");scanf("%c",&ch);if(ch>='1'||ch<='7')break;else printf("������Ч\n");}
        switch(ch)
        {
            case '1':while(1){ff=0;printf("��������ѧ��\n");
                scan_num(num);
        for(int i=0;i<=student_key_total;i++)
        if(strcmp(num,student_key_data[i].num)==0){ff=1;break;}
        if(ff){printf("�Բ��𣬸�ѧ�����ѱ�ע�ᣬ�뻻��һ�û���\n");continue;}
        else {strcpy(student_array[studenti].num,num);printf("�޸ĳɹ�\n");break;}
        }break;
            case '2':printf("������������\n");scanf("%s",name);strcpy(student_array[studenti].name,name);printf("�޸ĳɹ�\n");break;
            case '3':printf("�������°��\n");scanf("%s",clas);strcpy(student_array[studenti].class_name,clas);printf("�޸ĳɹ�\n");break;
            case '4':printf("�������Ա�\n");scanf("%s",sex);strcpy(student_array[studenti].sex,sex);printf("�޸ĳɹ�\n");break;
            case '5':printf("����������\n");scanf("%s",age);strcpy(student_array[studenti].age,age);printf("�޸ĳɹ�\n");break;
            case '6':printf("�������������\n");scanf("%s",dor);strcpy(student_array[studenti].dormitory,dor);printf("�޸ĳɹ�\n");break;
            case '7':printf("�������µ绰��\n");scan_num(phone);strcpy(student_array[studenti].phone,phone);printf("�޸ĳɹ�\n");break;
            case '*':{system("CLS");return 0;}
        }
        printf("-----------------------------------------------------------------------\n");
        printf("\n    ѧ����       �༶       ����     �Ա�     ����      ����    �绰����\n\n");
        printf("%10s%12s%9s%7s%9s%10s%14s\n",student_array[studenti].num,student_array[studenti].class_name,student_array[studenti].name,student_array[studenti].sex,student_array[studenti].age,student_array[studenti].dormitory,student_array[studenti].phone);
        printf("-----------------------------------------------------------------------\n");
        printf("�����޸�:Y\n�˳��޸�:N\n����������ѡ��");
        {
        while(1){char ch;printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y')break;
        if(ch=='N'||ch=='n'){fflag=1;break;}
        else printf("������Ч\n");}

        }
        if(fflag)break;
        }
        return 1;
}
int modification_student_key()
{
    char key1[20],key2[20];
    int flag=0;
    while(1)
    {
        printf("����������������\n");
        fflush(stdin);if(!scanf_key(key1))return 0;
        fflush(stdin);printf("\n���ٴ���������������\n");if(!scanf_key(key2))continue;
        if(strcmp(key1,key2)){printf("\n�����������벻һ��,����������\n");flag=0;}
        else flag=1;
        if(flag){strcpy(student_key_data[studenti].key,key1);break;}
    }
     printf("\n�뱣����������룡\n����������Ϊ ");
    printf("%s\n",key1);
    return 1;
}

int input_student_imformation_of_course()
{
    char num[20],counum[20];int i;int fff;

    while(1){printf("\n\n\n������Ҫ¼�������Ϣ��ѧ��ѧ��\n");
    fflush(stdin);if(!scan_num(num))return 0;
    for(i=0;i<student_key_total;i++)
        if(!strcmp(num,student_key_data[i].num)){studenti=i;break;}
        if(i>=student_key_total){printf("δ�ҵ���ѧ��\n");continue;}
        studenti=i;
     while(1){ fff=0; printf("������Ϊ %s  ͬѧ¼��ѡ����Ϣ\n",student_array[studenti].name);
     printf("����ѡ�޿εı�ż�����\n");
     for(int j=0;j<course_total;j++)
     printf("%s   %s\n",ALL_course[j].num,ALL_course[j].name);
     int flag=0;
     printf("������ѡ�޿α��\n");
     fflush(stdin);fff=scan_course_num(counum);
     if(!fff){system("CLS");break;}
     if(!repeat_course(counum)){system("CLS");printf("��ѧ���Ѿ�ע���˸ÿγ̣��������ظ�ע��\n");continue;}
     for(i=0;i<course_total;i++)if(!strcmp(counum,ALL_course[i].num)){flag=1;break;}
     if(flag){
     printf("ȷ����ѧ��  %s   ��ӿγ�  %s     %s\nȷ��:Y  ����:N\n",student_array[studenti].name,ALL_course[i].num,ALL_course[i].name);
    {char ch;
     while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
     if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
     else printf("������Ч\n");}
    if(ch=='Y'||ch=='y'){
       student_array[studenti].All_course[student_array[studenti].cousetotal].credit=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].usual_score=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].exam_score=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].final_score=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].IsRetake=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].Retake_count=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].fnish=0;
       strcpy(student_array[studenti].All_course[student_array[studenti].cousetotal].Retake_semester,"��");
       strcpy(student_array[studenti].All_course[student_array[studenti].cousetotal].num,counum);
       ALL_course[i].finish=0;
       ALL_course[i].Choose_student_idex[ALL_course[i].count++]=studenti;
       strcpy(student_array[studenti].All_course[student_array[studenti].cousetotal++].name,ALL_course[i].name);

       printf("��ӳɹ�\n");
        }
     }
     }
    else  {system("CLS");printf("�����ڸÿγ̣�����������γ̱��\n");}
    printf("�������:Y  �������:N\n");{char ch;
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    break;else printf("������Ч\n");}
    if(ch=='N'||ch=='n')break;
     }
     }if(!fff)continue;
     printf("�Ƿ����Ϊ����ѧ��¼��ѡ�޿�\n");
     printf("Y ����¼��  N ����¼��\n");
     {  char ch;
         while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    break;else printf("������Ч\n");}
    if(ch=='N'||ch=='n')break;
     }
     }
    //for(i=0;i<student_array[studenti].cousetotal;i++)
        //printf("%s   %s\n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);
        return 0;
}

int input_student_grade_imformation_of_course()
{
    while(1){printf("������¼����Ϣ��ѧ��ѧ��\n");
                  char num[20];int i,pp=1,fflag=0;
                  fflush(stdin);if(!scan_num(num))break;
        for(i=0;i<student_key_total;i++)
        if(!strcmp(num,student_key_data[i].num))break;
        if(i>=student_key_total){printf("δ�ҵ���ѧ��\n");continue;}
        studenti=i;
    char counum[20],s[20];
    int flag=0,course_flag=0;
    double u,e,cre;
    while(1){fflag=0;course_flag=0;
    for(i=0;i<student_array[studenti].cousetotal;i++)
    if(!student_array[studenti].All_course[i].fnish)
    {course_flag=1;break;}
    if(!course_flag){printf("��ͬѧ���пγ̳ɼ���Ϣ��¼����ϣ������ٴ�¼��\n");break;}
     printf("����δ¼��ɼ��Ŀγ̱�ź�����\n");
    for(i=0;i<student_array[studenti].cousetotal;i++)
    if(!student_array[studenti].All_course[i].fnish)
    {printf("%s    %s\n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);}
    printf("����Ҫ����ɼ��Ŀγ̱��\n");flag=0;
    pp=scan_course_num(counum);
    if(!pp)break;
    for(i=0;i<student_array[studenti].cousetotal;i++)if(!strcmp(student_array[studenti].All_course[i].num,counum))break;
    if(i>=student_array[studenti].cousetotal){printf("�Բ��𣬸�ѧ��δ�д�ѡ�޿�\n");return 0;}
    printf("������Ϊ  %s  ¼��   %s  ��Ŀ�ĳɼ���ѡ�����\n",student_array[studenti].name,student_array[studenti].All_course[i].name);
    int fg=0;
    for(;!fg;)
    {
        printf("������ƽʱ�ɼ�\n");
        if(!scan_score(u))break;
        else for(;!fg;)
        {
            printf("��������ĩ�ɼ�\n");
            if(!scan_score(e))break;
            else for(;!fg;){
                printf("����������ѧ��\n");
                if(!scan_credit(cre))break;
                else fg=1;
            }
        }
    }
if(!fg){system("CLS");continue;}
    printf("�������Ƿ�����\n����Y  ������N\n");
     {char ch;
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')flag=1;break;}else printf("������Ч\n");}
    }
    if(flag)
    {
        fflush(stdin);
        printf("����������ѧ�ڣ���ʽ��2013~2014��\n");
        gets(s);
    }
    printf("����Ϊ %s ͬѧ %s  ��Ŀ¼��������Ϣ\n",student_array[studenti].name,student_array[studenti].All_course[i].name);
    printf("  ���  ����  ƽʱ�ɼ�  ��ĩ�ɼ�  ƽ���ɼ�  ѧ��   �Ƿ�����   ����ѧ��   ���޴���\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("%s%7s%8.1lf%10.1lf%10.1lf%8.1lf     ",counum,student_array[studenti].All_course[i].name,u,e,(e+u)/2,cre);
      if(flag)
    {
        printf("��     %s      %d\n",s,student_array[studenti].All_course[i].Retake_count+1);}
        else printf("��         ��         ��\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("ȷ��������Y  ��������N\n");

char ch;
    {
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("������Ч\n");}
    if(ch=='N'||ch=='n')printf("�γ������Ϣδ¼��\n");
    if(ch=='Y'||ch=='y')
    {
        student_array[studenti].All_course[i].usual_score=u;
        student_array[studenti].All_course[i].exam_score=e;
        student_array[studenti].All_course[i].final_score=(u+e)/2;
         {
        int m;for(m=0;m<course_total;m++)
        if(!strcmp(ALL_course[m].num,student_array[studenti].All_course[i].num))break;
        if((u+e)/2<60)ALL_course[m].unpass=1;
        else ALL_course[m].unpass=0;}
        student_array[studenti].All_course[i].credit=cre;
        student_array[studenti].All_course[i].fnish=1;
        if(flag)
    {
        student_array[studenti].All_course[i].IsRetake=1;
        student_array[studenti].All_course[i].Retake_count++;
        strcpy(student_array[studenti].All_course[i].Retake_semester,s);
    }

       printf("¼��ɼ��ɹ�\n");
    }

    }

    printf("����¼�� %s ͬѧ��������Ŀ�ɼ�Y  ����¼������N\n",student_array[studenti].name);
    {char ch;
        while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')fflag=1;break;}else printf("������Ч\n");}
    }
    if(!fflag)break;
}
if(!pp)continue;
printf("�Ƿ����¼������ͬѧ�ĳɼ�\n");
printf("Y ����¼��  N ����¼��\n");
{char ch;
        while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')fflag=1;break;}else printf("������Ч\n");}
   if(ch=='N'||ch=='n')break;
    }

}
return 0;
}

int searchstudentaccordingnuminkey()
{
    int i;char num[20];
    for(i=0;i<student_key_total;i++)if(!strcmp(num,student_key_data[i].num))break;studenti=i;
    return 0;
}

int all_student_total_credit()
{system("CLS");
    for(int i=0;i<32;i++)printf(" ");
    printf("����ѧ������ѧ��\n");
    printf("    -------------------------------------------------------------------------\n\n\n");
    int i;
    printf("    ѧ����           ����       ����ѧ��\n");
    printf(" --------------------------------------\n");
    for(i=0;i<student_total;i++)
    {
    printf(" %12s%13s%12.2lf\n",student_array[i].num,student_array[i].name,student_array[i].total_credit);
    printf(" --------------------------------------\n");

    }
    return 0;
}
int unpass()
{
    system("CLS");
        for(int i=0;i<30;i++)printf(" ");printf("�鿴����Ŀ������ѧ��������\n");
    printf("   ----------------------------------------------------------------------\n\n\n");
    int idex,k;

    for(int i=0;i<course_total;i++)
    {
       if(ALL_course[i].unpass)
            {printf("�γ�����: ");
             printf("%s \n\n",ALL_course[i].name);
             printf("   ѧ��            ���          ����\n");
             printf(" --------------------------------------\n");
            for(int j=0;j<ALL_course[i].count;j++)
            {
                idex=ALL_course[i].Choose_student_idex[j];
                for(k=0;k<student_array[idex].cousetotal;k++)
                {if(!strcmp(ALL_course[i].num,student_array[idex].All_course[k].num))break;}
                    if(student_array[idex].All_course[k].final_score<60&&(student_array[idex].All_course[k].fnish))
                printf("%s\t%s\t%s\n",student_array[idex].num,student_array[idex].class_name,student_array[idex].name);
            }
            printf("\n");
            }
    }
    return 0;
}

int rightful_key(char *s)
{
    int flag=0;
    while(*s)
    {
        if(! isalnum(*s++)){flag=1;break;}
    }
    if(flag)return 0;
    return 1;
}
int R_L_K(char*s)
{
    if(strlen(s)>=6&&strlen(s)<=12)return 1;
    else return 0;
}

int scan_num(char *num)
{
    while(1){printf("         (֤���ų���Ϊ 12)\n");
             printf("               ���� * ����\n");
    char s[100];
    fflush(stdin);
    scanf("%s",s);
    //printf("s=%s\n",s);
    if(!strcmp(s,"*"))return 0;
    if(strlen(s)!=12){system("CLS");printf("����֤���ų��Ȳ��Ϸ�������������\n");continue;}
    strcpy(num,s);
    return 1;
    }
}
int scan_course_num(char *num)
{
    while(1){printf("         (ѡ�޿α�ų���Ϊ 6)\n");
             printf("               (���� *  ����)\n");
    char s[100];
    fflush(stdin);
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    if(strlen(s)!=6){system("CLS");printf("����ѡ�޿α�ų��Ȳ���ȷ������������\n");continue;}
    strcpy(num,s);
    return 1;
    }
}
int scan_phone(char *num)
{
   printf("�������ֻ�����\n");
    while(1){printf("         (�ֻ����볤��Ϊ 11��6)\n");
             printf("                (���� * ����)\n");
    char s[100];
    fflush(stdin);
    scanf("%s",s);
    if(!strcmp(s,"*")){system("CLS");return 0;}
    if(!(strlen(s)==11||strlen(s)==6)){system("CLS");printf("�����ֻ����볤�Ȳ���ȷ������������\n");continue;}
    strcpy(num,s);
    system("CLS");return 1;
    }
}

int right_course(char *s)
{
    for(int i=0;i<course_total;i++)
        if(!strcmp(s,ALL_course[i].num))return 0;
    return 1;
}

int repeat_course(char *s)
{
    for(int i=0;i<student_array[studenti].cousetotal;i++)
        if(!strcmp(s,student_array[studenti].All_course[i].num))return 0;
    return 1;
}
int encrypt(char *key)
{
    int y=strlen(key);
    for(int i=0;i<y;i++)
        key[i]=key[i]^15;
    return 0;
}
int decode(char *key)
{
   int y=strlen(key);
   for(int i=0;i<y;i++)
   key[i]=key[i]^15;
   return 0;

}
int scan_class(char *s)
{
    //system("CLS");
    while(1){printf("��������  (��:�������R2)  \n");
    printf("         (���� * ����)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;

    return 1;
    }
}
int scan_name(char *s)
{
    system("CLS");
    printf("����������\n");
    printf("         (���� * ����)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    return 1;
}
int scan_dor(char *s)
{
    system("CLS");
    while(1){
    printf("����������� (��ʽ�� 7-413 )\n");
    printf("         (���� * ����)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    return 1;}
}
int scan_age(char *s)
{
    int d;
    system("CLS");
   while(1){printf("����������\n");
    printf("         (���� * ����)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    sscanf(s,"%d",&d);
    if(d<0||d>=200){system("CLS");printf("�������䲻����,����������\n");continue;}
    return 1;}
}
int scan_sex(char *s)
{   char a[100];
    system("CLS");
    while(1)
    {printf("�������Ա�\n");
    printf("         (���� * ����)\n");
    printf(" 1:��  2:Ů\n");
    scanf("%s",a);
    if(!strcmp(s,"*"))return 0;
    if(!strcmp(a,"1")||!strcmp(a,"2"))break;
    system("CLS");printf("������Ч������������\n");
    }
    if(!strcmp(a,"1"))strcpy(s,"��");
    if(!strcmp(a,"2"))strcpy(s,"��");
    return 1;
}
int scan_score(double &s)
{
    while(1){printf("        (����Ϊ�ٷ���)\n");
    printf("              (����-1����)\n");
    scanf("%lf",&s);
    if(s==-1)return 0;
    if(s<0||s>100){system("CLS");printf("�����벻�Ϸ�,����������\n");continue;}
     system("CLS");
    return 1;
    }
}
int scan_credit(double &s)
{

    while(1){printf("        (ѧ�ֵ���Ч��ΧΪ0~4��)\n");
    printf("              (����-1����)\n");
    scanf("%lf",&s);
    if(s==-1)return 0;
    if(s<0||s>4){system("CLS");printf("�����벻�Ϸ�,����������\n");continue;}
    system("CLS");
    return 1;
    }
}
int sort_data()
{
   int i,j,flag;
   char temp[20];
    for(i=0;i<student_total;i++)
        {flag=0;
        for(j=0;j<student_total-i-1;j++)
        {
            if(strcmp(student_array[j].num,student_array[j+1].num)>0){
                    strcpy(temp,student_array[j+1].num);
            strcpy(student_array[j+1].num,student_array[j].num);
            strcpy(student_array[j].num,temp);flag=1;}
        }
        if(!flag)break;
        }
        return 0;
}
int sort_student_key()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<student_key_total;i++)
    {
        flag=0;
        for(j=0;j<student_key_total-i-1;j++)
        {
            if(strcmp(student_key_data[j].num,student_key_data[j+1].num)>0)
            {
                strcpy(temp,student_key_data[j+1].num);
                strcpy(student_key_data[j+1].num,student_key_data[j].num);
                strcpy(student_key_data[j].num,temp);
                flag=1;
            }
        }
        if(!flag)break;
    }
    return 0;
}

int sort_admin_key()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<admin_total;i++)
    {
        flag=0;
        for(j=0;j<admin_total-i-1;j++)
        {
            if(strcmp(admin_key_data[j].num,admin_key_data[j+1].num)>0)
            {
                strcpy(temp,admin_key_data[j+1].num);
                strcpy(admin_key_data[j+1].num,admin_key_data[j].num);
                strcpy(admin_key_data[j].num,temp);
                flag=1;
            }
        }
        if(!flag)break;
    }
    return 0;
}
int sort_student_course()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<student_array[studenti].cousetotal;i++)
    {
        flag=0;
        for(j=0;j<student_array[studenti].cousetotal-i-1;j++)
        {
            if(strcmp(student_array[studenti].All_course[j].num,student_array[studenti].All_course[j+1].num)>0)
            {
                strcpy(temp,student_array[studenti].All_course[j].num);
                strcpy(student_array[studenti].All_course[j].num,student_array[studenti].All_course[j+1].num);
                strcpy(student_array[studenti].All_course[j+1].num,temp);
                flag=1;
               // printf("%s\n",temp);
            }
        }
        if(!flag)break;
    }
    return 0;
}

int sort_course()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<course_total;i++)
    {
        flag=0;
        for(j=0;j<course_total-i-1;j++)
        {
            if(strcmp(ALL_course[j].num,ALL_course[j+1].num)>0)
            {
                strcpy(temp,ALL_course[j+1].num);
                strcpy(ALL_course[j+1].num,ALL_course[j].num);
                strcpy(ALL_course[j].num,temp);
                flag=1;
            }
        }
        if(!flag)break;
    }
    return 0;
}

int I_LOVE_YOU()
{
    int m=1,n=9,i;char s[100]="Design by��Chen M  L";int y=strlen(s);

    for(i=0;i<17;i++){
    system("CLS");
    printf("\n\n\n\n");
    if(i%2==0)printf("\n");
    if(i%3==0)printf("\n\n");
    if(i%4==0)printf("\n\n\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("* * *  *     * * * * *       * * * * *  *    * * * * * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("  *    *     *     *  *     *  *         *  *  *     * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("  *    *     *     *   *   *   * * * *     *   *     * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("  *    *     *     *    * *    *           *   *     * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("* * *  * * * * * * *     *     * * * *     *   * * * * *  * *\n");
    for(int k=0;k<201314000;k++);
    }
     printf("\n\n\n\n\n\n\n\n");
    printf("                                                        ");
    for(int n=0;n<y;n++)
    {
        for(int j=0;j<100000000;j++);
        printf("%c",s[n]);
    }
    printf("\n\n");
   system("pause");
    system("CLS");
    return 0;
}
int logging_grade_data_one_course()
{
    char num[20],s[20];int i;int flag=0;int fg=0;
    double e,u,cre;
    while(1){
            printf("���пγ̵ı�ź�����\n");
    for(i=0;i<course_total;i++)
    {
        printf("%s    %s",ALL_course[i].num,ALL_course[i].name);
        if(ALL_course[i].finish)printf("(��¼�����)\n");
        else printf("\n");
    }
            printf("������Ҫ¼��ɼ��Ŀγ̱��\n");
    if(!scan_course_num(num)){system("CLS");break;}

    for(i=0;i<course_total;i++)
        if(!strcmp(num,ALL_course[i].num)){coursei=i;break;}

    if(i>=course_total){
            printf("�Բ������޴˿γ̱��\n");
            printf("�˳�¼��: Y ��������: N\n");
    }
    else {//printf("count %d  \n",ALL_course[coursei].count);
            for(i=0;i<ALL_course[coursei].count;i++)
    {
        studenti=ALL_course[coursei].Choose_student_idex[i];
        if(!finish_logging_grade()){break;}
    }
    if(ALL_course[coursei].finish){printf("�ÿγ�����ɳɼ�����\n");continue;}
    if(!ALL_course[coursei].count){printf("��ѡ�޿�����ѧ��ѡ��\n");continue;}
    printf("�Ѽ�鵽�ÿγ��ϴ���¼�뵽    %s   %s  \n",student_array[studenti].num,student_array[studenti].name);
    printf("�Ӹô�����¼��:Y  ����¼��: N \n");
    char ch;int ppp;
    {
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("������Ч\n");}
    }
    if(ch=='N'||ch=='n'){i=0;printf("����ѡ����������ѡ�޿γɼ�\n");}
    while(i<ALL_course[coursei].count)
    {
        flag=0;studenti=ALL_course[coursei].Choose_student_idex[i];
        printf("��������Ϊ %s ͬѧ¼�� %s  ��Ŀ�ĳɼ�\n",student_array[ALL_course[coursei].Choose_student_idex[i]].name,ALL_course[coursei].name);
        fg=0;
        for(;!fg;)
      {
        printf("������ƽʱ�ɼ�\n");
        if(ppp=scan_score(u),!ppp)break;
        else for(;!fg;)
        {
            printf("��������ĩ�ɼ�\n");
            if(!scan_score(e))break;
            else for(;!fg;){
                printf("����������ѧ��\n");
                if(!scan_credit(cre))break;
                else fg=1;
            }
        }

    }
    if(!fg){system("CLS");break;}
        printf("�������Ƿ�����\n����Y  ������N\n");
     {char ch;
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')flag=1;break;}else printf("������Ч\n");}
    }
    if(flag)
    {
        fflush(stdin);
        printf("����������ѧ�ڣ���ʽ��2013~2014��\n");
        gets(s);
    }int sti;
    for(sti=0;sti<student_array[studenti].cousetotal;sti++)
        if(!strcmp(student_array[studenti].All_course[sti].num,ALL_course[coursei].num))break;
    printf("����Ϊ %s ͬѧ %s  ��Ŀ¼��������Ϣ\n",student_array[studenti].name,student_array[studenti].All_course[sti].name);
    printf("  ���  ����  ƽʱ�ɼ�  ��ĩ�ɼ�  ƽ���ɼ�  ѧ��   �Ƿ�����   ����ѧ��   ���޴���\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("%s%7s%8.1lf%10.1lf%10.1lf%8.1lf     ",ALL_course[coursei].num,student_array[studenti].All_course[sti].name,u,e,(e+u)/2,cre);
      if(flag)
    {
        printf("��     %s      %d\n",s,student_array[studenti].All_course[sti].Retake_count+1);}
        else printf("��         ��         ��\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("ȷ��������Y  ��������N\n");

char ch;
    {
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("������Ч\n");}
    if(ch=='N'||ch=='n')printf("�γ������Ϣδ¼��\n");
    if(ch=='Y'||ch=='y')
    {
        student_array[studenti].All_course[sti].usual_score=u;
        student_array[studenti].All_course[sti].exam_score=e;
        student_array[studenti].All_course[sti].final_score=(u+e)/2;
        student_array[studenti].All_course[sti].credit=cre;
        if((u+e)/2<60)ALL_course[coursei].unpass=1;
        student_array[studenti].All_course[sti].fnish=1;
        if(flag)
    {
        student_array[studenti].All_course[sti].IsRetake=1;
        student_array[studenti].All_course[sti].Retake_count++;
        strcpy(student_array[studenti].All_course[sti].Retake_semester,s);
    }
       printf("¼��ɼ��ɹ�\n");i++;
    }
    }
    }
    if(!ppp) continue;
    {ALL_course[coursei].finish=1;
    printf(" %s  %s  ¼��ɼ����\n",ALL_course[coursei].num,ALL_course[coursei].name);i=0;}
    }
     if(!fg){system("CLS");continue;}
    {char ch;
    printf("\n\n�Ƿ����¼�������γ�\n����: Y  ����: N \n");
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("������Ч\n");}
    if(ch=='N'||ch=='n')break;
    else i=0;
    }
    }
    system("CLS");
    return 0;
}
int finish_logging_grade()
{
    int i;
    for(i=0;i<student_array[studenti].cousetotal;i++)
        if(!strcmp(student_array[studenti].All_course[i].num,ALL_course[coursei].num))break;
    if(student_array[studenti].All_course[i].fnish){return 1;}
    return 0;
}
int input_grade()
{
    int y=35;
   while(1){
         system("CLS");
                  for(int i=0;i<32;i++)printf(" ");
                  printf("¼��γ̻�����Ϣ�Ϳ������\n");
                  printf("    ------------------------------------------------------------------------------\n\n\n\n");
    for(int i=0;i<y;i++)printf(" ");printf("-----------------------\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  ¼��ɼ���ʽ   ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  1:��ѧ��ѧ��   ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  2:��ѡ�޿ογ� ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  *:����         ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("-----------------------\n");
    char ch;
    {
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='1'||ch=='2'||ch=='*')break;
    else printf("������Ч\n");}
    switch(ch)
    {
        case '1':system("CLS");input_student_grade_imformation_of_course();system("CLS");break;
        case '2':system("CLS");logging_grade_data_one_course();system("CLS");break;
        case '*':system("CLS");return 0;
     }
    }
   }
}

int Total_Credit_Unpass()
{
    int y=35;

    while(1){ printf("                              ����ѧ����ѧ�ֺ͸���Ŀ����������\n");
              printf("   -----------------------------------------------------------------------------\n\n\n\n");
    for(int i=0;i<y;i++)printf(" "); printf("----------------------------\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  1:����ѧ������ѧ��  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  2:����Ŀ����������  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  *:����              ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("----------------------------\n\n\n\n");
    char ch;
    {
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='1'||ch=='2'||ch=='*')break;
    else printf("������Ч\n");}
    switch(ch)
    {
        case '1':all_student_total_credit();system("pause");system("CLS");break;
        case '2':unpass();system("pause");system("CLS");break;
        case '*':system("CLS");return 0;
     }
    }
   }
}
int Delete_course()
{   system("CLS");
    int i;char num[20],name[20];
    printf("                                  ɾ��ĳ��ѡ�޿���Ϣ\n");
    printf("   ------------------------------------------------------------------------------\n\n\n");
    if(!course_total){printf("�Բ���ϵͳ��ʱ��δ�пγ�\n");return 0;}
    while(1){printf("����Ҫɾ��ѡ�޿α��\n");
    if(!scan_course_num(num))break;
    for(i=0;i<course_total;i++)
            if(!strcmp(num,ALL_course[i].num))break;
    if(i>=course_total){printf("�Բ���ϵͳδ�и�ѡ�޿�\n");continue;}
    strcpy(name,ALL_course[i].name);
    printf("��Ҫɾ����ѡ�޿���Ϣ����\n");
    printf("ѡ�޿α��   %s\n",ALL_course[i].num);
    printf("ѡ�޿�����    %s\n",ALL_course[i].name);
    printf("������Ϣ   %s\n",ALL_course[i].imformation);
    printf("ȷ��ɾ�� Y  ����ɾ�� N\n");
       char ch;
        while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='n'||ch=='N')break;
        else printf("��������Ч\n");}
    if(ch=='Y'||ch=='y')
    {
        for(int j=i;j<course_total;j++)
        {
            strcpy(ALL_course[j].num,ALL_course[j+1].num);
             strcpy(ALL_course[j].name,ALL_course[j+1].name);
              strcpy(ALL_course[j].imformation,ALL_course[j+1].imformation);
        }
        course_total--;
        printf("ɾ�� %s �γ̳ɹ�\n",name);
    }
    else printf("%s  �γ�δɾ��\n",name);
    printf("�Ƿ����ɾ�������γ�\n");
    printf("Y ����   N ����\n");
    {  char ch;
        while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='n'||ch=='N')break;
        else printf("��������Ч\n");}
        if(ch=='N'||ch=='n')break;
    }
    }
    system("CLS");
    return 0;
}
int add_course()
{
    {system("CLS");
            char num[20],name[20],imfo[200];
            printf("                                ����ĳ��ѡ�޿�\n\n\n\n");
            printf("    -------------------------------------------------------------------------\n");
            while(1){printf("��������Ҫ����ѡ�޿εı��\n");
            fflush(stdin);if(!scan_course_num(num))break;
            if(!right_course(num)){printf("�Բ������и�ѡ�޿Σ��뻻��һ���\n");continue;}
            printf("�������ѡ�޿ε�����\n");
            scanf("%s",name);
            printf("������Ըÿγ̵Ĵ������(����40��)\n");
            fflush(stdin);scanf("%s",imfo);
            printf("ȷ���������ѡ�޿�\n");
            printf("��� %s  ����%s  \n������Ϣ\n%s\n",num,name,imfo);
            printf("ȷ�� Y  ���� N\n");
        {char ch;
        while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("������Ч\n");}
        if(ch=='Y'||ch=='y')
        {
            strcpy(ALL_course[course_total].num,num);
            strcpy(ALL_course[course_total].name,name);
            strcpy(ALL_course[course_total++].imformation,imfo);
            printf("��ӳɹ���\n");
        }
        }
        printf("�������ӿγ� Y  ����  N\n");
        {char ch;
        while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("������Ч\n");}
        if(ch=='N'||ch=='n')break;}
            }
    }
 system("CLS");
 return 0;
}
int add_delete_course()
{
    system("CLS");int y=35;
   while(1) {
        printf("                                    ��ӻ�ɾ���γ�\n");
        printf("   -------------------------------------------------------------------------------\n\n\n");
    for(int i=0;i<y;i++)printf(" "); printf("--------------------\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  1:��ӿγ�  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  2:ɾ���γ�  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  *:����      ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("--------------------\n\n\n\n");
    printf("��ѡ��\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);
    if((ch>='1'&&ch<='2')||ch=='*')break;
    else printf("������Ч\n");}
    switch(ch)
    {
        case '1':add_course();break;
        case '2':Delete_course();break;
        case '*':system("CLS");return 0;
    }
   }
}
int modification_admin_key()
{
    system("CLS");
    char new1[100],new2[100];int p,fl;
    printf("                                   �޸Ĺ���Ա����\n");
    printf("   -------------------------------------------------------------------------------\n\n\n\n");
    while(1){printf("������ԭ����\n");fl=0;
    p=Input_key(admin_key_data[admini].key);
    if(p==2){ system("CLS");break;}
    if(!p){system("CLS");printf("\n�������벻��ȷ������������\n");continue;}
    system("CLS");
    while(1){printf("������������\n");
    if(!scanf_key(new1))break;
    system("CLS");
    printf("���ٴ�����������\n");
    if(!scanf_key(new2)){continue;}
    system("CLS");
    if(!strcmp(new1,new2)){fl=1;strcpy(admin_key_data[admini].key,new1);printf("�޸�����ɹ�!\n����������Ϊ  %s  \n",new1);break;}
    printf("�����������벻һ��������������\n");
    }
    if(fl)break;
    }
return 0;
}
int Look_over_scores()
{
    system("CLS");
    int y=28;
    while(1){printf("                                        �鿴ѧ���ɼ�\n");
    printf("  --------------------------------------------------------------------------------------\n\n\n\n\n\n");
    for(int i=0;i<y;i++)printf(" "); printf("------------------------------------------\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  1:����ͳ��ѧ��ѡ����������Գɼ�  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  2:���γ�ͳ��ѧ�����������Գɼ�    ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  *:����                            ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("------------------------------------------\n\n\n\n");
    printf("��ѡ��\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);
    if((ch>='1'&&ch<='2')||ch=='*')break;
    else printf("������Ч\n");}
    switch(ch)
    {
        case '1':system("CLS");if(!student_total){printf("����ϵͳ��û��ѧ����Ϣ����ȥע��ɣ�\n");break;}
          for(int i=0;i<28;i++)printf(" "); printf("���༶ͳ��ѧ��ѡ�޿μ��������\n");
          printf("    -------------------------------------------------------------------------\n");
                 while(1){for(int j=0;j<classnum;j++)printf(" %s \n",ALLCLASS[j].class_name);
                printf("��������Ҫ�鿴�༶������\n");char s[20];
                    fflush(stdin);if(!scan_class(s))break;int i;
        for(i=0;i<classnum;i++)
        if(!strcmp(ALLCLASS[i].class_name,s))break;
        if(!strcmp(ALLCLASS[i].class_name,s)){
        printf("                            %s\n",ALLCLASS[i].class_name);
        for(int j=0;j<ALLCLASS[i].count;j++)
        {
        int studenti=ALLCLASS[i].student_num[j];printf("ѧ��ѧ��%s\n",student_array[studenti].num);
        printf("    ���   ����   ƽʱ�ɼ�  ��ĩ�ɼ�  ƽ���ɼ�  ѧ�� \n");
        printf("--------------------------------------------------------------\n");
        for(int j=0;j<student_array[studenti].cousetotal;j++){
    if(student_array[studenti].All_course[j].fnish)
    printf("  %5s%8s%9.1lf%10.1lf%10.1lf%8.1lf     \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);
    else printf("  %5s%8s     ��         ��       ��      �� \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name);
        }
         printf("--------------------------------------------------------------\n");

        }
    printf("\n\n\n");system("pause");system("CLS");
}
else printf("�Ҳ����ð༶\n");
printf("�Ƿ������ѯ�����༶\n");
printf("������ѯ Y  ������ѯ N\n");
 char ch;
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
        else printf("��������Ч\n");}
        if(ch=='N'||ch=='n')break;
}system("CLS");
break;
        case '2':system("CLS");
                    if(!student_total){printf("����ϵͳ��û��ѧ����Ϣ����ȥע��ɣ�\n");break;}
                    if(!course_total){printf("�Բ���ϵͳ��û�����ѡ�޿γ̣���ȥ¼��ѡ�޿γ̰ɣ�\n");break;}
                    while(1){for(int i=0;i<28;i++)printf(" ");
                            printf("���γ�ͳ��ѧ�����������Գɼ�\n");
                     printf("    -------------------------------------------------------------------------\n");
                    for(int i=0;i<course_total;i++)
                    {printf("%s    %s",ALL_course[i].num,ALL_course[i].name);
                   if(!ALL_course[i].finish)printf("(δ��ȫ¼��)\n");
                    else printf("(��¼��)\n");
                    }
                  printf("��������Ҫ���ʵĿγ̱��\n");
                  char num[20];fflush(stdin);if(!scan_course_num(num))break;
                  system("CLS");int i;
                  for(i=0;i<course_total;i++)
                    if(!strcmp(num,ALL_course[i].num))break;
            if(!strcmp(num,ALL_course[i].num)){printf("��Ŀ: %s\n",ALL_course[i].name);
            printf("     ѧ��            �༶      ����    ƽʱ�ɼ�  ��ĩ�ɼ�   ƽ���ɼ�  ѧ�� \n");
            for(int j=0;j<ALL_course[i].count;j++)
            {
                int k,idex=ALL_course[i].Choose_student_idex[j];
                for(k=0;k<student_array[idex].cousetotal;k++)if(!strcmp(student_array[idex].All_course[k].name,ALL_course[i].name))break;
                printf(" %8s%14s%10s%8.1lf%10.1lf%10.1lf%8.1lf\n",student_array[idex].num,student_array[idex].class_name,student_array[idex].name,student_array[idex].All_course[k].usual_score,student_array[idex].All_course[k].exam_score,student_array[idex].All_course[k].final_score,student_array[idex].All_course[k].credit);
                }
        }
        else printf("���޴���ѡ�޿�\n");
    printf("������ѯ Y  ������ѯ N\n");
    char ch;
    while(1){printf("����������ѡ��\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n'){system("CLS");break;}
        else printf("��������Ч\n");}
        if(ch=='N'||ch=='n')break;
        }system("CLS");break;
        case '*':system("CLS");return 0;
    }
    }
}

int SORT_ALL()
{
     sort_data();
     sort_student_key();
     sort_admin_key();
     sort_course();
     return 0;
}

int END()
{
    system("CLS");
    printf("\n\n\n\n\n\n\n");
    printf("                          ********************************************\n");
    printf("                          ***���ڽ��й���Ϣд���ļ�������رճ���***\n");
    printf("                          ********************************************\n\n");
    printf("д�����\n\n");
    for(int i=0;i<89;i++)
    {for(int j=0;j<10000000;j++);printf(">");}
    if(Write_ALL()){printf(">\n\n\n");
    printf("                             ***********************************\n");
    printf("                             ***��Ϣд��ɹ�,����ת���뿪����***\n");
    printf("                             ***********************************\n");
    }
    for(int i=0;i<201314000;i++);
    for(int i=0;i<201314000;i++);
    for(int i=0;i<201314000;i++);
    return 0;
}



