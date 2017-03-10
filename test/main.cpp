#include "menu.h"

void main_Menu()
{
	//界面上的各个按钮
	setcolor(EGERGB(255, 0, 0));
	circle(100,90,70);
	circle(100,240,70);
	circle(100,390,70);
	setfillcolor(EGERGB(0xFF, 0x0, 0x0));
	bar(540,430,640,480);
	setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
	bar(250,100,600,250);
	//为按钮添加相应文字
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "华文琥珀");
	outtextxy(58, 70, "播放器");
	outtextxy(42, 225, "播放模式");
	outtextxy(42, 375, "播放列表");
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "华文琥珀");
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "退出");
	setcolor(EGERGB(255, 0, 0));
	setfont(40, 0, "华文琥珀");
	setbkmode(TRANSPARENT);
	outtextxy(280, 160, "4104MP3播放器");	
}