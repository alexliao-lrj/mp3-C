#include "menu.h"

void mode_Menu(struct media* pcurrent)
{
	//����ģʽ��ѡ��ť
	char modeButton = 'z';
	//����ϲ���Ļ
	cleardevice();
	//�����ϵĸ�����ť
	setfillcolor(EGERGB(0xFF, 0xFF, 0xFF));
	bar(128,80,296,200);
	bar(344,80,512,200);
	bar(128,280,296,400);
	bar(344,280,512,400);
	setfillcolor(EGERGB(0xFF, 0, 0));
	bar(540,430,640,480);
	//Ϊ��ť�����Ӧ����
	setcolor(EGERGB(255, 0, 0));
	setbkmode(TRANSPARENT);
	setfont(30, 0, "��������");
	outtextxy(155, 125, "��������");
	outtextxy(372, 125, "�������");
	outtextxy(155, 325, "�б���");
	outtextxy(372, 325, "�б�ѭ��");
	setcolor(EGERGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "����");
	//����mode_click()����������������в�ͬ����
	for(;is_run();delay_fps(60)){
		char mp3[N];
		modeButton = mode_Click();
		switch(modeButton){
		case '1'://���ŵ���
			pcurrent = play_single(pcurrent);
			break;
		case '2'://�������
			pcurrent = play_random(pcurrent);
			break;
		case '3'://�б���
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
		case '4'://�б�ѭ������
			play_list_cyc(pcurrent);
			break;
		case 'a'://�����ϼ��˵�
			stop(pcurrent);
			cleardevice();
			main_Menu();
			return;	
		}
	}
}