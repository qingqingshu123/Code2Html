#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define	MIN_INPUT 0x20
#define	MAX_INPUT 0x7e
int pppp=0;
typedef struct userdata
{
    char name[20];
    char phonenumber[20];
    char qq[20];
    char address[20];
    char relation[20];
    int no;
    struct userdata *next;
    struct userdata *nextnext;
} userdata;
userdata *tttt=NULL;
int  denglujiemiancaidan();
int zhuce();
int shouxinxi(char name[]);
int faxinxi(char *name);
void chakan(char name[]);
int tianjia(char name[]);
userdata * shanchu(char name[]);
userdata * genggai(char name[]);
int fenxiang(char name[]);
void chakan(char name[]);
int tianjia(char name[]);
userdata * shanchu(char name[]);
userdata * genggai(char name[]);
int fenxiang(char name[]);
userdata *chazhao(char name[]);
int gaimima();
int dadianhua();
int dianhuajiemian(char a);
int check_password(char password[]);
int check_name(char name[]);
int panduan(char *a,char *name);
int getdata( char* ps);
int GetPassword(char * ps);
char * jiemi(char mima[]);
char * jiami(char mima[]);
char * jiami(char mima[])
{
    int n,i;
    n=strlen(mima);
    for(i=0; i<=n-1; i++)
        mima[i]=mima[i]+i;
    return mima;
}
char * jiemi(char mima[])
{
    int n;
    n=strlen(mima);
    for(n=n-1; n>=0; n--)
        mima[n]=mima[n]-n;
    return mima;
}
int GetPassword(char * ps)
{
    int MaxSize=80;
    unsigned char ch;
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
    printf("\n");
    return TRUE;
}
int getdata(char* ps)
{
    int MaxSize=80;
    signed char ch;
    int i=0;
    int bIsEcho=TRUE;
    while( ( ch = (signed char)getch() ) && i < MaxSize )
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
        else if(ch<0)
        {
            putchar(ch);
            ps[i++]=ch;
            ch=getch();
            ps[i++]=ch;
        }
        else if ( ch == 8 && i> 0 )	/*�˸��*/
        {
            if(ps[i-1]<0)
            {
                ps[i--] = 0;
                ps[i--] = 0;
                bIsEcho = FALSE;
                putchar( ch );
                putchar( ch );
                putchar( ' ' );
                putchar( ch );
                goto Z;
            }
            ps[i--] = 0;
            bIsEcho = FALSE;
            putchar( ch );
            putchar( ' ' );
            putchar( ch );
        }
        else if(ch==8&&i==0)return 0;
        else
            bIsEcho = FALSE;
Z:
        if(bIsEcho)
            putchar(ch);
    }
    ps[i]=0;
    i=0;
    while(ps[i]!=0)
    {
        if(ps[i]==' ') return 2;
        i++;
    }//���ڿո������£�����2
    printf("\n");
    return 1;
}
int panduan(char *a,char *name)
{
    int i,j,l,m,k,t=0;
    i=strlen(a);
    j=strlen(name);
    for(l=0; l<i; l++)
        for(m=0; m<j; m++)
        {
            for(k=0; k<l; k++)if(a[l]==a[k])
                {
                    l++;
                    break;
                }
            if(l>=i) break;
            if(a[l]==name[m]) t++;
        }
    if(t>=i) return 1;
    else return 0;
}
int check_name(char name[])//�ж��û������ȣ�������12���ַ��������ֻ�������֣���ĸ�����
{
    int n;
    n=strlen(name);
    if(n<3||n>12) return 0;
    while(n)
    {
        if(!isalnum(name[n-1])) break;
        n--;
    }
    if(!n) return 1;
    else return 0;
}
int check_password(char password[])//�ж�����Ϸ��ԣ����Ȳ�����15���ַ���������6���ַ���ֻ�������֣���ĸ�����ϵ����
{
    int n;
    n=strlen(password);
    if(n>15||n<6) return 0;
    while(n)
    {
        if(!(isalnum(password[n-1])||ispunct(password[n-1]))) break;
        n--;
    }
    if(!n) return 1;
    else return 0;
}
int dianhuajiemian(char a)
{
    if(a=='1')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|               |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='2')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |                 |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='3')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='4')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|               |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");

    }
    if(a=='5')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |                 |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='6')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='7')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|               |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='8')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |                 |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='9')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='*')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|               |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='0')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |                 |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='#')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    return 0;
}
int dadianhua()
{
    char a,dianhua[100];
    int i=0,j=1;
    system("CLS");
    printf(" _____________________________________________________\n");
    printf("|               |                 |                   |\n");
    printf("|       1       |        2        |          3        |\n");
    printf("|_______________|_________________|___________________|\n");
    printf("|               |                 |                   |\n");
    printf("|       4       |        5        |          6        |\n");
    printf("|_______________|_________________|___________________|\n");
    printf("|               |                 |                   |\n");
    printf("|       7       |        8        |          9        |\n");
    printf("|_______________|_________________|___________________|\n");
    printf("|               |                 |                   |\n");
    printf("|       *       |        0        |          #        |\n");
    printf("|_______________|_________________|___________________|\n");
    while(a!=13)
    {
        a=getch();
        fflush(stdin);
        // if(a==8) {dianhua[i++]=0;putchar(a);putchar(' ');putchar(a);goto i;}
        dianhua[i++]=a;
        dianhua[i]=0;

        if(a=='1')
        {
            Beep(1209,80);
            dianhuajiemian('1');
            printf("%s",dianhua);
        }
        if(a=='2')
        {
            Beep(1336,80);
            dianhuajiemian('2');
            printf("%s",dianhua);
        }
        if(a=='3')
        {
            Beep(1477,80);
            dianhuajiemian('3');
            printf("%s",dianhua);
        }
        if(a=='4')
        {
            Beep(1290,80);
            dianhuajiemian('4');
            printf("%s",dianhua);
        }
        if(a=='5')
        {
            Beep(1336,80);
            dianhuajiemian('5');
            printf("%s",dianhua);
        }
        if(a=='6')
        {
            Beep(1477,80);
            dianhuajiemian('6');
            printf("%s",dianhua);
        }
        if(a=='7')
        {
            Beep(1209,80);
            dianhuajiemian('7');
            printf("%s",dianhua);
        }
        if(a=='8')
        {
            Beep(1336,80);
            dianhuajiemian('8');
            printf("%s",dianhua);
        }
        if(a=='9')
        {
            Beep(1477,80);
            dianhuajiemian('9');
            printf("%s",dianhua);
        }
        if(a=='*')
        {
            Beep(1209,80);
            dianhuajiemian('*');
            printf("%s",dianhua);
        }
        if(a=='0')
        {
            Beep(1336,80);
            dianhuajiemian('0');
            printf("%s",dianhua);
        }
        if(a=='#')
        {
            Beep(1477,80);
            dianhuajiemian('#');
            printf("%s",dianhua);
        }
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                        ���ڲ���");
    while(j!=5)
    {
        j++;
        Beep(500,1200);
        printf(".");
        Sleep(800);
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                        ��������û���æ�����Ժ��ٲ�");
    printf("\n�����������...");
    a=getch();
    return 0;
}
int gaimima()
{
    fflush(stdin);
    char name1[20],name2[20],password1[20],password2[20],password3[20];
    char data[500][20],choicee[100];
    int i=0,j;
    FILE *fp;
AAA:
    system("CLS");
    printf("                                          MaxͨѶ¼\n\n");
    printf("  ��������\n");
    printf("    �û���:");
    gets(name1);
    strcat(name1,".txt");
    fp=fopen(name1,"r");
    if(fp==NULL)
    {
        printf("�޴��û�\a��1.�����޸� 2.�������룺");
        fclose(fp);
DDD:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"1")==0) return 1;
        else if(strcmp(choicee,"2")==0) goto AAA;
        else
        {
            printf("�����������������:\a");
            goto DDD;
        }
    }
    printf("  �ɵ�����:");
BBB:
    GetPassword(password1);
    if(strlen(password1)>20)
    {
        printf("�����������������:\a");
        goto BBB;
    }
    fp=fopen(name1,"r");
    fscanf(fp,"%s%s",name2,password2);
    fclose(fp);
    if(strcmp(password1,jiemi(password2)))
    {
        printf("�������\a1.�����޸� 2.��������:");
CCC:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"1")==0) return 9;
        else if(strcmp(choicee,"2")==0)
        {
            system("CLS");
            printf("                                          MaxͨѶ¼\n\n");
            printf("  ��������\n");
            printf("    �û���:");
            printf("%s\n",name2);
            printf("  �ɵ�����:");
            goto BBB;
        }

        else
        {
            printf("�����������������:\a");
            goto CCC;
        }
    }
    if(!strcmp(name2,"001"))
    {
        printf("���û�Ϊ����ͨѶ¼�û�����Ҫ�����������������������:\a");
        GetPassword(password3);
        if(strcmp(password3,"8868431"))
        {
            printf("������󣬽��������˵�\a");
            Sleep(1500);
            return 2;
        }
        else printf("��֤�ɹ�\n");
    }
    printf("(���벻�ܶ���15���ַ�������6 ���ַ�����ֻ�������֣���ĸ�ͷ������)\n");
    printf("  �µ�����:");
