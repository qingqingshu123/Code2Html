#include <conio.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#define	MIN_INPUT 0x20
#define	MAX_INPUT 0x7e
#include <ctype.h>

/*
* ���й����д˺���ʵ�֣�
* pszPw �� ��������Ļ���
* iMaxSize ���������볤�ȣ��ó��ȱ���С�ڻ�������С��
* ����ֵΪTRUEΪ�ɹ���ȡ���롣���Ƿ���TRUE

*/
int R_L_K(char*s)
{
    if(strlen(s)>=6&&strlen(s)<=12)return 1;
    else return 0;
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
/*int scanf_key(char *key)
{
  char input[100];
  char ch;
  int i;

      while(1)
  {
      printf("      (������6~12�����ֻ���ĸ����)\n");
      printf("              (������һ���� * )\n");
  memset(input,0,10);
  i = 0;
  while((ch = getch()) != '\r')
   {
   if( ch == '\b')
    {
    putchar('\b');
    putchar(0);
    putchar('\b');
    i--;
    }
   else{
    input[i++] = ch;
    putchar('*');
     }
   }
   if(!strcmp(input,"*")){system("CLS");return 0;}
   if(!R_L_K(input)){printf("\n���볤�Ȳ���ȷ����������\n");continue;}
   if(!rightful_key(input)){printf("\n���뺬�в��Ϸ��ַ���������������\n");continue;}
   strcpy(key,input);
 system("CLS");return 1;
  }

}*/
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
  if(!#strcmp(ps,"*"))return 2;
  if(strcmp(key,ps)==0)return 1;
  return 0;
  printf("\n");
  }
}

int main()
{
    char key[20];
    while(1){
    printf("\n%d\n",Input_key("123456"));
    }
}


