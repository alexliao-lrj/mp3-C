#include "menu.h"

void main(){
	//��������
	pcurrent = create();
	head = pcurrent;
	//�������ѡ��ť
	char mainButton = 'z';
	//��ʼ������
	initgraph(640, 480);
	//�������˵�
	main_Menu();
	//����main_click()�����������������ֽ���
	for(;is_run();delay_fps(60)){
		mainButton = main_Click();
		switch(mainButton){
		case '1':
			//���벥��������
			play_Menu(pcurrent,head);
			//mark(pcurrent);
			break;
		case '2':
			//���벥��ģʽ����
			mode_Menu(pcurrent);
			break;
		case '3':
			//���벥���б����
			list_Menu(pcurrent);
			break;
		case '4':
			//�˳�����
			exit(0);
		}
	}
	//�رս���
	closegraph();
}