C:
    GetPassword(password1);
    if(!check_password(password1))
    {
        printf("�����벻�Ϸ�,����������:\a");
        goto C;
    }
    strcat(name2,".txt");
    fp=fopen(name2,"r");
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    i--;
    strcpy(data[1],jiami(password1));
    fp=fopen(name2,"w");
    fprintf(fp,"%s %s\n",data[0],data[1]);
    for(j=2; j<=i; j=j+5)
        fprintf(fp,"%s %s %s %s %s\n",data[j],data[j+1],data[j+2],data[j+3],data[j+4]);
    fclose(fp);
    printf("���ĳɹ�...");
    Sleep(1000);
    return 0;
}
userdata *chazhao(char name[])
{
    system("CLS");
    printf("                                          MaxͨѶ¼\n\n");
    FILE *fp;
    char data[7][20],a[80],abc[9][30],choicee[100];
    int i=0,j=0,k,l=0,m,t,n=1,z=0,w=0,dd;
    strcat(name,".txt");
    userdata *head,*headhead,*p,*q,*r;
    fp=fopen(name,"r");
    while(fscanf(fp,"%s",abc[z++])!=EOF)if(z>=10)break;
    fclose(fp);
    if(z==8)
    {
        printf("������ϵ��");
        return 0;//����ϵ��
    }
    fp=fopen(name,"r");
    while(i!=7) fscanf(fp,"%s",data[i++]);
    head=( userdata*)malloc(sizeof( userdata));
    p=( userdata*)malloc(sizeof( userdata));
    head->next=p;
    p->next=NULL;
    p->nextnext=NULL;
    while(fscanf(fp,"%s%s%s%s%s",p->name,p->phonenumber,p->qq,p->address,p->relation)!=EOF)
    {
        q=p;
        p=(userdata*)malloc(sizeof( userdata));
        p->next=NULL;
        p->nextnext=NULL;
        q->next=p;
    }
    fclose(fp);
    q->next=NULL;
    q->nextnext=NULL;
    free(p);
    printf("��ͨ����Щ�������ң�1.���� 2.�ֻ�/�̺� 3.QQ 4.סַ 5.Ⱥ�� 6.������һ��\n");
m:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"2")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"3")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"4")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"5")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"6")==0)
    {
        pppp=1;
        return (userdata *)6;//����
    }
    else
    {
        printf("�����������������:\a");
        goto m;
    }
    if(i==5) goto A;
    printf("������ؼ���,ע�ⲻ����20���ַ�(ֱ�Ӱ��س��ɲ��ҵ�ȫ��):");
    fflush(stdin);
    gets(a);
    j=strlen(a);
    while(j>20)
    {
        fflush(stdin);
        printf("�����������������:\a");
        gets(a);
        j=strlen(a);
    }
    p=head->next;
    printf("        %10s%17s%14s%15s%10s\n","����","�ֻ�/�̺�","QQ","סַ","Ⱥ��");
    if(i==1)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->name);
                if(j>t) break;
                for(m=0; m<t; m++)
                    if(p->name[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->name))
            {
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else  if(i==2)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->phonenumber);
                if(j>t) break;

                for(m=0; m<t; m++)
                    if(p->phonenumber[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->phonenumber))
            {
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else  if(i==3)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->qq);
                if(j>t) break;
                for(m=0; m<t; m++)
                    if(p->qq[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->qq))
            {
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else if(i==4)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->address);
                if(j>t) break;
                for(m=0; m<t; m++)
                    if(p->address[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->address))
            {
                //p->no=n++;
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else if(i==5)
    {
A:
        p=head->next;
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        printf("����ͨ����ЩȺ�����:1.��ͥ 2.���� 3.ͬѧ 4.ͬ�� 5.����\n");
        printf("����������ѡ��:");
C:
        scanf("%s",a);
        fflush(stdin);
        if(strcmp(a,"1")==0) strcpy(a,"��ͥ");
        else if(strcmp(a,"2")==0) strcpy(a,"����");
        else if(strcmp(a,"3")==0) strcpy(a,"ͬѧ");
        else if(strcmp(a,"4")==0) strcpy(a,"ͬ��");
        else if(strcmp(a,"5")==0) strcpy(a,"����");
        else
        {
            printf("\n");
            printf("�����������������:\a");
            goto C;
        }
        dd=5;
        while (p)
        {
            if(strcmp(p->relation,a)==0)
            {
                r->nextnext=p;
                r=p;
            }
            p=p->next;
        }
    }
    n=1;
    if(dd==5)
    {
        w=0;
        r=headhead->nextnext;
        printf("��ͥ��");
        while(r)
        {
            w++;
            r->no=n++;
            if(w!=1)printf("      ");
            printf("%2d:%10s%17s %14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
            r=r->nextnext;
        }
        dd=0;
    }
    else
        for(i=1; i<=5; i++)
        {
            w=0;
            r=headhead->nextnext;
            if(i==1)printf("��ͥ��");
            if(i==2)printf("���ѣ�");
            if(i==3)printf("ͬѧ��");
            if(i==4)printf("ͬ�£�");
            if(i==5)printf("������");
            while(r)
            {
                if(i==1)
                {
                    if(strcmp(r->relation,"��ͥ")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==2)
                {
                    if(strcmp(r->relation,"����")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==3)
                {
                    if(strcmp(r->relation,"ͬѧ")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==4)
                {
                    if(strcmp(r->relation,"ͬ��")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==5)
                {
                    if(strcmp(r->relation,"����")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                r=r->nextnext;
            }
            if(w==0) printf("����\n");
        }
    tttt=headhead;
    return head;
}
int fenxiang(char name[])
{
    FILE *fp;
    char name2[30],a,data[100][20],choicee[100];
    userdata *headhead,*head,*q;
    int choice,i=0,j=0,t;
    system("CLS");
    printf("                                          MaxͨѶ¼\n\n");
    printf("������ͨ���˹��ܣ��������û�����������ϵ����Ϣ�������Ȳ�����Ҫ�������ϵ��\n\n�����������...");
    a=getch();
    printf("%c",a);
    strcpy(name2,name);
    head=chazhao(name2);
    headhead=tttt;
    if(head==( userdata *)0)
    {
        Sleep(1500);
        return 2;
    }
    if(head==( userdata *)6) return 6;
    if(!headhead->nextnext)
    {
        printf("��Ǹ��û���ҵ�\n");
        Sleep(1000);
        return 2;
    }
    q=headhead->nextnext;
    i=1;
    while(q)
    {
        i++;
        q=q->nextnext;
    }
    i=i-1;
    printf("��������Ҫ������ǵڼ�λ��ϵ��:");
A:
    scanf("%d",&choice);
    fflush(stdin);
    if(choice<=0||choice>i)
    {
        printf("�����������������:");
        goto A;
    }
    q=headhead->nextnext;
    while(q)
    {
        if(choice==q->no) break;
        q=q->nextnext;
    }
    fp=fopen("datadatadata.txt","r");
    i=0;
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    system("CLS");
    printf("�����Խ����ղ�ѡ�����ϵ�˷���������û���\n");
    j=0;
    i=i-1;
    while(j<=i-1)
    {
        printf("%2d:%s\n",j+1,data[j]);
        j++;
    }
    t=i;//iΪ�û�����
    printf("��Ҫ����λ�û�������ϵ��:");
    if(i>=10&&i<=99)
    {
p:
        scanf("%s",choicee);
        fflush(stdin);
        if(strlen(choicee)==1)
        {
            choicee[1]='0';
            choicee[2]=0;
        }
        i=choicee[0]-'0'+(choicee[1]-'0')*10-1;
        if(strlen(choicee)<=0||strlen(choicee)>2||i<=0||i>t)
        {
            printf("�����������������:\a");
            goto p;
        }
    }
    else if(i<=9&&i>=0)
    {
q:
        scanf("%s",choicee);
        fflush(stdin);
        i=choicee[0]-'0';
        if(strlen(choicee)!=1||i<=0||i>t)
        {
            printf("�����������������:\a");
            goto q;
        }
    }
    strcat(data[i-1],"share.txt");
    fp=fopen(data[i-1],"a");
    fprintf(fp,"%s %s %s %s %s\n",q->name,q->phonenumber,q->qq,q->address,q->relation);
    fclose(fp);
    printf("����ɹ�");
    Sleep(1500);
    return 2;
}
userdata * genggai(char name[])
{
    char data[10][22],name2[80],name3[80],choicee[100],dd[100];
    strcpy(name2,name);
    strcpy(name3,name);
    userdata *headhead,*head,*q;
    FILE *fp;
    int i=1,n,j;
    int choice;
    char aa[80];
CC:
    strcpy(name,name3);
    strcpy(name2,name3);
    printf("�����������Ҫ���ĵ���Ŀ");
    Sleep(1500);
    system("CLS");
    head=chazhao(name);
    if(head==(userdata *)0)
    {
        Sleep(1500);
        return (userdata *)2;
    }
    if(head==(userdata *)6) return (userdata *)6;
    headhead=tttt;
    if(!headhead->nextnext)
    {
        printf("��Ǹ��û���ҵ�\n");
        Sleep(1000);
        return (userdata *)2;
    }
    q=headhead->nextnext;
    i=1;
    while(q)
    {
        i++;
        q=q->nextnext;
    }
    i=i-1;//iΪ�������ĸ���
    if(i==1)
    {
        q=headhead->nextnext;
        goto BB;
    }
    printf("��Ҫ���ĵ�������ڼ�λ��ϵ��:");
AA:
    fflush(stdin);
    choice=0;
    scanf("%d",&choice);
    if(!choice||choice<1||choice>i)
    {
        printf("�����������������:\a");
        goto AA;
    }
    fflush(stdin);
    i=1;
    q=headhead->nextnext;
    while(q)
    {
        if(choice==q->no) break;
        q=q->nextnext;
    }

BB:
    printf("�ɸ�����Ŀ��1.���� 2.�ֻ�/�̺� 3.QQ 4.סַ 5.Ⱥ�� 6.��������\n��������Ҫ���ĵ���Ŀ:");
j:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) printf("(������10���ַ������ɺ��ո�)������:");
    else if(strcmp(choicee,"2")==0) printf("(������17���ַ������ɺ��ո�ͺ���)���ֻ�/�̺�:");
    else if(strcmp(choicee,"3")==0) printf("(������14���ַ������ɺ��ո�ͺ���)��QQ:");
    else if(strcmp(choicee,"4")==0) printf("(������15���ַ������ɺ��ո�)��סַ:");
    else if(strcmp(choicee,"5")==0)
    {
        printf("�ɸ���Ϊ��Ⱥ��: 1.��ͥ 2.���� 3.ͬѧ 4.ͬ�� 5. ����\n");
        printf("����������ѡ��:");
cc:
        scanf("%s",dd);
        fflush(stdin);
        if(strcmp(dd,"1")==0) strcpy(aa,"��ͥ");
        else if(strcmp(dd,"2")==0) strcpy(aa,"����");
        else if(strcmp(dd,"3")==0) strcpy(aa,"ͬѧ");
        else if(strcmp(dd,"4")==0) strcpy(aa,"ͬ��");
        else if(strcmp(dd,"5")==0) strcpy(aa,"����");
        else
        {
            printf("�����������������:");
            goto cc;
        }
        strcpy(q->relation,aa);
        goto ff;

    }
    else if(strcmp(choicee,"6")==0) return (userdata *)6;
    else
    {
        printf("�����������������:\a");
        goto j;
    }
    choice=choicee[0]-'0';
d:
    gets(aa);
    fflush(stdin);
    n=strlen(aa);
    for(j=0; j<=n-1; j++)if(aa[j]==' ') break;
    if(j<=n-1)
    {
        printf("�����������������:\a");
        goto d;
    }
    while(n>20)
    {
        printf("�����������������:\a");
        gets(aa);
        fflush(stdin);
    }
    if(choice==2||choice==3)
    {
        for(j=0; j<=n-1; j++)if(aa[j]<0) break;
        if(j<=n-1)
        {
            printf("�����������������:\a");
            goto d;
        }
    }
    if(choice==1) strcpy(q->name,aa);
    else if(choice==2) strcpy(q->phonenumber,aa);
    else if(choice==3) strcpy(q->qq,aa);
    else if(choice==4) strcpy(q->address,aa);
    else if(choice==5) strcpy(q->relation,aa);
ff:
    strcat(name2,".txt");
    fp=fopen(name2,"r");
    i=0;
    while(i!=7) fscanf(fp,"%s",data[i++]);
    fclose(fp);
    fp=fopen(name2,"w");
    for(i=0; i<=6; i++) fprintf(fp,"%s ",data[i]);
    fprintf(fp,"\n");
    q=head->next;
    while(q)
    {
        fprintf(fp,"%s %s %s %s %s\n",q->name,q->phonenumber,q->qq,q->address,q->relation);
        q=q->next;
    }
    printf("�����ѱ��棬1.�������� 2.������һ��\n");
II:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)
    {
        fclose(fp);
        system("CLS");
        goto CC;
    }
    else if(strcmp(choicee,"2")==0);
    else
    {
        printf("�����������������:\a");
        goto II;
    }
    fclose(fp);
    return head;
}
userdata * shanchu(char name[])
{
    char data[10][22],name2[80],name3[80],choicee[100];
    strcpy(name2,name);
    strcpy(name3,name);
    userdata *headhead,*head,*q,*r,*s;
    FILE *fp;
    int i=1;
    int choice;
C:
    strcpy(name,name3);
    strcpy(name2,name3);
    printf("���Ȳ�����Ҫɾ������ϵ��");
    Sleep(1500);
    head=chazhao(name);
    if(head==(userdata *)0)
    {
        Sleep(1500);
        return (userdata *)2;
    }
    if(head==(userdata *)6) return (userdata *)6;
    headhead=tttt;
    if(!headhead->nextnext)
    {
        printf("��Ǹ��û���ҵ�\n");
        Sleep(1000);
        return (userdata *)2;
    }
    q=headhead->nextnext;
    while(q->nextnext)
    {
        q=q->nextnext;
        i++;
    }//iΪ�������ĸ���
    printf("��Ҫɾ����������ڼ�λ��ϵ��:");
A:
    scanf("%d",&choice);
    fflush(stdin);
    if(!choice||choice<1||choice>i)
    {
        printf("�����������������:\a");
        goto A;
    }


    printf("ȷ��ɾ����1.��2.��\n");
K:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) ;
    else if(strcmp(choicee,"2")==0)
    {
        printf("1.����ɾ�� 2.������һ��\n");
        goto I;
    }
    else
    {
        printf("����������������룺\a");
        goto K;
    }
    fflush(stdin);
    i=1;
    r=headhead;
    q=headhead->nextnext;
    while(q)
    {
        if(choice==q->no) break;
        r=q;
        q=q->nextnext;
    }
    r->nextnext=r->nextnext->nextnext;
    s=head;
    while(s->next!=q)s=s->next;
    s->next=s->next->next;
    free(q);
    strcat(name2,".txt");
    fp=fopen(name2,"r");
    i=0;
    while(i!=7) fscanf(fp,"%s",data[i++]);
    fclose(fp);
    fp=fopen(name2,"w");
    fprintf(fp,"%s %s\n",data[0],data[1]);
    for(i=2; i<=6; i++) fprintf(fp,"%s ",data[i]);
    fprintf(fp,"\n");
    q=head->next;
    while(q)
    {
        fprintf(fp,"%s %s %s %s %s\n",q->name,q->phonenumber,q->qq,q->address,q->relation);
        q=q->next;
    }
    printf("ɾ���ɹ���1.����ɾ�� 2.������һ��������2\n");
    fclose(fp);
I:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)
    {
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        goto C;
    }
    else if(strcmp(choicee,"2")==0) return head;
    else
    {
        printf("�����������������:\a");
        goto I;
    }
    return head;
}
int tianjia(char name[])
{
    system("CLS");
    fflush(stdin);
    FILE *fp;
    char data[500][30],choicee[100];
    int i=0,d,j;
A:
    printf("                                          MaxͨѶ¼\n\n");
    printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
    printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
    printf("     (������10���ַ��������ո�)��������ϵ��������");
    d=getdata(data[i]);
    fflush(stdin);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        goto A;
    }
    if(d==2)
    {
        printf("\n");
        goto Y;
    }
    if(strlen(data[i])>10)
    {
Y:
        printf("�����������������\a");
        Sleep(1000);
        system("CLS");
        goto A;
    }
B:
    printf("(������17���ַ��������ո�)��������ϵ���ֻ�/�̺ţ�");
    d=getdata(data[i+1]);
    fflush(stdin);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        goto A;
    }
    if(d==2)
    {
        printf("\n");
        goto X;
    }
    if(strlen(data[i+1])>17)
    {
X:
        printf("�����������������\a");
        Sleep(1000);
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        goto B;
    }
C:
    printf("       (������14���ַ��������ո�)��������ϵ��QQ��");
    d=getdata(data[i+2]);
    fflush(stdin);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        goto B;
    }
    if(d==2)
    {
        printf("\n");
        goto W;
    }
    if(strlen(data[i+2])>14)
    {
W:
        printf("�����������������\a");
        Sleep(1000);
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        printf("(������17���ַ��������ո�)��������ϵ���ֻ�/�̺ţ�%s\n",data[i+1]);
        goto C;
    }
D:
    printf("     (������15���ַ��������ո�)��������ϵ�˵�ַ��");
    d=getdata(data[i+3]);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        printf("(������17���ַ��������ո�)��������ϵ���ֻ�/�̺ţ�%s\n",data[i+1]);
        goto C;
    }
    if(d==2)
    {
        printf("\n");
        goto V;
    }
    if(strlen(data[i+3])>14)
    {
V:
        printf("�����������������\a");
        Sleep(1000);
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        printf("(������17���ַ��������ո�)��������ϵ���ֻ�/�̺ţ�%s\n",data[i+1]);
        printf("       (������14���ַ��������ո�)��������ϵ��QQ��%s\n",data[i+1]);
        goto D;
    }
