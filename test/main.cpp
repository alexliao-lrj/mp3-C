#include "menu.h"

void main_Menu()
{
	//�����ϵĸ�����ť
	setcolor(EGERGB(255, 0, 0));
	circle(100,90,70);
	circle(100,240,70);
	circle(100,390,70);
	setfillcolor(EGERGB(0xFF, 0x0, 0x0));
	bar(540,430,640,480);
	setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
	bar(250,100,600,250);
	//Ϊ��ť�����Ӧ����
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "��������");
	outtextxy(58, 70, "������");
	outtextxy(42, 225, "����ģʽ");
	outtextxy(42, 375, "�����б�");
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "��������");
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "�˳�");
	setcolor(EGERGB(255, 0, 0));
	setfont(40, 0, "��������");
	setbkmode(TRANSPARENT);
	outtextxy(280, 160, "4104MP3������");	
}