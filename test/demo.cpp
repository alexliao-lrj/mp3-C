#include "menu.h"

void main(){
	//创建链表
	pcurrent = create();
	head = pcurrent;
	//主界面的选择按钮
	char mainButton = 'z';
	//初始化界面
	initgraph(640, 480);
	//载入主菜单
	main_Menu();
	//调用main_click()函数根据鼠标点击进入分界面
	for(;is_run();delay_fps(60)){
		mainButton = main_Click();
		switch(mainButton){
		case '1':
			//载入播放器界面
			play_Menu(pcurrent,head);
			//mark(pcurrent);
			break;
		case '2':
			//载入播放模式界面
			mode_Menu(pcurrent);
			break;
		case '3':
			//载入播放列表界面
			list_Menu(pcurrent);
			break;
		case '4':
			//退出程序
			exit(0);
		}
	}
	//关闭界面
	closegraph();
}


