#include<Windows.h>

#ifndef BOARDTYPE_H_
#define BOARDTYPE_H_

/*ad
ad*/

/*	��������	*/
#define	BAN33	1		/*	��������									*/
#define	BAN44	2		/*	���Ľ���									*/
#define	BANLL	3		/*	��������									*/

/*���ͱ��	*/
#define L4L4	1		/*												*/
#define L4D4	2		/*												*/
#define L4L3	3		/*												*/
#define D4D4	4		/*												*/
#define	L4		5		/*												*/
#define	BAN5	6		/*	������										*/
#define	D4L3	7		/*												*/
#define	TL4L3	8		/*												*/
#define	TD4L3	9		/*												*/
#define	L3L3	10		/*												*/

/*���ͷ�ֵ*/
#define	MAXF	1000000	/*	������5��ʱ�������޴�ֵ						*/
#define L4L4F	750000	/*	8192 8184(����) 8176(˫��)	˫����			*/
#define L4D4F	700000	/*	6144 6140 6136 6132			��������		*/
#define L4L3F	650000	/*	4608 4600 4592				���Ļ���		*/
#define D4D4F	600000	/*	4096 4092 4088								*/
#define	L4F		550000	/*	4096										*/
#define	TL4L3F	500000	/*												*/
#define	D4L3F	450000	/*	2560 2552(����) 2556(����) 2548(��������)	*/
#define	TD4L3F	400000	/*												*/
#define	L3L3F	350000	/*	1024 1016(��������) 1008(˫������)			*/
#define BASEF	10		/*	�÷ֻ���									*/




/*����*/
#define BORDLEN 1		/*�߽���չ���									*/


/*���ֻ�ɫ*/
const int COLOR_RED		=		FOREGROUND_RED;
const int COLOR_BLUE	=		FOREGROUND_BLUE;
const int COLOR_GREEN	=		FOREGROUND_GREEN;


#endif 
