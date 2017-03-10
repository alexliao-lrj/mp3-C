#include "menu.h"

void list_Menu(struct media* pcurrent)
{
	//播放列表的选择按钮
	char listButton = 'z';
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
	setfillcolor(EGERGB(0, 0, 0));
	bar(0,430,100,480);
	//为按钮添加相应文字
	setcolor(EGERGB(255, 0, 0));
	setbkmode(TRANSPARENT);
	setfont(30, 0, "华文琥珀");		
	outtextxy(155, 125, "显示歌曲");
	outtextxy(372, 125, "查询歌曲");
	outtextxy(155, 325, "添加歌曲");		
	outtextxy(372, 325, "删除歌曲");
	setcolor(EGERGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "返回");
	//调用list_click()函数根据鼠标点击进行不同功能
	for(;is_run();delay_fps(60)){
		char* path = (char*)malloc(sizeof(char)*N);
		int i = 0;
		listButton = list_Click();
		switch(listButton){
		case '1'://显示所有信息
			cleardevice();
			display_allinfo(pcurrent);		
			break;
		case '2'://查询歌曲是否在列表中
			check_music(pcurrent);
			break;
		case '3'://往列表中添加歌曲
			inputbox_getline("请输入要添加的歌曲的路径", "回车确认", path, N);
			mark(pcurrent);
			i = add(path);
			if(i==2){
				char* error = "找不到音乐文件！\n";
				//mention(error);
			}else if(i==0){
				char* error = "文件打开失败！\n";
				//mention(error);
			}
			head = create();
			pcurrent = head;
			break;
		case '4'://删除在列表中的歌曲
			inputbox_getline("请输入要删除的歌曲的路径", "回车确认", path, N);
			mark(pcurrent);
			i = deletes(path);
			if(i==2){
				char* error = "找不到音乐文件！\n";
				//mention(error);
			}else if(i==0){
				char* error = "文件打开失败！\n";
				//mention(error);
			}
			head = create();
			pcurrent = head;
			break;
		case 'c':
			list_Menu(pcurrent);
			break;
		case 'a'://返回上级菜单
			stop(pcurrent);
			cleardevice();
			main_Menu();
			return;	
		}
	}	
}