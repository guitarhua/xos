/*
 *  LCD1602�Ͳ�����
 *
 * 0x01; ����ʾ,��긴λ��00Hλ��.
 * 0X02;��0X03��긴λ��00Hλ��.
 * 0000 1 D C B;
 * 			(Ȼ��Ϊ16����,��0x0f��ʾ��˸�Ĺ��)D=1����ʾ,D=0����ʾ,C=1��ʾ���,C=0����ʾ���.B=1�����˸,B=0��겻��˸.
 * 0000 0 1 N S;
 * 			(Ȼ��Ϊ16����)N=1����дһ���ַ�ʱ��ַָ��͹�궼��һ.
 * 						N=0ʱ,����дһ���ַ����ַָ��͹�궼��һ.
 * 						S=1,��дһ���ַ�����������(N=1)������(N=0),�Եõ���겻��������Ļ�ڶ���Ч��.
 * 						S=0,дһ���ַ�����������.
 * 0x80+(0x00~0x27��һ�л�0x40~0x67�ڶ���),�������ݵ�ַָ��,��ÿ�е�һ�ַ������ϵ�λ��,
 * 						����0x90����һ�еĵ�һ���ַ��ڵ�һ�еĵ�ʮ��λ�ÿ�ʼд.
 * 0x18;��������һλ.
 * 0x1c;��������һλ
 * 0x10;�������һλ
 * 0x14;�������һλ.
 */
#ifndef _1602_H
#define _1602_H
/**/
#define OTHERS_BOARD
/**/
#ifndef OTHERS_BOARD
	#define L_data P0
	sbit rs=P3^0;
	sbit rw=P3^1;
	sbit en=P3^2;
#else
	#define L_data P2
	sbit rs=P1^2;
	sbit rw=P1^1;
	sbit en=P1^0;
#endif

#define LINE_0		0x80
#define LINE_1		0xc0

/** ָ��*/
#define CLEAR_SHOW 	0x01	//����ʾ,��긴λ��00Hλ��.
#define ENTER		0x02	//��ʾ�س�, ����ָ������

#define CMD_1		0x08
#define SHOW_BIT 	0x04	// ��ʾλ
#define CURSOR_BIT	0x02	// �����ʾλ
#define FLASH_BIT	0x01

#define CMD_2 		0x04
#define	POINT_BIT 	0x02	// ָ���
#define MOVE_DIR	0x01

#define CRYSTAL_1602 24
extern void init_1602();
//-------------------------------------------------------ָ��λ����ʾһ���ַ�
extern void prints(unsigned char x,unsigned char y,unsigned char *dat);
/***************************ָ��λ����ʾһ���ַ�************************************/
extern void printc(unsigned char x,unsigned char y,unsigned char dat);
#endif //1602_H