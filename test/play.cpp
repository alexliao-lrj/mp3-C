#include "menu.h"


void play_Menu(struct media* pcurrent, struct media* head)
{
	//播放器的选择按钮
	char playButton = 'z';
	//错误定义
	MCIERROR mciError = NULL;
	char error[50];
	//清空上层屏幕
	cleardevice();
	//界面上的各个按钮
	setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
	bar(290,210,350,270);
	bar(290,130,350,190);
	bar(290,290,350,350);
	bar(370,210,430,270);
	bar(210,210,270,270);
	bar(450,210,540,270);
	bar(100,210,190,270);
	bar(50,50,140,110);
	bar(160,50,250,110);
	bar(0,430,100,480);
	setfillcolor(EGERGB(0xFF, 0x0, 0x0));
	bar(540,430,640,480);
	//为按钮添加相应文字
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "华文琥珀");
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "返回");
	setcolor(EGERGB(255, 0, 0));
	setfont(30, 0, "华文琥珀");
	setbkmode(TRANSPARENT);
	outtextxy(291, 225, "播放");
	outtextxy(371, 225, "快进");
	outtextxy(451, 225, "下一首");
	outtextxy(211, 225, "快退");
	outtextxy(101, 225, "上一首");
	outtextxy(291, 145, "暂停");
	outtextxy(291, 305, "停止");
	outtextxy(57, 65, "音量↑");
	outtextxy(167, 65, "音量↓");
	outtextxy(20, 440, "信息");
	//调用play_click()函数根据鼠标点击进行不同功能
	for(;is_run();delay_fps(60)){
		char* playOpen = play_open(pcurrent);
		char* playPlay = play_play(pcurrent);
		char* pauseStr = pause_str(pcurrent);
		char* playStop = play_stop(pcurrent);
		char* playClose = play_close(pcurrent);
		struct media* previous;
		playButton = play_Click();
		switch(playButton){
		case '1'://播放音乐
			if (pcurrent == NULL){
			//mention:printf("无音乐\n");
			}
			mciError = mciSendString(playOpen, NULL, 0, NULL);
			if (mciError){
				mciGetErrorString(mciError, error, strlen(error));
				//mention(error);
			}
			mciSendString(playPlay, NULL, 0, NULL);
			if (mciError){
				mciGetErrorString(mciError, error, strlen(error));
				//mention(error);
			}
			//mark(pcurrent);
			break;
		case '2'://暂停音乐
			mciError = mciSendString(pauseStr, NULL, 0, NULL);
			mciGetErrorString(mciError, error, strlen(error));
			if (mciError){
			//mention(error);
			}//Error handle	
			break;
		case '3'://停止音乐
			mciError = mciSendString(playStop, NULL, 0, NULL);
			if (mciError){
				//mention(error);
			}
			mciSendString(playClose, NULL, 0, NULL);
			break;
		case '4'://快进音乐
			fast_forward(pcurrent);//from here, 函数里可能会有很多bug, 可以先调上面... 
			break;
		case '5'://快退音乐
			fast_rewind(pcurrent);
			break;
		case '6'://播放下一首
			play_next(pcurrent);
			if(pcurrent->next == NULL){
				setcolor(EGERGB(255, 255, 255));
				setfont(30, 0, "宋体");
				outtextxy(0, 0, "没有更多了");
			}else{
				pcurrent=pcurrent->next;
			}
			break;
		case '7'://播放上一首
			previous = play_previous(pcurrent,head);
			pcurrent = previous;
			break;
		case '8'://增大音量
			volume_up(pcurrent);
			break;
		case '9'://减小音量
			volume_down(pcurrent);
			break;
		case 'b'://显示当前歌曲的信息
			cleardevice();
			display_info(pcurrent);
			break;
		case 'c':
			play_Menu(pcurrent, head);
			break;
		case 'a'://返回上级菜单
			stop(pcurrent);
			cleardevice();
			main_Menu();
			return;
		}
	}
}
