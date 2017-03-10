#include "menu.h"

void mode_Menu(struct media* pcurrent)
{
	//播放模式的选择按钮
	char modeButton = 'z';
	//清空上层屏幕
	cleardevice();
	//界面上的各个按钮
	setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
	bar(128,80,296,200);
	bar(344,80,512,200);
	bar(128,280,296,400);
	bar(344,280,512,400);
	setfillcolor(EGERGB(0xFF, 0, 0));
	bar(540,430,640,480);
	//为按钮添加相应文字
	setcolor(EGERGB(255, 0, 0));
	setbkmode(TRANSPARENT);
	setfont(30, 0, "华文琥珀");
	outtextxy(155, 125, "单曲播放");
	outtextxy(372, 125, "随机播放");
	outtextxy(155, 325, "列表播放");
	outtextxy(372, 325, "列表循环");
	setcolor(EGERGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "返回");
	//调用mode_click()函数根据鼠标点击进行不同功能
	for(;is_run();delay_fps(60)){
		char mp3[N];
		modeButton = mode_Click();
		switch(modeButton){
		case '1'://播放单曲
			pcurrent = play_single(pcurrent);
			break;
		case '2'://随机播放
			pcurrent = play_random(pcurrent);
			break;
		case '3'://列表播放
			pcurrent = create();
			play(pcurrent);
			while(pcurrent->next != NULL){
				strcpy(mp3,"");
				strcpy(mp3, "play ");
				strcat(mp3, pcurrent->path);
				strcat(mp3," wait");
				mciSendString(mp3,NULL,0,NULL);
				pcurrent = pcurrent->next;
			}
			break;
		case '4'://列表循环播放
			play_list_cyc(pcurrent);
			break;
		case 'a'://返回上级菜单
			stop(pcurrent);
			cleardevice();
			main_Menu();
			return;	
		}
	}
}