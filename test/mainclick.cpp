#include "menu.h"

char main_Click(){
	//���������Ϣ
	mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
		//��ȡ�����Ϣ��getmouse()��ȴ���ֱ������ϢΪֹ
		while (mousemsg())
		{
			msg = getmouse();
		}
		//�����������ͬ��ť���򷵻���Ӧֵ��mainButton����switchѡ��ṹ
		if(msg.is_down())
		{
			if( (msg.x-100)*(msg.x-100) + (msg.y - 90)*(msg.y - 90) <= 4900 )
			{
				return '1';
			}
			if( (msg.x-100)*(msg.x-100) + (msg.y - 240)*(msg.y - 240) <= 4900 )
			{
				return '2';
			}
			if( (msg.x-100)*(msg.x-100) + (msg.y - 390)*(msg.y - 390) <= 4900 )
			{
				return '3';
			}
			if( msg.x >= 540 && msg.x <=640 && msg.y >= 430 && msg.y <=480 )
			{
				return '4';
			}
		}
	}
	return NULL;
}