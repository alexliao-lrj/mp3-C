#include "menu.h"

void list_Menu(struct media* pcurrent)
{
	//�����б��ѡ��ť
	char listButton = 'z';
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
	setfillcolor(EGERGB(0, 0, 0));
	bar(0,430,100,480);
	//Ϊ��ť�����Ӧ����
	setcolor(EGERGB(255, 0, 0));
	setbkmode(TRANSPARENT);
	setfont(30, 0, "��������");		
	outtextxy(155, 125, "��ʾ����");
	outtextxy(372, 125, "��ѯ����");
	outtextxy(155, 325, "��Ӹ���");		
	outtextxy(372, 325, "ɾ������");
	setcolor(EGERGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	outtextxy(560, 440, "����");
	//����list_click()����������������в�ͬ����
	for(;is_run();delay_fps(60)){
		char* path = (char*)malloc(sizeof(char)*N);
		int i = 0;
		listButton = list_Click();
		switch(listButton){
		case '1'://��ʾ������Ϣ
			cleardevice();
			display_allinfo(pcurrent);		
			break;
		case '2'://��ѯ�����Ƿ����б���
			check_music(pcurrent);
			break;
		case '3'://���б�����Ӹ���
			inputbox_getline("������Ҫ��ӵĸ�����·��", "�س�ȷ��", path, N);
			mark(pcurrent);
			i = add(path);
			if(i==2){
				char* error = "�Ҳ��������ļ���\n";
				//mention(error);
			}else if(i==0){
				char* error = "�ļ���ʧ�ܣ�\n";
				//mention(error);
			}
			head = create();
			pcurrent = head;
			break;
		case '4'://ɾ�����б��еĸ���
			inputbox_getline("������Ҫɾ���ĸ�����·��", "�س�ȷ��", path, N);
			mark(pcurrent);
			i = deletes(path);
			if(i==2){
				char* error = "�Ҳ��������ļ���\n";
				//mention(error);
			}else if(i==0){
				char* error = "�ļ���ʧ�ܣ�\n";
				//mention(error);
			}
			head = create();
			pcurrent = head;
			break;
		case 'c':
			list_Menu(pcurrent);
			break;
		case 'a'://�����ϼ��˵�
			stop(pcurrent);
			cleardevice();
			main_Menu();
			return;	
		}
	}	
}