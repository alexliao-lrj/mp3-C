#include "menu.h"

char play_Click(){
	//定义鼠标信息
	mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
		//获取鼠标消息，getmouse()会等待，直到有消息为止
		while (mousemsg())
		{
			msg = getmouse();
		}
		//根据鼠标点击不同按钮区域返回相应值给playButton进入switch选择结构
		if(msg.is_down())
		{
			if( msg.x >= 290 && msg.x <=350 && msg.y >= 210 && msg.y <=270)
			{
				return '1';
			}
			if( msg.x >= 290 && msg.x <=350 && msg.y >= 130 && msg.y <=190)
			{
				return '2';
			}
			if( msg.x >= 290 && msg.x <=350 && msg.y >= 290 && msg.y <=350)
			{
				return '3';
			}
			if( msg.x >= 370 && msg.x <=430 && msg.y >= 210 && msg.y <=270)
			{
				return '4';
			}
			if( msg.x >= 210 && msg.x <=270 && msg.y >= 210 && msg.y <=270)
			{
				return '5';
			}
			if( msg.x >= 450 && msg.x <=540 && msg.y >= 210 && msg.y <=270)
			{
				return '6';
			}
			if( msg.x >= 100 && msg.x <=190 && msg.y >= 210 && msg.y <=270)
			{
				return '7';
			}
			if( msg.x >= 50 && msg.x <=140 && msg.y >= 50 && msg.y <=110)
			{
				return '8';
			}
			if( msg.x >= 160 && msg.x <=250 && msg.y >= 50 && msg.y <=110)
			{
				return '9';
			}
			if( msg.x >= 0 && msg.x <=100 && msg.y >= 430 && msg.y <=480)
			{
				return 'b';
			}
			if( msg.x >= 120 && msg.x <=220 && msg.y >= 430 && msg.y <=480)
			{
				return 'c';
			}
			if( msg.x >= 540 && msg.x <=640 && msg.y >= 430 && msg.y <=480)
			{
				return 'a';
			}	
		}
	}
	return NULL;
}