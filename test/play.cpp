#include "menu.h"


void play_Menu(struct media* pcurrent, struct media* head)
{
	//��������ѡ��ť
	char playButton = 'z';
	//������
	MCIERROR mciError = NULL;
	char error[50];
	//����ϲ���Ļ
	cleardevice();
	//�����ϵĸ�����ť
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
	//Ϊ��ť�����Ӧ����
	setcolor(EGERGB(255, 255, 255));
	setfont(30, 0, "��������");
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "����");
	setcolor(EGERGB(255, 0, 0));
	setfont(30, 0, "��������");
	setbkmode(TRANSPARENT);
	outtextxy(291, 225, "����");
	outtextxy(371, 225, "���");
	outtextxy(451, 225, "��һ��");
	outtextxy(211, 225, "����");
	outtextxy(101, 225, "��һ��");
	outtextxy(291, 145, "��ͣ");
	outtextxy(291, 305, "ֹͣ");
	outtextxy(57, 65, "������");
	outtextxy(167, 65, "������");
	outtextxy(20, 440, "��Ϣ");
	//����play_click()����������������в�ͬ����
	for(;is_run();delay_fps(60)){
		char* playOpen = play_open(pcurrent);
		char* playPlay = play_play(pcurrent);
		char* pauseStr = pause_str(pcurrent);
		char* playStop = play_stop(pcurrent);
		char* playClose = play_close(pcurrent);
		struct media* previous;
		playButton = play_Click();
		switch(playButton){
		case '1'://��������
			if (pcurrent == NULL){
			//mention:printf("������\n");
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
		case '2'://��ͣ����
			mciError = mciSendString(pauseStr, NULL, 0, NULL);
			mciGetErrorString(mciError, error, strlen(error));
			if (mciError){
			//mention(error);
			}//Error handle	
			break;
		case '3'://ֹͣ����
			mciError = mciSendString(playStop, NULL, 0, NULL);
			if (mciError){
				//mention(error);
			}
			mciSendString(playClose, NULL, 0, NULL);
			break;
		case '4'://�������
			fast_forward(pcurrent);//from here, ��������ܻ��кܶ�bug, �����ȵ�����... 
			break;
		case '5'://��������
			fast_rewind(pcurrent);
			break;
		case '6'://������һ��
			play_next(pcurrent);
			if(pcurrent->next == NULL){
				setcolor(EGERGB(255, 255, 255));
				setfont(30, 0, "����");
				outtextxy(0, 0, "û�и�����");
			}else{
				pcurrent=pcurrent->next;
			}
			break;
		case '7'://������һ��
			previous = play_previous(pcurrent,head);
			pcurrent = previous;
			break;
		case '8'://��������
			volume_up(pcurrent);
			break;
		case '9'://��С����
			volume_down(pcurrent);
			break;
		case 'b'://��ʾ��ǰ��������Ϣ
			cleardevice();
			display_info(pcurrent);
			break;
		case 'c':
			play_Menu(pcurrent, head);
			break;
		case 'a'://�����ϼ��˵�
			stop(pcurrent);
			cleardevice();
			main_Menu();
			return;
		}
	}
}
