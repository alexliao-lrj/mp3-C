/*预定义*/
#ifndef __MENU_H_
#define __MENU_H_

/*项目所用到的头文件*/
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "windows.h"
#pragma comment(lib,"WinMM.Lib")
#include "mmsystem.h"
#include "time.h"

/*相关宏定义*/
#define N 100
#define M 50
#define O 20
static char filepath[N];
static int count = 0;
static struct media{
	char path[N];
	char name[M];
	char author[O];
	struct media *next;
};
static struct media *head = NULL;
static struct media *p1, *p2, *pcurrent = head;
typedef struct media Song; 

/*
Author:来旖
Date:2015.7.18
Description:界面构建相关函数
*/
void main_Menu();
void play_Menu(struct media* pcurrent, struct media* head);
void list_Menu(struct media* pcurrent);
void mode_Menu(struct media* pcurrent);
char main_Click();
char play_Click();
char list_Click();
char mode_Click();

/*
Author:赵明
Date:2015.7.18
Description:LOG模块相关函数
*/
void input_msg(struct media *pcurrent);										//记录用户播放信息
void output_msg(struct media *pcurrent);									//输出用户播放信息
void input_error(char *error);												//记录错误信息
/*void hotkey();*/

/*
Author:黄方圆
Date:2015.7.18
Description:错误处理相关函数
*/
void mention(char *error);													//错误提示
void output_error(char *error);												//输出错误信息

/*
Author:夏培萱
Date:2015.7.18
Description:文件流和数据处理相关函数
*/
int deletes(char* path);													//从用户歌曲中删除歌曲
int add(char *path);														//从用户歌曲中添加歌曲
Song* create();																//创建链表(播放列表)
int mark(Song *p);															//记录当前播放歌曲地址
void display_allinfo(struct media* pcurrent);								//播放列表中显示所有歌曲的信息


/*
Author:廖若佳
Date:2015.7.18
Description:动作控制相关函数
*/
long musiclen(struct media* pcurrent);										//return file length返回文件长度
int list_len(struct media *head);											//返回链表长度（播放列表长度）
void display_info(struct media* pcurrent);									//播放器中显示单首歌信息
struct media* search_music(struct media* pcurrent);							//查询音乐
int play(struct media* pcurrent);											//播放音乐 成功返1，否则返0
void stop(struct media* pcurrent);											//停止音乐
void pause(struct media* pcurrent);											//暂停音乐
char* play_open(struct media* pcurrent);
char* play_play(struct media* pcurrent);
char* play_stop(struct media* pcurrent);
char* play_close(struct media* pcurrent);
char* pause_str(struct media* pcurrent);
void play_next(struct media* pcurrent);										//播放下一首
struct media* play_previous(struct media* pcurrent, struct media* head);	//播放上一首
void fast_forward(struct media* pcurrent);									//音乐快进
void fast_rewind(struct media* pcurrent);									//音乐快退
void volume_up(struct media* pcurrent);										//音量增加
void volume_down(struct media* pcurrent);									//音量减少
char* rewind_status(struct media* pcurrent);
char* rewind_seek(struct media* pcurrent);
char* vol_set(struct media* pcurrent);
char* vol_status(struct media* pcurrent);
void show_list();															//显示列表信息
struct media* check_music(struct media* pcurrent);
struct media* play_single(struct media* pcurrent);							//单曲播放
void play_list(struct media* pcurrent);										//列表顺序
void play_single_cyc(struct media* pcurrent);								//single music cycle单曲循环
void play_list_cyc(struct media* pcurrent);									//list cycle play列表循环
struct media* play_random(struct media* pcurrent);							//random play随机

#endif