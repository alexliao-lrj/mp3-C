#include "menu.h"

char mode_Click(){
	//���������Ϣ
	mouse_msg msg = {0};

	for ( ; is_run(); delay_fps(60))
	{
		//��ȡ�����Ϣ��getmouse()��ȴ���ֱ������ϢΪֹ
		while (mousemsg())
		{
			msg = getmouse();
		}
		//�����������ͬ��ť���򷵻���Ӧֵ��modeButton����switchѡ��ṹ
		if(msg.is_down())
		{
			if( msg.x >= 128 && msg.x <=296 && msg.y >= 80 && msg.y <=200)
			{
				return '1';
			}
			if( msg.x >= 344 && msg.x <=512 && msg.y >= 80 && msg.y <=200)
			{
				return '2';
			}
			if( msg.x >= 128 && msg.x <=296 && msg.y >= 280 && msg.y <=400)
			{
				return '3';
			}
			if( msg.x >= 344 && msg.x <=512 && msg.y >= 280 && msg.y <=400)
			{
				return '4';
			}
			if( msg.x >= 540 && msg.x <=640 && msg.y >= 430 && msg.y <=480)
			{
				return 'a';
			}
		}
	}
	return NULL;
}