E:
    printf("��ѡ����ϵ��Ⱥ�飺1.��ͥ 2.���� 3.ͬѧ 4.ͬ�� 5.����\n");
    printf("����������ѡ��:");
    d=getdata(data[i+4]);
    fflush(stdin);

    if(d==0)//����backspace��
    {
        printf("\n");
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        printf("(������17���ַ��������ո�)��������ϵ���ֻ�/�̺ţ�%s\n",data[i+1]);
        printf("       (������14���ַ��������ո�)��������ϵ��QQ��%s\n",data[i+2]);
        goto D;
    }
    if(strcmp(data[i+4],"1")==0) strcpy(data[i+4],"��ͥ");
    else if(strcmp(data[i+4],"2")==0) strcpy(data[i+4],"����");
    else if(strcmp(data[i+4],"3")==0) strcpy(data[i+4],"ͬѧ");
    else if(strcmp(data[i+4],"4")==0) strcpy(data[i+4],"ͬ��");
    else if(strcmp(data[i+4],"5")==0) strcpy(data[i+4],"����");
    else if(!strlen(data[i+4])) strcpy(data[i+4],"��");
    else
    {
        printf("\n");
        goto S;
    }
    if(strlen(data[i+4])>14)
    {
S:
        printf("�����������������\a");
        Sleep(1000);
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                  ����µ���ϵ�˵�ͨѶ¼\n");
        printf("�� Backspace ���ɷ����ϸ���Ϣ��Ŀ,������Ϣ���룬��ֱ�ӻس�������һ��\n");
        printf("     (������10���ַ��������ո�)��������ϵ��������%s\n",data[i]);
        printf("(������17���ַ��������ո�)��������ϵ���ֻ�/�̺ţ�%s\n",data[i+1]);
        printf("       (������14���ַ��������ո�)��������ϵ��QQ��%s\n",data[i+2]);
        printf("     (������15���ַ��������ո�)��������ϵ�˵�ַ��%s\n",data[i+3]);
        goto E;
    }
    if(!strlen(data[i])) strcpy(data[i],"��");
    if(!strlen(data[i+1])) strcpy(data[i+1],"��");
    if(!strlen(data[i+2])) strcpy(data[i+2],"��");
    if(!strlen(data[i+3])) strcpy(data[i+3],"��");
    if(!strlen(data[i+4])) strcpy(data[i+4],"��");
    printf("1.ȷ����� 2.�������\n");
a:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) ;
    else if(strcmp(choicee,"2")==0) return 2;
    else
    {
        printf("�����������������:\a");
        goto a;
    }
    printf("��ӳɹ�,1.������� 2.������һ��\n");
b:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)
    {
        i=i+5;
        system("CLS");
        goto A;
    }
    else if(strcmp(choicee,"2")==0)
    {
        j=i+5;
        strcat(name,".txt");
        fp=fopen(name,"a");
        i=0;
        while(i!=j)
        {
            fprintf(fp,"%s %s %s %s %s\n",data[i],data[i+1],data[i+2],data[i+3],data[i+4]);
            i=i+5;
        }
        fclose(fp);
        return 2 ;
    }
    else
    {
        printf("�����������������:\a");
        goto b;
    }
}
void chakan(char name[])
{
    system("CLS");
    printf("                                          MaxͨѶ¼\n\n");
    FILE *fp;
    char data[500][40];
    int i=0,j,t,w;
    strcat(name,".txt");
    fp=fopen(name,"r");
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    t=i-2;
    printf("           %10s%17s%14s%15s\n","����","�ֻ�/�̺�","QQ","��ַ");
    for(i=1; i<=5; i++)
    {
        w=0;
        if(i==1)printf("     ��ͥ��");
        if(i==2)printf("     ���ѣ�");
        if(i==3)printf("     ͬѧ��");
        if(i==4)printf("     ͬ�£�");
        if(i==5)printf("     ������");
        for(j=2; j<=t; j++)
        {
            if(i==1)
            {
                if(strcmp(data[j],"��ͥ")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==2)
            {
                if(strcmp(data[j],"����")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==3)
            {
                if(strcmp(data[j],"ͬѧ")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==4)
            {
                if(strcmp(data[j],"ͬ��")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==5)
            {
                if(strcmp(data[j],"����")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
        }
        if(w==0) printf("��\n");
    }

    if(t==8) printf("             ������ϵ��\n");
    system("pause");
    return;
}
int faxinxi(char *name)
{
    FILE *fp;
    char user[100][20],text[1000],a[30],data[10][1050],choicee[100];
    int i=0,j,n,k,t;
    system("CLS");
    printf("                                 ��Ϣ\n");
    printf("�������������û�������Ϣ��ʹ�ô�������û���\n");
    fp=fopen("datadatadata.txt","r");
    while(fscanf(fp,"%s",user[i++])!=EOF);
    i--;
    for(j=0; j<=i-1; j++)
    {
        printf("%d:%s\n",j+1,user[j]);
    }
    printf("��Ҫ��ڼ�λ�û�������Ϣ:");
    t=i;
    if(i>=10&&i<=99)
    {
p:
        scanf("%s",choicee);
        fflush(stdin);
        if(strlen(choicee)==1)
        {
            choicee[1]='0';
            choicee[2]=0;
        }
        i=choicee[0]-'0'+(choicee[1]-'0')*10-1;

        if(strlen(choicee)<=0||strlen(choicee)>2||i<=0||i>t)
        {
            printf("�����������������:\a");
            goto p;
        }
    }
    else if(i<=9&&i>=0)
    {
q:
        scanf("%s",choicee);
        fflush(stdin);
        i=choicee[0]-'0';
        if(strlen(choicee)!=1||i<=0||i>t)
        {
            printf("�����������������:\a");
            goto q;
        }
    }
    strcpy(a,user[i-1]);
    printf("��������༭��Ϣ���棬1.�����༭ 2.�����༭\n");
B:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) return 2;
    else if(strcmp(choicee,"2")==0) ;
    else
    {
        printf("�����������������:\a");
        goto B;
    }
    system("CLS");
    printf("��Ϣ:\n");
    printf("(��Ϣ�ڲ��ܰ����ո�����������1000�ַ�)\n    ");
C:
    fflush(stdin);
    gets(text);
    n=strlen(text);
    if(n>1000)
    {
        printf("��Ϣ����������������:\a\n");
        goto C;
    }
    for(j=0; j<=n-1; j++)
    {
        if(text[j]==' ') break;
    }
    if(j<=n-1)
    {
        printf("����Ϣ���Ƿ��ַ�������������:\a\n");
        goto C;
    }
    strcat(text,"���������û�");
    strcat(text,name);
    strcat(a,"message.txt");
    fp=fopen(a,"r");
    k=0;
    if(fp)
    {
        while(fscanf(fp,"%s",data[k++])!=EOF);
        fclose(fp);
    }
    if(data[0][0]=='0')
    {
        //fclose(fp);
        fp=fopen(a,"w");
        fprintf(fp,"1\n%s\n ",text);
        fclose(fp);
    }
    else
    {
        data[0][0]=data[0][0]+1;
        fclose(fp);
        fp=fopen(a,"w");
        for(j=0; j<=k-1; j++)
        {
            fprintf(fp,"%s\n",data[j]);
        }
        fprintf(fp,"%s\n",text);
        fclose(fp);
    }
    printf("���ͳɹ�");
    Sleep(1000);
    return 2;
}
int shouxinxi(char name[])
{
    system("CLS");
    FILE *fp;
    char name2[30],data[10][1080],a;
    int i=0,j=1;
    strcpy(name2,name);
    strcat(name2,"message.txt");
    fp=fopen(name2,"r");
    while(fscanf(fp,"%s",data[i++])!=EOF);
    i--;
    fclose(fp);
    if(data[0][0]=='0') printf("���յ���Ϣ");
    if(strcmp(data[1],"��ӭʹ��MaxͨѶ¼ϵͳ")==0)
    {
        printf("�յ�1����Ϣ:\n\n");
        printf("��ӭʹ��MaxͨѶ¼��--����Max\n\n");
        printf("�����������...");
        a=getch();
        printf("%c",a);
        goto g;
    }
    else
    {
        printf("�յ�%c����Ϣ��\n",data[0][0]);
        printf("\n");
        for(; j<=i-1; j++)
            printf("%s\n\n",data[j]);
    }
    printf("�����������...");
    a=getch();
g:
    fp=fopen(name2,"w");
    fprintf(fp,"0\n��\n");
    fclose(fp);
    return 2;
}
int zhuce()
{
    void signin();
    FILE *fp;
    char name1[80],name2[80],password1[80],password2[80],choicee[100];
    system("CLS");
    printf("(�û���ֻ����3��12���ַ���ɣ���ֻ�������ֺ���ĸ��ɳ�)\n");
    printf("(���벻�ܶ���15���ַ�������6 ���ַ�����ֻ�������֣���ĸ�ͷ������)\n");
    printf("          �û���:");
    scanf("%s",name1);
    fflush(stdin);
    strcpy(name2,name1);
    strcat(name1,".txt");
    fp=fopen(name1,"r");
    if(fp)
    {
        printf("���û����ѱ�ע��,������ע��\a");
        Sleep(1500);
        fclose(fp);
        zhuce();
        return 1;
    }
    if(!check_name(name2))
    {
        printf("�û������Ϸ�,������ע��\a");
        Sleep(1500);
        zhuce();
        return 1;
    }
    printf("\n            ����:");
    GetPassword(password1);
    if(!check_password(password1))
    {
        printf("���벻�Ϸ�,������ע��\a");
        Sleep(1500);
        zhuce();
        return 17;
    }
    printf("\n��������һ������:");
    GetPassword(password2);
    while(strcmp(password1,password2))
    {
        printf("���벻��ȷ��1.����ע�� 2.����ע��\n\a");
h:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"1")==0) return 2;
        else if(strcmp(choicee,"2")==0) ;
        else
        {
            printf("�����������������:");
            goto h;
        }
        printf("\n            ����:");
        GetPassword(password1);
        if(!check_password(password1))
        {
            printf("���벻�Ϸ�,������ע��\a");
            Sleep(1500);
            zhuce();
            return 17;
        }
        printf("\n��������һ������:");
        GetPassword(password2);
    }
    printf("ע��ɹ�,�����µ�½\n");
    Sleep(1500);
    fp=fopen(name1,"w");
    fprintf(fp,"%s %s\n",name2,jiami(password1));
    fprintf(fp,"���� �ֻ�/�̺� QQ סַ Ⱥ��");
    fclose(fp);
    fp=fopen("datadatadata.txt","a");
    fprintf(fp," %s",name2);
    fclose(fp);
    strcat(name2,"message.txt");
    fp=fopen(name2,"w");
    fprintf(fp,"1\n��ӭʹ��MaxͨѶ¼ϵͳ\n");
    fclose(fp);
    signin();
    return 0;
}
int  denglujiemiancaidan()//��½����˵�
{
    void signin();
A:
    printf("1.���µ�½ 2.ע�����û� 3.������һ��\n");
    char choicee[100];
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) signin();
    else if(strcmp(choicee,"2")==0) zhuce();
    else if(strcmp(choicee,"3")==0) return 3;
    else
    {
        printf("�����������������:\a\n");
        goto A;
    }
    return 1;
}
int yonghujiemian(char name[])//�û�����
{
    char name4[30],name5[30],a,choicee[100],share[500][20];
    FILE *fp;
    int y,j;
    strcpy(name4,name);
    strcpy(name5,name);
    strcat(name4,"message.txt");
    fp=fopen(name4,"r");
    //��Ϣ��Ϊ0
    a=fgetc(fp);
    if(a=='0')
    {
        fclose(fp);
        goto GG;
    }
    if(fp)
    {
        fclose(fp);
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("\n\n\n\n\n\n                           \a��������Ϣ���Ƿ�鿴: 1�� 2.��\n");
B:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"2")==0) goto GG;
        else if(strcmp(choicee,"1")==0) shouxinxi(name5);
        else
        {
            printf("�����������������:");
            goto B;
        }
    }
GG:
    strcpy(name4,name);
    strcat(name4,"share.txt");
    fp=fopen(name4,"r");
    if(fp!=NULL)
    {
        j=0;
        while(fscanf(fp,"%s",share[j++])!=EOF);
        fclose(fp);
        if(j<=3)
        {
            goto A;
        }
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("\n\n\n\n\n\n                           \a�����û�������������ϵ�ˣ��Ƿ�鿴: 1�� 2.���´β鿴\n");
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"2")==0)
        {
            goto A;
        }
        else if(strcmp(choicee,"1")==0)
        {
            system("CLS");
            printf("%10s%17s%14s%15s%10s","����","�ֻ�/�̺�","QQ","��ַ","Ⱥ��\n");
            y=0;
            while(y<=j-1)
            {
                printf("%10s%17s%14s%15s%10s\n",share[y],share[y+1],share[y+2],share[y+3],share[y+4]);
                y=y+5;
            }
            printf("�Ƿ������ϵ��: 1.�� 2.��:");
            scanf("%s",choicee);
            fflush(stdin);
            if(strcmp(choicee,"2")==0)
            {
                strcpy(name4,name);
                strcat(name4,"share.txt");
                fp=fopen(name4,"w");
                fclose(fp);
                goto A;
            }
            else if(strcmp(choicee,"1")==0)
            {
                strcpy(name4,name);
                strcat(name4,".txt");
                fp=fopen(name4,"a");
                y=0;
                while(y<=j-3)
                {
                    fprintf(fp,"%s %s %s %s %s\n",share[y],share[y+1],share[y+2],share[y+3],share[y+4]);
                    y=y+5;
                }
                fclose(fp);
            }
            else
            {
                printf("�����������������:");
                goto B;
            }
        }
        else
        {
            printf("�����������������:\a");
            goto B;
        }
        strcpy(name4,name);
        strcat(name4,"share.txt");
        fp=fopen(name4,"w");
        fclose(fp);
    }
A:
    system("CLS");
    int i=0,k=0,l=0;
    char password[16],name2[30],name3[30],data[500][40],ch;
    printf("                                          MaxͨѶ¼\n\n");
    printf("�û�:");
    printf("%s\n",name);
    printf("����:1.���� 2.��� 3.ɾ�� 4.���� 5.�鿴ȫ�� 6.���� 7.������Ϣ 8.����绰 0.ע��\n");
    strcat(name,".txt");
    fp=fopen(name,"r");
    fscanf(fp,"%s %s",name,password);
    strcpy(name2,name);
    strcpy(name3,name2);
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    printf("������Ҫ���еĲ���:");
C:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"0")!=0&&strcmp(choicee,"1")!=0&&strcmp(choicee,"2")!=0&&strcmp(choicee,"3")!=0&&strcmp(choicee,"4")!=0&&strcmp(choicee,"5")!=0&&strcmp(choicee,"6")!=0&&strcmp(choicee,"7")!=0&&strcmp(choicee,"8")!=0)
    {
        printf("�����������������:\a");
        goto  C;
    }
    while(strcmp(choicee,"0")!=0)
    {
        strcpy(name3,name2);
        switch(choicee[0])
        {
        case '1':
            chazhao(name3);
            if(pppp==1)
            {
                pppp=0;
                goto c;
            }
            printf("\n\n���������������һ��...");
            ch=getch();
            printf("%c",ch);
c:
            goto A;
            break;
        case '2':
            tianjia(name3);
            goto A;
            break;
        case '3':
            shanchu(name3);
            goto A;
            break;
        case '4':
            genggai(name3);
            goto A;
            break;
        case '5':
            chakan(name3);
            goto A;
            break;
        case '7':
            faxinxi(name3);
            goto A;
            break;
        case '8':
            dadianhua();
            goto A;
            break;
        case '6':
            fenxiang(name3);
            goto A;
            break;
        default:
            fflush(stdin);
            printf("�������,����������:\a");
        }
d:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"0")!=0&&strcmp(choicee,"1")!=0&&strcmp(choicee,"2")!=0&&strcmp(choicee,"3")!=0&&strcmp(choicee,"4")!=0&&strcmp(choicee,"5")!=0&&strcmp(choicee,"6")!=0&&strcmp(choicee,"7")!=0&&strcmp(choicee,"8")!=0)
        {
            printf("�����������������:");
            goto  d;
        }
    }
    if(strcmp(choicee,"0")==0)
    {
        strcpy(name3,name2);
        strcat(name3,".txt");
        fp=fopen(name3,"r");
        while(fscanf(fp,"%s",data[k++])!=EOF);
        fclose(fp);
        jiami(data[1]);
        fp=fopen(name3,"w");
        fprintf(fp,"%s %s\n",data[0],data[1]);
        for(l=2; l<=k-2; l=l+5) fprintf(fp,"%s %s %s %s %s\n",data[l],data[l+1],data[l+2],data[l+3],data[l+4]);
        fclose(fp);
        return 1;
    }
    return 0;
}
void signin()
{
    system("CLS");
    printf("                                          MaxͨѶ¼\n\n");
    FILE *fp;
    char a[2][16];
    int i=0,g,j=0;
    char name[80],name2[80],password[80],d[2][20],data[500][20];
    fp=fopen("001.txt","r");
    fscanf(fp,"%s%s",d[0],d[1]);
    fclose(fp);
    printf("��½\n����ͨѶ¼�û��˺�Ϊ001������Ϊ%s\n",jiemi(d[1]));
    printf("�û���:");
    scanf("%s",name);
    fflush(stdin);
    strcpy(name2,name);
    strcat(name,".txt");
    printf("\n  ����:");
    GetPassword(password);
    fflush(stdin);
    fp=fopen(name,"r");
    if(fp==NULL)
    {
        printf("�û������ڻ��������\a\n");
        g=denglujiemiancaidan();
        return;
    }
    else //�û�����ȷ����ʼ��֤����
    {
        fp=fopen(name,"r");
        while(fscanf(fp,"%s",a[i++])!=EOF)if(i==2) break;
        if(strcmp(jiemi(a[1]),password)==0)
        {
            fp=fopen(name,"r");
            while(fscanf(fp,"%s",data[j++])!=EOF);
            fclose(fp);
            jiemi(data[1]);
            fp=fopen(name,"w");
            fprintf(fp,"%s %s\n",data[0],data[1]);
            for(i=2; i<=j-2; i=i+5) fprintf(fp,"%s %s %s %s %s\n",data[i],data[i+1],data[i+2],data[i+3],data[i+4]);
            fclose(fp);
            system("CLS");
            printf("                                          MaxͨѶ¼\n\n");
            printf("\n\n\n\n\n\n\n\n\n\n                                   ���ڵ�¼,���Ե�");
            printf(".");
            Sleep(300);
            printf(".");
            Sleep(300);
            printf(".");
            Sleep(300);
        }
        else
        {
            printf("�û������ڻ��������\a\n");
            g=denglujiemiancaidan();
            if(g==3)
            {
                g=0;
                return;
            }
        }
    }
    yonghujiemian(name2);
    fflush(stdin);
    return;
}
int main()
{
    char choice[100];
    system("CLS");
    printf("                                          MaxͨѶ¼\n\n");
    printf("                                          1.��½ \n");
    printf("                                          2.ע�� \n");
    printf("                                          3.�������� \n");
    printf("                                          4.���� \n");
    printf("                                          5.�˳�ϵͳ \n");
    printf("��������Ҫ���еĲ���:");
d:
    scanf("%s",choice);
    fflush(stdin);
    if(strcmp(choice,"1")!=0&&strcmp(choice,"2")!=0&&strcmp(choice,"3")!=0&&strcmp(choice,"4")!=0&&strcmp(choice,"5")!=0)
    {
        printf("�����������������:\a");
        goto d;
    }
    while(strcmp(choice,"5")!=0)
    {
        switch(choice[0])
        {
        case '1':
            signin();
            break;
        case '2':
            zhuce ();
            break;
        case '3':
            gaimima();
            break;
        case '4':
            system("CLS");
            printf("\n\n\n\n\n\n\n\n\n                                          MaxͨѶ¼\n");
            printf("\n                                          �汾:v0.99\n");
            printf("\n                                          ��˾:microhard\n\n");
            system("pause");
            break;
        }
        system("CLS");
        printf("                                          MaxͨѶ¼\n\n");
        printf("                                          1.��½ \n");
        printf("                                          2.ע�� \n");
        printf("                                          3.�������� \n");
        printf("                                          4.���� \n");
        printf("                                          5.�˳�ϵͳ \n");
        printf("��������Ҫ���еĲ���:");
b:
        scanf("%s",choice);
        fflush(stdin);
        if(strcmp(choice,"1")!=0&&strcmp(choice,"2")!=0&&strcmp(choice,"3")!=0&&strcmp(choice,"4")!=0&&strcmp(choice,"5")!=0)
        {
            printf("�����������������:\a");
            goto b;
        }
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                         ��лʹ��\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}
